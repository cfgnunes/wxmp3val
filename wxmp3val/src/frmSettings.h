/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMSETTINGS_H
#define FRMSETTINGS_H

#include "ConfigBase.h"

//(*Headers(frmSettings)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
//*)

class frmSettings : public wxDialog
{
public:

    frmSettings(wxWindow* parent, ConfigBase* configBase, wxWindowID id = wxID_ANY);
    virtual ~frmSettings();

    //(*Declarations(frmSettings)
    wxCheckBox* chkKeepTimestamps;
    wxPanel* Panel6;
    wxTextCtrl* txtToolExecutable;
    wxFileDialog* FileDialog1;
    wxNotebook* Notebook1;
    wxButton* btnOK;
    wxButton* btnCancel;
    wxCheckBox* chkDeleteBackup;
    wxButton* btnDefault;
    wxButton* btnToolExecutable;
    //*)

protected:

    //(*Identifiers(frmSettings)
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON5;
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX2;
    static const long ID_PANEL6;
    static const long ID_NOTEBOOK1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON4;
    //*)

private:

    //(*Handlers(frmSettings)
    void OnbtnOKClick(wxCommandEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnbtnDefaultClick(wxCommandEvent& event);
    void OnbtnToolExecutableClick(wxCommandEvent& event);
    //*)

    void updateValueControls();
    void defaultValueControls();
    void saveValuesConfig();

    ConfigBase* configBase;
    DECLARE_EVENT_TABLE()
};

#endif
