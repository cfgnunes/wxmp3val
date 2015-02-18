/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmMain.h"
#include "frmSettings.h"
#include "Progress.h"
#include "Global.h"

//(*InternalHeaders(frmMain)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)

#include <wx/aboutdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

//(*IdInit(frmMain)
const long frmMain::ID_LISTCTRL1 = wxNewId();
const long frmMain::ID_MENUITEM14 = wxNewId();
const long frmMain::ID_MENUITEM2 = wxNewId();
const long frmMain::ID_MENUITEM1 = wxNewId();
const long frmMain::ID_MENUITEM3 = wxNewId();
const long frmMain::ID_MENUITEM4 = wxNewId();
const long frmMain::ID_MENUITEM6 = wxNewId();
const long frmMain::ID_MENUITEM7 = wxNewId();
const long frmMain::ID_MENUITEM8 = wxNewId();
const long frmMain::ID_MENUITEM10 = wxNewId();
const long frmMain::ID_MENUITEM11 = wxNewId();
const long frmMain::ID_MENUITEM9 = wxNewId();
const long frmMain::ID_STATUSBAR1 = wxNewId();
const long frmMain::ID_TOOLBARITEM8 = wxNewId();
const long frmMain::ID_TOOLBARITEM1 = wxNewId();
const long frmMain::ID_TOOLBARITEM2 = wxNewId();
const long frmMain::ID_TOOLBARITEM3 = wxNewId();
const long frmMain::ID_TOOLBARITEM4 = wxNewId();
const long frmMain::ID_TOOLBARITEM5 = wxNewId();
const long frmMain::ID_TOOLBARITEM6 = wxNewId();
const long frmMain::ID_TOOLBARITEM7 = wxNewId();
const long frmMain::ID_TOOLBAR1 = wxNewId();
const long frmMain::ID_MENUITEM15 = wxNewId();
const long frmMain::ID_MENUITEM5 = wxNewId();
const long frmMain::ID_MENUITEM12 = wxNewId();
const long frmMain::ID_MENUITEM13 = wxNewId();
const long frmMain::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmMain, wxFrame)
//(*EventTable(frmMain)
//*)
END_EVENT_TABLE()

