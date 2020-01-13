///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jan  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Gui.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* g_boxMain;
	g_boxMain = new wxBoxSizer( wxHORIZONTAL );

	wxPanel* m_panel2;
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	g_lstFiles = new wxListCtrl( m_panel2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxLC_REPORT );
	bSizer6->Add( g_lstFiles, 1, wxALL|wxEXPAND, 0 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	g_gugProgress = new wxGauge( m_panel2, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	g_gugProgress->SetValue( 0 );
	bSizer7->Add( g_gugProgress, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	g_btnStop = new wxButton( m_panel2, wxID_ANY, _("&Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	g_btnStop->Enable( false );

	bSizer7->Add( g_btnStop, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer6->Add( bSizer7, 0, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer6 );
	m_panel2->Layout();
	bSizer6->Fit( m_panel2 );
	g_boxMain->Add( m_panel2, 1, wxEXPAND, 5 );


	this->SetSizer( g_boxMain );
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

	g_mainStatusBar = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	g_mainToolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
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

	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( FrameMain::FrameMainOnContextMenu ), NULL, this );

	m_timer1.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Connect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	g_btnStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnbAddFolder->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnbAddFiles->GetId());
	g_mnbFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuExit ), this, g_mnbExit->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnbRemoveFiles->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnbClearList->GetId());
	g_mnbEdit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuSettings ), this, g_mnbSettings->GetId());
	g_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuScan ), this, g_mnbScan->GetId());
	g_mnbActions->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRepair ), this, g_mnbRepair->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuToolWebsite ), this, g_mnbToolWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuWebsite ), this, g_mnbWebsite->GetId());
	g_mnbHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAbout ), this, g_mnbAbout->GetId());
	this->Connect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Connect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Connect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Connect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Connect( g_tbScan->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuScan ) );
	this->Connect( g_tbRepair->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRepair ) );
	this->Connect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Connect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddDirectory ), this, g_mnuAddFolder->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuAddFiles ), this, g_mnuAddFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ), this, g_mnuRemoveFiles->GetId());
	g_mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::mnuClearList ), this, g_mnuClearList->GetId());
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_DELETE_ITEM, wxListEventHandler( FrameMain::OnlstFilesDeleteItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_INSERT_ITEM, wxListEventHandler( FrameMain::OnlstFilesInsertItem ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_DESELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( FrameMain::OnlstFilesItemRClick ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( FrameMain::OnlstFilesItemSelect ), NULL, this );
	g_lstFiles->Disconnect( wxEVT_COMMAND_LIST_KEY_DOWN, wxListEventHandler( FrameMain::OnlstFilesKeyDown ), NULL, this );
	g_btnStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::btnProcessStop ), NULL, this );
	this->Disconnect( g_tbAddFolder->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddDirectory ) );
	this->Disconnect( g_tbAddFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAddFiles ) );
	this->Disconnect( g_tbRemoveFiles->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRemoveFiles ) );
	this->Disconnect( g_tbClearList->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuClearList ) );
	this->Disconnect( g_tbScan->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuScan ) );
	this->Disconnect( g_tbRepair->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuRepair ) );
	this->Disconnect( g_tbSettings->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuSettings ) );
	this->Disconnect( g_tbAbout->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( FrameMain::mnuAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( FrameMain::OnTimer1Trigger ) );

	delete g_mainMenu;
}

DialogSettings::DialogSettings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxNotebook* m_notebook1;
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxPanel* m_panel1;
	m_panel1 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("File options") ), wxVERTICAL );

	g_chkDeleteBackup = new wxCheckBox( sbSizer2->GetStaticBox(), wxID_ANY, _("Delete bakup files"), wxDefaultPosition, wxDefaultSize, 0 );
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
	g_btnDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );
}

DialogSettings::~DialogSettings()
{
	// Disconnect Events
	g_btnDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnDefaultClick ), NULL, this );
	g_btnOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnOKClick ), NULL, this );
	g_btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSettings::OnbtnCancelClick ), NULL, this );

}
