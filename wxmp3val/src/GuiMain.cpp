/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiMain.h"
#include "GuiSettings.h"
#include "Constants.h"

#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

GuiMain::GuiMain(wxWindow* parent)
: Main(parent), m_processRunning(false) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_fileListManager = new FileListManager(g_lstFiles);

    // List Drag & Drop
    mp_dndFile = new DndFile(mp_fileListManager);
    g_lstFiles->SetDropTarget(mp_dndFile);

    // Title List
    g_lstFiles->InsertColumn(ID_LIST_FILE, _("File"), wxLIST_FORMAT_LEFT, 200);
    g_lstFiles->InsertColumn(ID_LIST_FOLDER, _("Folder"), wxLIST_FORMAT_LEFT, 200);
    g_lstFiles->InsertColumn(ID_LIST_VERSION, _("Version"), wxLIST_FORMAT_LEFT, 100);
    g_lstFiles->InsertColumn(ID_LIST_TAGS, _("Tags"), wxLIST_FORMAT_LEFT, 100);
    g_lstFiles->InsertColumn(ID_LIST_CBR, _("CBR"), wxLIST_FORMAT_LEFT, 70);
    g_lstFiles->InsertColumn(ID_LIST_STATE, _("State"), wxLIST_FORMAT_LEFT, 70);

    // Set statusbar widths
    const int wxStatusBarWidths [3] = {-10, -10, -5};
    g_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();
}

GuiMain::~GuiMain() {
    delete mp_fileListManager;
    delete mp_configBase;
}

void GuiMain::OnlstFilesDeleteItem(wxListEvent& event) {
    if (!m_processRunning) {
        mp_fileListManager->deleteItem(event.GetIndex());
        updateControls();
    }
    event.Skip();
}

