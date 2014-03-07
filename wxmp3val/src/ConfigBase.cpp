/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ConfigBase.h"

#include "Global.h"

ConfigBase::ConfigBase(const wxString & appName)
{
    config = new wxConfig(appName);

    // If there isn't a setting, writes a new one with default values
    if (!config->Exists(CONFIG_GENERAL_GROUP))
        setDefaultConfig();
}

ConfigBase::~ConfigBase()
{
    delete config;
}

void ConfigBase::setDefaultConfig()
{
    setLastOpenDir(DEFAULT_VALUE_LastOpenDir);

    setToolExecutable(DEFAULT_VALUE_ToolExecutable);
    setKeepTimestamp(DEFAULT_VALUE_KeepTimestamp);
    setDeleteBackup(DEFAULT_VALUE_DeleteBackup);
}

void ConfigBase::setConfigFlush()
{
    config->Flush();
}

wxString ConfigBase::getStringToolOptions()
{
    wxString toolOptions;

    if (getKeepTimestamp())
        toolOptions.append(_T("-t "));

    if (getDeleteBackup())
        toolOptions.append(_T("-nb "));

    toolOptions.Trim();
    return toolOptions;
}

// Gets...

wxString ConfigBase::getLastOpenDir()
{
    wxString value = wxEmptyString;
    config->Read(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, &value);
    return value;
}

wxString ConfigBase::getToolExecutable()
{
    wxString value = wxEmptyString;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, &value);
    return value;
}

bool ConfigBase::getKeepTimestamp()
{
    bool value;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_KeepTimestamp, &value);
    return value;
}

bool ConfigBase::getDeleteBackup()
{
    bool value;
    config->Read(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteBackup, &value);
    return value;
}

// Sets...

void ConfigBase::setLastOpenDir(wxString value)
{
    config->Write(CONFIG_SYSTEM_GROUP + CONFIG_STR_LastOpenDir, value);
}

void ConfigBase::setToolExecutable(wxString value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_ToolExecutable, value);
}

void ConfigBase::setKeepTimestamp(bool value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_KeepTimestamp, value);
}

void ConfigBase::setDeleteBackup(bool value)
{
    config->Write(CONFIG_GENERAL_GROUP + CONFIG_STR_DeleteBackup, value);
}
