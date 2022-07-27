/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "AppSettings.hpp"
#include "Constants.hpp"

AppSettings::AppSettings(const wxString &appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (getAppVersion().Cmp(APP_VERSION) != 0)
        setDefaultConfig();
}

AppSettings::~AppSettings() {
    delete mp_config;
}

void AppSettings::setDefaultConfig() {
    setAppVersion(APP_VERSION);
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setDeleteBackup(DEFAULT_VALUE_DeleteBackup);
}

void AppSettings::setConfigFlush() {
    mp_config->Flush();
}

wxString AppSettings::getStringToolOptions() const {
    wxString toolOptions;

    if (getDeleteBackup())
        toolOptions.append(_T("-nb "));

    toolOptions.Trim();
    return toolOptions;
}

// Gets

wxString AppSettings::getAppVersion() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, &value);
    return value;
}

wxString AppSettings::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, &value);
    return value;
}

bool AppSettings::getDeleteBackup() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteBackup, &value);
    return value;
}

// Sets

void AppSettings::setAppVersion(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, value);
}

void AppSettings::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, value);
}

void AppSettings::setDeleteBackup(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteBackup, value);
}
