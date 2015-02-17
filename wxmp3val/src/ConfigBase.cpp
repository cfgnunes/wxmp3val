/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"
#include "Global.h"

ConfigBase::ConfigBase(const wxString& appName) {
    mp_config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (!mp_config->Exists(CONFIG_GENERAL_GROUP))
        setDefaultConfig();
}

ConfigBase::~ConfigBase() {
    delete mp_config;
}

void ConfigBase::setDefaultConfig() {
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setToolExecutable(DEFAULT_VALUE_ToolExecutable);
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

wxString ConfigBase::getLastOpenDir() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, &value);
    return value;
}

wxString ConfigBase::getToolExecutable() const {
    wxString value = wxEmptyString;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, &value);
    return value;
}

bool ConfigBase::getKeepTimestamp() const {
    bool value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_KeepTimestamp, &value);
    return value;
}

bool ConfigBase::getDeleteBackup() const {
    bool value;
    mp_config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteBackup, &value);
    return value;
}

// Sets...

void ConfigBase::setLastOpenDir(wxString value) {
    mp_config->Write(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setToolExecutable(wxString value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, value);
}

void ConfigBase::setKeepTimestamp(bool value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_KeepTimestamp, value);
}

void ConfigBase::setDeleteBackup(bool value) {
    mp_config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteBackup, value);
}