void GuiMain::OnlstFilesInsertItem(wxListEvent& event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiMain::OnlstFilesItemSelect(wxListEvent& event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiMain::OnlstFilesItemRClick(wxListEvent& event) {
    if (!m_processRunning) {
        updateControls();
        // Displays the popup menu when you click a list item
        g_lstFiles->PopupMenu(g_mainMenu);
    }
    event.Skip();
}

void GuiMain::OnlstFilesKeyDown(wxListEvent& event) {
    if (!m_processRunning) {
        // Remove files with Delete key
        int keyCode = event.GetKeyCode();
        if (keyCode == WXK_DELETE)
            mnuRemoveFiles(event);
    }
    event.Skip();
}

void GuiMain::btnProcessStop(wxCommandEvent& event) {
    m_processRunning = false;
    g_btnStop->Enable(false);
}

void GuiMain::mnuAddDirectory(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_configBase->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_fileListManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuAddFiles(wxCommandEvent& event) {
    wxArrayString files;
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_configBase->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_fileListManager->insertFiles(files);

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void GuiMain::mnuExit(wxCommandEvent& event) {
    // Terminates the program
    Close();
}

void GuiMain::mnuRemoveFiles(wxCommandEvent& event) {
    int itemCount = g_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++)
        g_lstFiles->DeleteItem(g_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    SetCursor(wxCURSOR_ARROW);

    updateControls();
}

void GuiMain::mnuClearList(wxCommandEvent& event) {
    // Deletes all items from the list
    mp_fileListManager->clear();

    updateControls();
}

void GuiMain::mnuSettings(wxCommandEvent& event) {
    // Displays the "Settings" window
    GuiSettings guiSettings(this, mp_configBase);
    guiSettings.ShowModal();

    updateControls();
}

void GuiMain::mnuScan(wxCommandEvent& event) {
    m_processType = TOOL_SCAN;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
}

void GuiMain::mnuRepair(wxCommandEvent& event) {
    m_processType = TOOL_FIX;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
}

void GuiMain::mnuToolWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(_T("http://mp3val.sourceforge.net/"));
}

void GuiMain::mnuWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void GuiMain::mnuAbout(wxCommandEvent& event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the MP3val"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    wxAboutBox(aboutInfo);
}

void GuiMain::OnTimer1Trigger(wxTimerEvent& event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        if (!m_exeInputString.IsEmpty())
            g_mainStatusBar->SetStatusText(_("Using MP3val version: ") + m_exeInputString.Item(0).AfterLast(' '), 0);
        else
            g_mainStatusBar->SetStatusText(_("MP3val not found!"), 0);
    }

    // Show the number of files in list on status bar
    g_mainStatusBar->SetStatusText(wxString::Format(_T("%i "), g_lstFiles->GetItemCount()) + _("files"), 1);

    for (size_t i = 0; i < g_mainMenuBar->GetMenuCount(); i++)
        g_mainMenuBar->EnableTop(i, !m_processRunning);

    g_mainToolBar->Enable(!m_processRunning);

    g_mainMenu->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    g_mainMenuBar->Enable(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    g_mainToolBar->EnableTool(ID_REMOVE_FILES, g_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);

    g_mainMenu->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0 && !m_processRunning);
    g_mainMenuBar->Enable(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0 && !m_processRunning);
    g_mainToolBar->EnableTool(ID_CLEAR_LIST, g_lstFiles->GetItemCount() > 0 && !m_processRunning);

    g_mainMenuBar->Enable(ID_SCAN, g_lstFiles->GetItemCount() > 0 && !m_processRunning);
    g_mainToolBar->EnableTool(ID_SCAN, g_lstFiles->GetItemCount() > 0 && !m_processRunning);

    g_mainMenuBar->Enable(ID_REPAIR, g_lstFiles->GetItemCount() > 0 && !m_processRunning);
    g_mainToolBar->EnableTool(ID_REPAIR, g_lstFiles->GetItemCount() > 0 && !m_processRunning);

    g_btnStop->Enable(m_processRunning);
}

void GuiMain::loadResources() {
    wxString resourceDir = GetResourceDir();

    // Window icon
    wxIcon frameIcon;
    frameIcon.CopyFromBitmap(wxBitmap(wxImage(resourceDir + _T("icon-frame.ico"))));
    SetIcon(frameIcon);

    // Toolbar bitmaps
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/add-file.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(resourceDir + _T("toolbar/add-folder.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(resourceDir + _T("toolbar/remove.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(resourceDir + _T("toolbar/clear.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_SCAN, wxBitmap(wxImage(resourceDir + _T("toolbar/scan.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_REPAIR, wxBitmap(wxImage(resourceDir + _T("toolbar/fix.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(resourceDir + _T("toolbar/settings.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(resourceDir + _T("toolbar/about.png"))));
}

void GuiMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiMain::setFilesCmdLine(const wxArrayString& filenames) {
    mp_fileListManager->insertFilesAndDir(filenames);
}

void GuiMain::processExecute() {
    unsigned long int maxValue = mp_fileListManager->size();
    unsigned long int i;

    g_gugProgress->SetRange((int) maxValue);
    for (i = 0; i < maxValue; i++) {
        processFile(i);
        g_gugProgress->SetValue((int) i + 1);

        if (!m_processRunning) {
            if (wxMessageBox(_("Do you want to stop process now?"), APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES) {
                i++;
                break;
            }
            m_processRunning = true;
            g_btnStop->Enable(true);
        }
    }
    wxMessageBox(wxString::Format(_("Processed %lu files of %lu."), i, maxValue), APP_NAME, wxOK | wxICON_INFORMATION);
    g_gugProgress->SetValue(0);
}

void GuiMain::processFile(unsigned long int fileIterator) {
    wxString fullCommand = APP_TOOL_EXECUTABLE;
    FileInfo& fileInfo = mp_fileListManager->getItem(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    // Do not process OK MP3's again
    if (fileInfo.getStateMP3() == STATE_MP3_OK)
        return;

    if (m_processType == TOOL_FIX)
        fullCommand.append(_T(" -f ") + mp_configBase->getStringToolOptions());

    // Execute external application
    wxExecute(fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\""), m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);

    // Process output string and updates the list
    int stateMP3 = processOutputString(fileIterator);
    fileInfo.setStateMP3(stateMP3);

    g_mainStatusBar->SetStatusText(wxString::Format(_("Processed %lu files of %lu."), fileIterator + 1, mp_fileListManager->size()), 1);
}

int GuiMain::processOutputString(unsigned long int fileIterator) {
    wxString tempString;
    int stateMP3 = STATE_MP3_OK;
    int warningCount = 0;

    if (!m_exeInputString.IsEmpty()) {
        for (unsigned long int i = 0; i < m_exeInputString.GetCount(); i++) {
            tempString = m_exeInputString.Item(i);

            if (tempString.Find(_T("MPEG frames")) != wxNOT_FOUND) {
                // Cut the string for: "MPEG frames..."
                tempString = tempString.Right(tempString.Len() - tempString.Find(_T("MPEG frames")));

                // Update Version column
                if (tempString.AfterFirst('(').BeforeFirst(')').Find(_T("MPEG")) != wxNOT_FOUND)
                    mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_VERSION, tempString.AfterFirst('(').BeforeFirst(')'));

                // Update Tags column
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_TAGS, tempString.AfterFirst(',').BeforeFirst(','));

                // Update CBR column
                if (tempString.AfterFirst(',').AfterFirst(',').Find(_T("CBR")) != wxNOT_FOUND)
                    mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_CBR, _T("CBR"));
                else
                    mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_CBR, _T("VBR"));
            }

            if (tempString.StartsWith(_T("WARNING: ")))
                warningCount++;

            if (tempString.Find(_T("tags in the file")) != wxNOT_FOUND)
                warningCount--;

            if (tempString.StartsWith(_T("FIXED: ")))
                stateMP3 = STATE_MP3_FIXED;
        }

        if (stateMP3 == STATE_MP3_OK && warningCount > 0)
            stateMP3 = STATE_MP3_PROBLEM;

        // Update State column
        switch (stateMP3) {
            case STATE_MP3_OK:
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_STATE, _("OK"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxBLACK);
                break;
            case STATE_MP3_PROBLEM:
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_STATE, _("PROBLEM"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxRED);
                break;
            case STATE_MP3_FIXED:
                mp_fileListManager->getOwner().SetItem(fileIterator, ID_LIST_STATE, _("FIXED"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxBLACK);
                break;
        }

        // Clear the output
        m_exeInputString.Clear();
    }
    return stateMP3;
}
