/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiSettings.h"

#include <wx/filedlg.h>

GuiSettings::GuiSettings(wxWindow* parent, ConfigBase* configBase)
:Settings(parent), mp_configBase(configBase) {
    // Set labels of controls
    setLabelsControls();

    // Updates the values controls according to the configuration file
    updateValueControls();
}

void GuiSettings::OnbtnToolExecutableClick(wxCommandEvent& event) {
    wxFileDialog fileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_OPEN);
    if (fileDialog.ShowModal() == wxID_OK) {
        g_txtToolExecutable->Clear();
        g_txtToolExecutable->WriteText(fileDialog.GetPath());
    }
}

void GuiSettings::OnbtnDefaultClick(wxCommandEvent& event) {
    defaultValueControls();
}

void GuiSettings::OnbtnOKClick(wxCommandEvent& event) {
    saveValuesConfig();
    Close();
}

void GuiSettings::OnbtnCancelClick(wxCommandEvent& event) {
    Close();
}

void GuiSettings::updateValueControls() {
    wxScrollEvent evt;

    // General controls
    g_txtToolExecutable->Clear();
    g_txtToolExecutable->WriteText(mp_configBase->getToolExecutable());
    g_chkKeepTimestamps->SetValue(mp_configBase->getKeepTimestamp());
    g_chkDeleteBackup->SetValue(mp_configBase->getDeleteBackup());
}

void GuiSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setToolExecutable(g_txtToolExecutable->GetLineText(0));
    mp_configBase->setKeepTimestamp(g_chkKeepTimestamps->GetValue());
    mp_configBase->setDeleteBackup(g_chkDeleteBackup->GetValue());

    mp_configBase->setConfigFlush();
}

void GuiSettings::defaultValueControls() {
    // General controls
    g_txtToolExecutable->Clear();
    g_txtToolExecutable->WriteText(DEFAULT_VALUE_ToolExecutable);
    g_chkKeepTimestamps->SetValue(DEFAULT_VALUE_KeepTimestamp);
    g_chkDeleteBackup->SetValue(DEFAULT_VALUE_DeleteBackup);
}

void GuiSettings::setLabelsControls() {
    g_btnToolExecutable->SetLabel(_T("..."));
}
