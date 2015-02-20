///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

Main::Main( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	g_lstFiles = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer1->Add( g_lstFiles, 1, wxALL|wxEXPAND, 0 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	g_mainMenuBar = new wxMenuBar( 0 );
	g_mnbFile = new wxMenu();
	wxMenuItem* g_mnbAddFolder;
	g_mnbAddFolder = new wxMenuItem( g_mnbFile, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFolder );
	
	wxMenuItem* g_mnbAddFiles;
	g_mnbAddFiles = new wxMenuItem( g_mnbFile, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbAddFiles );
	
	g_mnbFile->AppendSeparator();
	
	wxMenuItem* g_mnbExit;
	g_mnbExit = new wxMenuItem( g_mnbFile, ID_EXIT, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbFile->Append( g_mnbExit );
	
	g_mainMenuBar->Append( g_mnbFile, _("&File") ); 
	
	g_mnbEdit = new wxMenu();
	wxMenuItem* g_mnbRemoveFiles;
	g_mnbRemoveFiles = new wxMenuItem( g_mnbEdit, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbRemoveFiles );
	
	wxMenuItem* g_mnbClearList;
	g_mnbClearList = new wxMenuItem( g_mnbEdit, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbClearList );
	
	g_mnbEdit->AppendSeparator();
	
	wxMenuItem* g_mnbSettings;
	g_mnbSettings = new wxMenuItem( g_mnbEdit, ID_SETTINGS, wxString( _("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbEdit->Append( g_mnbSettings );
	
	g_mainMenuBar->Append( g_mnbEdit, _("&Edit") ); 
	
	g_mnbActions = new wxMenu();
	wxMenuItem* g_mnbScan;
	g_mnbScan = new wxMenuItem( g_mnbActions, ID_SCAN, wxString( _("Scan") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbActions->Append( g_mnbScan );
	
	wxMenuItem* g_mnbRepair;
	g_mnbRepair = new wxMenuItem( g_mnbActions, ID_REPAIR, wxString( _("Repair") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbActions->Append( g_mnbRepair );
	
	g_mainMenuBar->Append( g_mnbActions, _("&Actions") ); 
	
	g_mnbHelp = new wxMenu();
	wxMenuItem* g_mnbToolWebsite;
	g_mnbToolWebsite = new wxMenuItem( g_mnbHelp, ID_WEBSITE, wxString( _("MP3val Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbToolWebsite );
	
	wxMenuItem* g_mnbWebsite;
	g_mnbWebsite = new wxMenuItem( g_mnbHelp, ID_TOOL_WEBSITE, wxString( _("wxMP3val Website") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbWebsite );
	
	g_mnbHelp->AppendSeparator();
	
	wxMenuItem* g_mnbAbout;
	g_mnbAbout = new wxMenuItem( g_mnbHelp, ID_ABOUT, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	g_mnbHelp->Append( g_mnbAbout );
	
	g_mainMenuBar->Append( g_mnbHelp, _("&Help") ); 
	
	this->SetMenuBar( g_mainMenuBar );
	
	g_mainStatusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	g_mainToolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	g_tbAddFolder = g_mainToolBar->AddTool( ID_ADD_FOLDER, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add folder"), wxEmptyString, NULL ); 
	
	g_tbAddFiles = g_mainToolBar->AddTool( ID_ADD_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Add files"), wxEmptyString, NULL ); 
	
	g_tbRemoveFiles = g_mainToolBar->AddTool( ID_REMOVE_FILES, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Remove files"), wxEmptyString, NULL ); 
	
	g_tbClearList = g_mainToolBar->AddTool( ID_CLEAR_LIST, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Clear list"), wxEmptyString, NULL ); 
	
	g_mainToolBar->AddSeparator(); 
	
	g_tbScan = g_mainToolBar->AddTool( ID_SCAN, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Scan"), wxEmptyString, NULL ); 
	
	g_tbRepair = g_mainToolBar->AddTool( ID_REPAIR, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Repair"), wxEmptyString, NULL ); 
	
	g_mainToolBar->AddSeparator(); 
	
	g_tbSettings = g_mainToolBar->AddTool( ID_SETTINGS, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("Settings"), wxEmptyString, NULL ); 
	
	g_tbAbout = g_mainToolBar->AddTool( ID_ABOUT, wxEmptyString, wxArtProvider::GetBitmap( wxART_MISSING_IMAGE, wxART_TOOLBAR ), wxNullBitmap, wxITEM_NORMAL, _("About"), wxEmptyString, NULL ); 
	
	g_mainToolBar->Realize(); 
	
	g_mainMenu = new wxMenu();
	wxMenuItem* g_mnuAddFolder;
	g_mnuAddFolder = new wxMenuItem( g_mainMenu, ID_ADD_FOLDER, wxString( _("Add folder") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFolder );
	
	wxMenuItem* g_mnuAddFiles;
	g_mnuAddFiles = new wxMenuItem( g_mainMenu, ID_ADD_FILES, wxString( _("Add files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuAddFiles );
	
	wxMenuItem* g_mnuRemoveFiles;
	g_mnuRemoveFiles = new wxMenuItem( g_mainMenu, ID_REMOVE_FILES, wxString( _("Remove files") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuRemoveFiles );
	
	wxMenuItem* g_mnuClearList;
	g_mnuClearList = new wxMenuItem( g_mainMenu, ID_CLEAR_LIST, wxString( _("Clear list") ) , wxEmptyString, wxITEM_NORMAL );
	g_mainMenu->Append( g_mnuClearList );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( Main::MainOnContextMenu ), NULL, this ); 
	
	m_timer1.SetOwner( this, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( Main::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( Main::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( Main::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( Main::OnlstFilesKeyDown ), NULL, this );
	this->Connect( g_mnbAddFolder->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_mnbAddFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_mnbExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuExit ) );
	this->Connect( g_mnbRemoveFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_mnbClearList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( g_mnbSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Connect( g_mnbScan->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuScan ) );
	this->Connect( g_mnbRepair->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRepair ) );
	this->Connect( g_mnbToolWebsite->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuToolWebsite ) );
	this->Connect( g_mnbWebsite->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuWebsite ) );
	this->Connect( g_mnbAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Connect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( g_tbScan->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuScan ) );
	this->Connect( g_tbRepair->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRepair ) );
	this->Connect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Connect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Connect( g_mnuAddFolder->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Connect( g_mnuAddFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Connect( g_mnuRemoveFiles->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Connect( g_mnuClearList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( Main::OnTimer1Trigger ) );
}

Main::~Main()
{
	// Disconnect Events
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( Main::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( Main::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( Main::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( Main::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( Main::OnlstFilesKeyDown ), NULL, this );
	this->Disconnect( ID_ADD_FOLDER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( ID_ADD_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( ID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuExit ) );
	this->Disconnect( ID_REMOVE_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( ID_CLEAR_LIST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( ID_SETTINGS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Disconnect( ID_SCAN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuScan ) );
	this->Disconnect( ID_REPAIR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRepair ) );
	this->Disconnect( ID_WEBSITE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuToolWebsite ) );
	this->Disconnect( ID_TOOL_WEBSITE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuWebsite ) );
	this->Disconnect( ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Disconnect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( g_tbScan->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuScan ) );
	this->Disconnect( g_tbRepair->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuRepair ) );
	this->Disconnect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuSettings ) );
	this->Disconnect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( Main::mnuAbout ) );
	this->Disconnect( ID_ADD_FOLDER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddDirectory ) );
	this->Disconnect( ID_ADD_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuAddFiles ) );
	this->Disconnect( ID_REMOVE_FILES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuRemoveFiles ) );
	this->Disconnect( ID_CLEAR_LIST, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Main::mnuClearList ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( Main::OnTimer1Trigger ) );
	
	delete g_mainMenu; 
}

Settings::Settings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxVERTICAL );
	
	g_chkKeepTimestamps = new wxCheckBox( m_panel1, wxID_ANY, _("Keep file timestamps"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( g_chkKeepTimestamps, 0, wxALL, 2 );
	
	g_chkDeleteBackup = new wxCheckBox( m_panel1, wxID_ANY, _("Delete bakup files"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( g_chkDeleteBackup, 0, wxALL, 2 );
	
	
	bSizer4->Add( sbSizer2, 0, wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer4 );
	m_panel1->Layout();
	bSizer4->Fit( m_panel1 );
	m_notebook1->AddPage( m_panel1, _("General"), false );
	
	bSizer2->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	g_btnDefault = new wxButton( this, wxID_ANY, _("Restore defaults"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnDefault, 1, wxALL, 5 );
	
	g_btnOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnOK, 1, wxALL, 5 );
	
	g_btnCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( g_btnCancel, 1, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	g_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnCancelClick ), NULL, this );
}

Settings::~Settings()
{
	// Disconnect Events
	g_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnbtnCancelClick ), NULL, this );
	
}
