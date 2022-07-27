/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiDialogSettings.hpp"
#include "../Constants.hpp"

GuiDialogSettings::GuiDialogSettings(wxWindow *parent, AppSettings *appSettings) : DialogSettings(parent), mp_appSettings(appSettings) {
    // Updates the values controls according to the configuration file
    updateValueControls();
}

GuiDialogSettings::~GuiDialogSettings() {
}

void GuiDialogSettings::OnbtnDefaultClick(wxCommandEvent &event) {
    defaultValueControls();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnOKClick(wxCommandEvent &event) {
    saveValuesConfig();
    Close();
    event.Skip(false);
}

void GuiDialogSettings::OnbtnCancelClick(wxCommandEvent &event) {
    Close();
    event.Skip(false);
}

void GuiDialogSettings::updateValueControls() {
    // General controls
    gui_chkDeleteBackup->SetValue(mp_appSettings->getDeleteBackup());
}

void GuiDialogSettings::saveValuesConfig() {
    // General controls
    mp_appSettings->setDeleteBackup(gui_chkDeleteBackup->GetValue());

    mp_appSettings->flush();
}

void GuiDialogSettings::defaultValueControls() {
    // General controls
    gui_chkDeleteBackup->SetValue(DEFAULT_VALUE_DeleteBackup);
}
