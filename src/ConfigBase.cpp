/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"
#include "Constants.h"

ConfigBase::ConfigBase(const wxString &appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (getAppVersion().Cmp(APP_VERSION) != 0)
        setDefaultConfig();
}

ConfigBase::~ConfigBase() {
    delete mp_config;
}

void ConfigBase::setDefaultConfig() {
    setAppVersion(APP_VERSION);
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setKeepTimestamp(DEFAULT_VALUE_KeepTimestamp);
    setDeleteBackup(DEFAULT_VALUE_DeleteBackup);
}

void ConfigBase::setConfigFlush() {
    mp_config->Flush();
}

wxString ConfigBase::getStringToolOptions() const {
    wxString toolOptions;

    if (getKeepTimestamp())
        toolOptions.append(_T("-t "));

    if (getDeleteBackup())
        toolOptions.append(_T("-nb "));

    toolOptions.Trim();
    return toolOptions;
}

// Gets...

wxString ConfigBase::getAppVersion() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, &value);
    return value;
}

wxString ConfigBase::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, &value);
    return value;
}

bool ConfigBase::getKeepTimestamp() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_KeepTimestamp, &value);
    return value;
}

bool ConfigBase::getDeleteBackup() const {
    bool value;
    mp_config->Read(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteBackup, &value);
    return value;
}

// Sets...

void ConfigBase::setAppVersion(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_AppVersion, value);
}

void ConfigBase::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_GROUP_SYSTEM + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setKeepTimestamp(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_KeepTimestamp, value);
}

void ConfigBase::setDeleteBackup(bool value) {
    mp_config->Write(CONFIG_GROUP_GENERAL + CONFIG_STR_DeleteBackup, value);
}
