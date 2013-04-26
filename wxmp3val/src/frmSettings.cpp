/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "frmSettings.h"
#include "Global.h"

//(*InternalHeaders(frmSettings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(frmSettings)
const long frmSettings::ID_TEXTCTRL2 = wxNewId();
const long frmSettings::ID_BUTTON5 = wxNewId();
const long frmSettings::ID_CHECKBOX1 = wxNewId();
const long frmSettings::ID_CHECKBOX2 = wxNewId();
const long frmSettings::ID_PANEL6 = wxNewId();
const long frmSettings::ID_NOTEBOOK1 = wxNewId();
const long frmSettings::ID_BUTTON1 = wxNewId();
const long frmSettings::ID_BUTTON2 = wxNewId();
const long frmSettings::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(frmSettings, wxDialog)
//(*EventTable(frmSettings)
//*)
END_EVENT_TABLE()

frmSettings::frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id)
: configBase(configBase)
{
    //(*Initialize(frmSettings)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer10;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("MP3val executable"));
    txtToolExecutable = new wxTextCtrl(Panel6, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticBoxSizer2->Add(txtToolExecutable, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    btnToolExecutable = new wxButton(Panel6, ID_BUTTON5, _("..."), wxDefaultPosition, wxSize(22,22), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer2->Add(btnToolExecutable, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Other options"));
    chkKeepTimestamps = new wxCheckBox(Panel6, ID_CHECKBOX1, _("Keep file timestamps"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    chkKeepTimestamps->SetValue(false);
    StaticBoxSizer3->Add(chkKeepTimestamps, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    chkDeleteBackup = new wxCheckBox(Panel6, ID_CHECKBOX2, _("Delete bakup files"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    chkDeleteBackup->SetValue(false);
    StaticBoxSizer3->Add(chkDeleteBackup, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 2);
    BoxSizer3->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel6);
    BoxSizer3->SetSizeHints(Panel6);
    Notebook1->AddPage(Panel6, _("General"), false);
    BoxSizer1->Add(Notebook1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    btnDefault = new wxButton(this, ID_BUTTON1, _("Restore Defaults"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer10->Add(btnDefault, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOK = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer10->Add(btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer10->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnToolExecutableClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnDefaultClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnOKClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&frmSettings::OnbtnCancelClick);
    //*)

    // Updates the volores controls according to the configuration file
    updateValueControls();
}

frmSettings::~frmSettings()
{
    //(*Destroy(frmSettings)
    //*)
}

void frmSettings::OnbtnOKClick(wxCommandEvent& event)
{
    saveValuesConfig();
    Close();
}

void frmSettings::OnbtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void frmSettings::OnbtnDefaultClick(wxCommandEvent& event)
{
    defaultValueControls();
}

void frmSettings::OnbtnToolExecutableClick(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal() == wxID_OK)
    {
        txtToolExecutable->Clear();
        txtToolExecutable->WriteText(FileDialog1->GetPath());
    }
}

void frmSettings::updateValueControls()
{
    wxScrollEvent evt;

    // General controls
    txtToolExecutable->Clear();
    txtToolExecutable->WriteText(configBase->getToolExecutable());
    chkKeepTimestamps->SetValue(configBase->getKeepTimestamp());
    chkDeleteBackup->SetValue(configBase->getDeleteBackup());
}

void frmSettings::saveValuesConfig()
{
    // General controls
    configBase->setToolExecutable(txtToolExecutable->GetLineText(0));
    configBase->setKeepTimestamp(chkKeepTimestamps->GetValue());
    configBase->setDeleteBackup(chkDeleteBackup->GetValue());

    configBase->setConfigFlush();
}

void frmSettings::defaultValueControls()
{
    // General controls
    txtToolExecutable->Clear();
    txtToolExecutable->WriteText(DEFAULT_VALUE_ToolExecutable);
    chkKeepTimestamps->SetValue(DEFAULT_VALUE_KeepTimestamp);
    chkDeleteBackup->SetValue(DEFAULT_VALUE_DeleteBackup);
}
