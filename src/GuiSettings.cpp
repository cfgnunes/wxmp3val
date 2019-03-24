/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "GuiSettings.h"
#include "Constants.h"

GuiSettings::GuiSettings(wxWindow *parent, ConfigBase *configBase)
        : Settings(parent), mp_configBase(configBase) {
    // Updates the values controls according to the configuration file
    updateValueControls();
}

GuiSettings::~GuiSettings() {
}

void GuiSettings::OnbtnDefaultClick(wxCommandEvent &event) {
    defaultValueControls();
}

void GuiSettings::OnbtnOKClick(wxCommandEvent &event) {
    saveValuesConfig();
    Close();
}

void GuiSettings::OnbtnCancelClick(wxCommandEvent &event) {
    Close();
}

void GuiSettings::updateValueControls() {
    // General controls
    g_chkKeepTimestamps->SetValue(mp_configBase->getKeepTimestamp());
    g_chkDeleteBackup->SetValue(mp_configBase->getDeleteBackup());
}

void GuiSettings::saveValuesConfig() {
    // General controls
    mp_configBase->setKeepTimestamp(g_chkKeepTimestamps->GetValue());
    mp_configBase->setDeleteBackup(g_chkDeleteBackup->GetValue());

    mp_configBase->setConfigFlush();
}

void GuiSettings::defaultValueControls() {
    // General controls
    g_chkKeepTimestamps->SetValue(DEFAULT_VALUE_KeepTimestamp);
    g_chkDeleteBackup->SetValue(DEFAULT_VALUE_DeleteBackup);
}