frmMain::frmMain(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) {
    //(*Initialize(frmMain)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu5;
    wxMenu* Menu3;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem9;
    wxMenu* Menu4;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem10;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem4;
    wxMenu* Menu2;
    wxMenuItem* MenuItem8;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(763, 450));
    Move(wxDefaultPosition);
    g_lstFiles = new wxListCtrl(this, ID_LISTCTRL1, wxPoint(184, 208), wxSize(520, 450), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    g_mainMenuBar = new wxMenuBar();
    Menu2 = new wxMenu();
    MenuItem14 = new wxMenuItem(Menu2, ID_MENUITEM14, _("Add folder"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem14);
    MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM2, _("Add files"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    Menu2->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu2, ID_MENUITEM1, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem1);
    g_mainMenuBar->Append(Menu2, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Remove files"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Clear list"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    Menu3->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    g_mainMenuBar->Append(Menu3, _("&Edit"));
    Menu4 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu4, ID_MENUITEM7, _("Scan"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu4, ID_MENUITEM8, _("Repair"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem8);
    g_mainMenuBar->Append(Menu4, _("&Actions"));
    Menu5 = new wxMenu();
    MenuItem12 = new wxMenuItem(Menu5, ID_MENUITEM10, _("MP3val website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(Menu5, ID_MENUITEM11, _("wxMP3val website"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem13);
    Menu5->AppendSeparator();
    MenuItem9 = new wxMenuItem(Menu5, ID_MENUITEM9, _("About"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem9);
    g_mainMenuBar->Append(Menu5, _("&Help"));
    SetMenuBar(g_mainMenuBar);
    g_mainStatusBar = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = {-10, -5, -10};
    int __wxStatusBarStyles_1[3] = {wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL};
    g_mainStatusBar->SetFieldsCount(3, __wxStatusBarWidths_1);
    g_mainStatusBar->SetStatusStyles(3, __wxStatusBarStyles_1);
    SetStatusBar(g_mainStatusBar);
    g_mainToolBar = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_FLAT | wxTB_HORIZONTAL | wxTB_TEXT | wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = g_mainToolBar->AddTool(ID_TOOLBARITEM8, _("Add folder"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = g_mainToolBar->AddTool(ID_TOOLBARITEM1, _("Add files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = g_mainToolBar->AddTool(ID_TOOLBARITEM2, _("Remove files"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem4 = g_mainToolBar->AddTool(ID_TOOLBARITEM3, _("Clear list"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->AddSeparator();
    ToolBarItem5 = g_mainToolBar->AddTool(ID_TOOLBARITEM4, _("Scan"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem6 = g_mainToolBar->AddTool(ID_TOOLBARITEM5, _("Repair"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->AddSeparator();
    ToolBarItem7 = g_mainToolBar->AddTool(ID_TOOLBARITEM6, _("Settings"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem8 = g_mainToolBar->AddTool(ID_TOOLBARITEM7, _("About"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUESTION")), wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    g_mainToolBar->Realize();
    SetToolBar(g_mainToolBar);
    MenuItem15 = new wxMenuItem((&g_mainMenu), ID_MENUITEM15, _("Add folder"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem15);
    MenuItem5 = new wxMenuItem((&g_mainMenu), ID_MENUITEM5, _("Add files"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem5);
    MenuItem10 = new wxMenuItem((&g_mainMenu), ID_MENUITEM12, _("Remove files"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem10);
    MenuItem11 = new wxMenuItem((&g_mainMenu), ID_MENUITEM13, _("Clear list"), wxEmptyString, wxITEM_NORMAL);
    g_mainMenu.Append(MenuItem11);
    Timer1.SetOwner(this, ID_TIMER1);
    Center();

    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_DELETE_ITEM, (wxObjectEventFunction) & frmMain::OnlstFilesDeleteItem);
    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_ITEM_SELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesItemSelect);
    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_ITEM_DESELECTED, (wxObjectEventFunction) & frmMain::OnlstFilesItemSelect);
    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, (wxObjectEventFunction) & frmMain::OnlstFilesItemRClick);
    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_KEY_DOWN, (wxObjectEventFunction) & frmMain::OnlstFilesKeyDown);
    Connect(ID_LISTCTRL1, wxEVT_COMMAND_LIST_INSERT_ITEM, (wxObjectEventFunction) & frmMain::OnlstFilesInsertItem);
    Connect(ID_MENUITEM14, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_MENUITEM2, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuExit);
    Connect(ID_MENUITEM3, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_MENUITEM4, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_MENUITEM6, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuSettings);
    Connect(ID_MENUITEM7, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuScan);
    Connect(ID_MENUITEM8, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuFix);
    Connect(ID_MENUITEM10, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuToolWebsite);
    Connect(ID_MENUITEM11, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuWebsite);
    Connect(ID_MENUITEM9, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAbout);
    Connect(ID_TOOLBARITEM8, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_TOOLBARITEM1, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_TOOLBARITEM2, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_TOOLBARITEM3, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_TOOLBARITEM4, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuScan);
    Connect(ID_TOOLBARITEM5, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuFix);
    Connect(ID_TOOLBARITEM6, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuSettings);
    Connect(ID_TOOLBARITEM7, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction) & frmMain::mnuAbout);
    Connect(ID_MENUITEM15, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddDirectory);
    Connect(ID_MENUITEM5, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuAddFiles);
    Connect(ID_MENUITEM12, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuRemoveFiles);
    Connect(ID_MENUITEM13, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction) & frmMain::mnuClearList);
    Connect(ID_TIMER1, wxEVT_TIMER, (wxObjectEventFunction) & frmMain::OnTimer1Trigger);
    //*)

    // Disable status bar pane used to display menu and toolbar help
    SetStatusBarPane(-1);

    // Aux list for wxListctrl
    mp_lstFilesData = new ArrayOfFiles();

    // Support Drag & Drop
    mp_dndFile = new DndFile(g_lstFiles, mp_lstFilesData);
    g_lstFiles->SetDropTarget(mp_dndFile);

    // Configuration file
    mp_configBase = new ConfigBase(APP_NAME);

    // Window title
    SetTitle(APP_NAME_WITH_VERSION);

    // Load resource
    loadResources();

    // Title List
    g_lstFiles->InsertColumn(0, _("File"), wxLIST_FORMAT_LEFT, 350);
    g_lstFiles->InsertColumn(1, _("Version"), wxLIST_FORMAT_LEFT, 100);
    g_lstFiles->InsertColumn(2, _("Tags"), wxLIST_FORMAT_LEFT, 100);
    g_lstFiles->InsertColumn(3, _("CBR"), wxLIST_FORMAT_LEFT, 80);
    g_lstFiles->InsertColumn(4, _("State"), wxLIST_FORMAT_LEFT, 80);

    // Updates the controls
    updateControls();
}

frmMain::~frmMain() {
    delete mp_lstFilesData;

    // Deletes the object configuration file and updates the file / record
    delete mp_configBase;
}

void frmMain::setFilesCmdLine(const wxArrayString& filenames) {
    mp_dndFile->OnDropFiles(0, 0, filenames);
}

void frmMain::mnuAddFiles(wxCommandEvent& event) {
    wxArrayString files;
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, APP_WILDCARD_EXT, wxFD_OPEN | wxFD_MULTIPLE);

    // Read the last directory used
    fileDialog.SetDirectory(mp_configBase->getLastOpenDir());

    if (fileDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);

        // Get the file(s) the user selected
        fileDialog.GetPaths(files);
        mp_dndFile->insertFileList(files);

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(fileDialog.GetDirectory());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuAddDirectory(wxCommandEvent& event) {
    wxDirDialog dirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE);

    // Read the last directory used
    dirDialog.SetPath(mp_configBase->getLastOpenDir());
    if (dirDialog.ShowModal() == wxID_OK) {
        SetCursor(wxCURSOR_WAIT);
        mp_dndFile->insertFileListDir(dirDialog.GetPath());

        // Remembers the last used directory
        mp_configBase->setLastOpenDir(dirDialog.GetPath());
        SetCursor(wxCURSOR_ARROW);
    }
}

void frmMain::mnuExit(wxCommandEvent& event) {
    // Terminates the program
    Close();
}

void frmMain::mnuClearList(wxCommandEvent& event) {
    // Deletes all items from the list
    g_lstFiles->DeleteAllItems();
    mp_lstFilesData->Clear();

    updateControls();
}

void frmMain::mnuRemoveFiles(wxCommandEvent& event) {
    int itemCount = g_lstFiles->GetSelectedItemCount();
    SetCursor(wxCURSOR_WAIT);
    for (int i = 0; i < itemCount; i++)
        g_lstFiles->DeleteItem(g_lstFiles->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED));
    SetCursor(wxCURSOR_ARROW);

    updateControls();
}

void frmMain::mnuScan(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, g_lstFiles, mp_lstFilesData, TOOL_SCAN);
    progressDialog.execute();
}

void frmMain::mnuFix(wxCommandEvent& event) {
    // Displays the "Progress" window
    Progress progressDialog(this, mp_configBase, g_lstFiles, mp_lstFilesData, TOOL_FIX);
    progressDialog.execute();
}

void frmMain::mnuSettings(wxCommandEvent& event) {
    // Displays the "Settings" window
    frmSettings progressDialog(this, mp_configBase);
    progressDialog.ShowModal();

    updateControls();
}

void frmMain::mnuAbout(wxCommandEvent& event) {
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(APP_NAME);
    aboutInfo.SetVersion(APP_VERSION);
    aboutInfo.SetDescription(_("Free front-end for the MP3val"));
    aboutInfo.SetCopyright(APP_COPYRIGHT);
    aboutInfo.SetWebSite(APP_WEBSITE);
    aboutInfo.AddDeveloper(APP_AUTHOR);
    aboutInfo.AddTranslator(APP_AUTHOR);
    aboutInfo.AddTranslator(_T("Carlos Sánchez <carlos1994sanchez@gmail.com>"));
    aboutInfo.AddTranslator(_T("Jan Rimmek <jan@rimmek.de>"));
    aboutInfo.AddTranslator(_T("Sergey Basalaev <sbasalaev@gmail.com>"));
    aboutInfo.AddTranslator(_T("Pavel Fric <pavelfric@seznam.cz>"));
    wxAboutBox(aboutInfo);
}

void frmMain::mnuWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(APP_WEBSITE);
}

void frmMain::mnuToolWebsite(wxCommandEvent& event) {
    wxLaunchDefaultBrowser(_T("http://mp3val.sourceforge.net/"));
}

void frmMain::loadResources() {
    wxString resourceDir = GetResourceDir();

    // Window icon
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(resourceDir + _T("icon2.ico"))));
    SetIcon(FrameIcon);

    // Toolbar bitmaps
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM1, wxBitmap(wxImage(resourceDir + _T("toolbar/add.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM2, wxBitmap(wxImage(resourceDir + _T("toolbar/remove.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM3, wxBitmap(wxImage(resourceDir + _T("toolbar/clear.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM4, wxBitmap(wxImage(resourceDir + _T("toolbar/scan.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM5, wxBitmap(wxImage(resourceDir + _T("toolbar/fix.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM6, wxBitmap(wxImage(resourceDir + _T("toolbar/settings.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM7, wxBitmap(wxImage(resourceDir + _T("toolbar/about.png"))));
    g_mainToolBar->SetToolNormalBitmap(ID_TOOLBARITEM8, wxBitmap(wxImage(resourceDir + _T("toolbar/folder.png"))));
}

void frmMain::OnlstFilesItemRClick(wxListEvent& event) {
    updateControls();

    // Displays the popup menu when you click a list item
    g_lstFiles->PopupMenu(&g_mainMenu);
    event.Skip();
}

void frmMain::OnlstFilesDeleteItem(wxListEvent& event) {
    mp_lstFilesData->Detach(event.GetIndex());
    updateControls();
    event.Skip();
}

void frmMain::OnlstFilesInsertItem(wxListEvent& event) {
    /*
     * :KLUDGE:
     * EVT_LIST_INSERT_ITEM is triggered before or after item is added:
     *   on wxGTK -> triggered before item is added;
     *   on wxMSW -> triggered after item is added.
     */
    updateControlsDelayed();
    event.Skip();
}

void frmMain::updateControls() {
    wxString newExeTool = mp_configBase->getToolExecutable();
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

    // Disables the menu item "Remove files" if no item is selected
    g_mainMenu.Enable(ID_MENUITEM12, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM3, g_lstFiles->GetSelectedItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM2, g_lstFiles->GetSelectedItemCount() > 0);

    // Disables the menu item "Clear list" if there is no item in the list
    g_mainMenu.Enable(ID_MENUITEM13, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM4, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM3, g_lstFiles->GetItemCount() > 0);

    // Disables menus Scan and Fix case there is no item in the list
    g_mainMenuBar->Enable(ID_MENUITEM7, g_lstFiles->GetItemCount() > 0);
    g_mainMenuBar->Enable(ID_MENUITEM8, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM4, g_lstFiles->GetItemCount() > 0);
    g_mainToolBar->EnableTool(ID_TOOLBARITEM5, g_lstFiles->GetItemCount() > 0);
}

void frmMain::updateControlsDelayed() {
    Timer1.Start(10, true);
}

void frmMain::OnTimer1Trigger(wxTimerEvent& event) {
    updateControls();
}

void frmMain::OnlstFilesKeyDown(wxListEvent& event) {
    // Remove files with Delete key
    int keyCode = event.GetKeyCode();
    if (keyCode == WXK_DELETE)
        mnuRemoveFiles(event);

    event.Skip();
}

void frmMain::OnlstFilesItemSelect(wxListEvent& event) {
    updateControls();
    event.Skip();
}
