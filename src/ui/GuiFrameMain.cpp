/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiFrameMain.hpp"
#include "../Constants.hpp"
#include "GuiDialogSettings.hpp"

#include <wx/aboutdlg.h>
#include <wx/dirdlg.h>
#include <wx/filedlg.h>
#include <wx/filefn.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>

GuiFrameMain::GuiFrameMain(wxWindow *parent) : FrameMain(parent), m_processRunning(false) {
    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // File list manager
    mp_listManager = new ListManager(gui_lstFiles);

    // List Drag & Drop
    mp_fileDrop = new FileDrop(mp_listManager);
    gui_lstFiles->SetDropTarget(mp_fileDrop);

    // Title List
    gui_lstFiles->InsertColumn(ID_LIST_FILE, _("File"), wxLIST_FORMAT_LEFT, 200);
    gui_lstFiles->InsertColumn(ID_LIST_FOLDER, _("Folder"), wxLIST_FORMAT_LEFT, 200);
    gui_lstFiles->InsertColumn(ID_LIST_VERSION, _("Version"), wxLIST_FORMAT_LEFT, 100);
    gui_lstFiles->InsertColumn(ID_LIST_TAGS, _("Tags"), wxLIST_FORMAT_LEFT, 100);
    gui_lstFiles->InsertColumn(ID_LIST_CBR, _("CBR"), wxLIST_FORMAT_LEFT, 70);
    gui_lstFiles->InsertColumn(ID_LIST_STATE, _("State"), wxLIST_FORMAT_LEFT, 70);

    // Set statusbar widths
    const int wxStatusBarWidths[3] = {-10, -10, -5};
    gui_mainStatusBar->SetStatusWidths(3, wxStatusBarWidths);

    // Configuration file
    mp_appSettings = new AppSettings(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Updates the controls
    updateControls();
}

GuiFrameMain::~GuiFrameMain() {
    delete mp_listManager;
    delete mp_appSettings;
}

void GuiFrameMain::OnlstFilesDeleteItem(wxListEvent &event) {
    if (!m_processRunning) {
        mp_listManager->deleteItem((unsigned long)event.GetIndex());
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesInsertItem(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemSelect(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesItemRClick(wxListEvent &event) {
    if (!m_processRunning) {
        updateControls();
        // Displays the popup menu when you click a list item
        gui_lstFiles->PopupMenu(gui_menu);
    }
    event.Skip();
}

void GuiFrameMain::OnlstFilesKeyDown(wxListEvent &event) {
    if (!m_processRunning) {
        // Remove files with Delete key
        int keyCode = event.GetKeyCode();
        if (keyCode == WXK_DELETE)
            mnuRemoveFiles(event);
    }
    event.Skip();
}

void GuiFrameMain::btnProcessStop(wxCommandEvent &event) {
    m_processRunning = false;
    gui_btnStop->Enable(false);
    event.Skip(false);
}

void GuiFrameMain::mnuAddDirectory(wxCommandEvent &event) {
    wxString msg = _("Select directory");
    wxDirDialog dirDialog(this, msg, wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_appSettings->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_listManager->insertDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuAddFiles(wxCommandEvent &event) {
    wxArrayString files;
    wxString msg = _("Select file");
    wxFileDialog fileDialog(this, msg, wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_appSettings->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_listManager->insertFiles(files);

        // Remembers the last used directory
        mp_appSettings->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
    event.Skip(false);
}

void GuiFrameMain::mnuExit(wxCommandEvent &event) {
    // Terminates the program
    Close();
    event.Skip(false);
}

void GuiFrameMain::mnuRemoveFiles(wxCommandEvent &event) {
    int itemCount = gui_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++) {
        long item = gui_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        gui_lstFiles->DeleteItem(item);
    }
    SetCursor(wxCURSOR_ARROW);

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuClearList(wxCommandEvent &event) {
    // Deletes all items from the list
    mp_listManager->clear();

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuSettings(wxCommandEvent &event) {
    // Displays the "Settings" window
    GuiDialogSettings guiSettings(this, mp_appSettings);
    guiSettings.ShowModal();

    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuScan(wxCommandEvent &event) {
    m_processType = TOOL_SCAN;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuRepair(wxCommandEvent &event) {
    m_processType = TOOL_FIX;
    m_processRunning = true;
    updateControls();
    processExecute();
    m_processRunning = false;
    updateControls();
    event.Skip(false);
}

void GuiFrameMain::mnuToolWebsite(wxCommandEvent &event) {
    wxLaunchDefaultBrowser(_T("http://mp3val.sourceforge.net/"));
    event.Skip(false);
}

void GuiFrameMain::mnuWebsite(wxCommandEvent &event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
    event.Skip(false);
}

void GuiFrameMain::mnuAbout(wxCommandEvent &event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the MP3val"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    wxString dataDir = getDataDir();
    aboutInfo.SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));
    wxAboutBox(aboutInfo);
    event.Skip(false);
}

void GuiFrameMain::OnTimer1Trigger(wxTimerEvent &event) {
    wxString newExeTool = APP_TOOL_EXECUTABLE;
    if (!m_exeTool.IsSameAs(newExeTool, false)) {
        m_exeInputString.Clear();
        m_exeInputErrorString.Clear();
        m_exeTool = newExeTool;
        // Execute external application
        wxExecute(m_exeTool + _T(" -v"), m_exeInputString, m_exeInputErrorString, wxEXEC_NODISABLE);

        // Show the version of tool
        wxString version;
        if (!m_exeInputString.IsEmpty()) {
            version = _("Using MP3val version: ");
            version += m_exeInputString.Item(0).AfterLast(' ');
        } else {
            version = _("MP3val not found!");
        }
        gui_mainStatusBar->SetStatusText(version, 0);
    }

    // Show the number of files in list on status bar
    wxString strNFiles;
    strNFiles += wxString::Format(_T("%i "), gui_lstFiles->GetItemCount());
    strNFiles += _("files");
    gui_mainStatusBar->SetStatusText(strNFiles, 1);

    for (size_t i = 0; i < gui_menuBar->GetMenuCount(); i++)
        gui_menuBar->EnableTop(i, !m_processRunning);

    gui_toolBar->Enable(!m_processRunning);

    gui_menu->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    gui_menuBar->Enable(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);
    gui_toolBar->EnableTool(ID_REMOVE_FILES, gui_lstFiles->GetSelectedItemCount() > 0 && !m_processRunning);

    gui_menu->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_menuBar->Enable(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_toolBar->EnableTool(ID_CLEAR_LIST, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_menuBar->Enable(ID_SCAN, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_toolBar->EnableTool(ID_SCAN, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_menuBar->Enable(ID_REPAIR, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);
    gui_toolBar->EnableTool(ID_REPAIR, gui_lstFiles->GetItemCount() > 0 && !m_processRunning);

    gui_btnStop->Enable(m_processRunning);
    event.Skip(false);
}

void GuiFrameMain::loadResources() {
    wxString dataDir = getDataDir();

    // Window icon
    SetIcon(wxIcon(dataDir + _T("icons/app.ico"), wxBITMAP_TYPE_ICO));

    // Toolbar bitmaps
    gui_toolBar->SetToolNormalBitmap(ID_ADD_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/add-file.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_ADD_FOLDER, wxBitmap(wxImage(dataDir + _T("toolbar/add-folder.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_REMOVE_FILES, wxBitmap(wxImage(dataDir + _T("toolbar/remove.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_CLEAR_LIST, wxBitmap(wxImage(dataDir + _T("toolbar/clear.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_SCAN, wxBitmap(wxImage(dataDir + _T("toolbar/scan.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_REPAIR, wxBitmap(wxImage(dataDir + _T("toolbar/fix.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_SETTINGS, wxBitmap(wxImage(dataDir + _T("toolbar/settings.png"))));
    gui_toolBar->SetToolNormalBitmap(ID_ABOUT, wxBitmap(wxImage(dataDir + _T("toolbar/about.png"))));
}

void GuiFrameMain::updateControls() {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    m_timer1.Start(20, true);
}

void GuiFrameMain::setFilesCmdLine(const wxArrayString &filenames) {
    mp_listManager->insertFilesAndDir(filenames);
}

void GuiFrameMain::processExecute() {
    unsigned long int total = mp_listManager->size();
    unsigned long int fileIdx;
    wxString msg;

    gui_gugProgress->SetRange((int)total);
    for (fileIdx = 0; fileIdx < total; fileIdx++) {
        processFile(fileIdx);
        gui_gugProgress->SetValue((int)fileIdx + 1);

        if (!m_processRunning) {
            msg = _("Do you want to stop process now?");
            if (wxMessageBox(msg, APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES) {
                fileIdx++;
                break;
            }
            m_processRunning = true;
            gui_btnStop->Enable(true);
        }
    }

    msg = wxString::Format(_("Processed %lu files of %lu."), fileIdx, total);
    wxMessageBox(msg, APP_NAME, wxOK | wxICON_INFORMATION);

    gui_gugProgress->SetValue(0);
}

void GuiFrameMain::processFile(unsigned long int fileIterator) {
    wxString fullCommand = APP_TOOL_EXECUTABLE;
    FileData &fileData = mp_listManager->getFileData(fileIterator);
    wxFileName filenameInput = fileData.getFileName();

    // Do not process OK MP3's again
    if (fileData.getStateMP3() == STATE_MP3_OK)
        return;

    // Works on a temp file
    wxString filenameTemp = wxFileName::CreateTempFileName(_T("temp-")) + _T(".mp3");
    wxCopyFile(filenameInput.GetFullPath(), filenameTemp, true);

    if (m_processType == TOOL_FIX)
        fullCommand.append(_T(" -f ") + mp_appSettings->getStringToolOptions());

    // Execute external application
    wxExecute(fullCommand + _T(" \"") + filenameTemp + _T("\""), m_exeInputString, wxEXEC_NODISABLE | wxEXEC_SYNC);

    // Process output string and updates the list
    int stateMP3 = processOutputString(fileIterator);
    fileData.setStateMP3(stateMP3);

    // Delete temp file or rename to the original filename
    if (m_processType == TOOL_SCAN)
        wxRemoveFile(filenameTemp);
    else {
        wxRenameFile(filenameTemp, filenameInput.GetFullPath(), true);
        // Rename backup file
        wxString filenameTempBak = filenameTemp + _T(".bak");
        if (wxFileExists(filenameTempBak))
            wxRenameFile(filenameTempBak, filenameInput.GetFullPath() + _T(".bak"), true);
    }

    gui_mainStatusBar->SetStatusText(wxString::Format(_("Processed %lu files of %lu."), fileIterator + 1, mp_listManager->size()), 1);
}

int GuiFrameMain::processOutputString(unsigned long int fileIterator) {
    wxString tempString;
    int stateMP3 = STATE_MP3_OK;
    int warningCount = 0;

    if (!m_exeInputString.IsEmpty()) {
        for (unsigned long int i = 0; i < m_exeInputString.GetCount(); i++) {
            tempString = m_exeInputString.Item(i);

            if (tempString.Find(_T("MPEG frames")) != wxNOT_FOUND) {
                // Cut the string for: "MPEG frames"
                tempString = tempString.Right(tempString.Len() - tempString.Find(_T("MPEG frames")));

                // Update Version column
                if (tempString.AfterFirst('(').BeforeFirst(')').Find(_T("MPEG")) != wxNOT_FOUND)
                    mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_VERSION, tempString.AfterFirst('(').BeforeFirst(')'));

                // Update Tags column
                mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_TAGS, tempString.AfterFirst(',').BeforeFirst(','));

                // Update CBR column
                if (tempString.AfterFirst(',').AfterFirst(',').Find(_T("CBR")) != wxNOT_FOUND)
                    mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_CBR, _T("CBR"));
                else
                    mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_CBR, _T("VBR"));
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
        default:
        case STATE_MP3_OK:
            mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_STATE, _("OK"));
            mp_listManager->getListCtrl().SetItemTextColour(fileIterator, *wxBLACK);
            break;
        case STATE_MP3_PROBLEM:
            mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_STATE, _("PROBLEM"));
            mp_listManager->getListCtrl().SetItemTextColour(fileIterator, *wxRED);
            break;
        case STATE_MP3_FIXED:
            mp_listManager->getListCtrl().SetItem(fileIterator, ID_LIST_STATE, _("FIXED"));
            mp_listManager->getListCtrl().SetItemTextColour(fileIterator, *wxBLACK);
            break;
        }

        // Clear the output
        m_exeInputString.Clear();
    }
    return stateMP3;
}
