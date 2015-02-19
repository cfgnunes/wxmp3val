/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString CONFIG_GROUP_SYSTEM = _T("/System/");
const wxString CONFIG_GROUP_GENERAL = _T("/General/");

// Config Strings
const wxString CONFIG_STR_AppVersion = _T("AppVersion");
const wxString CONFIG_STR_LastOpenDir = _T("LastOpenDir");

const wxString CONFIG_STR_KeepTimestamp = _T("KeepTimestamp");
const wxString CONFIG_STR_DeleteBackup = _T("DeleteBackup");

// Default Values
const wxString DEFAULT_VALUE_LastOpenDir = wxFileName::GetHomeDir();

const bool DEFAULT_VALUE_KeepTimestamp = true;
const bool DEFAULT_VALUE_DeleteBackup = true;

class ConfigBase {
public:
    ConfigBase(const wxString& appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions() const;

    // Gets...
    wxString getAppVersion() const;
    wxString getLastOpenDir() const;
    bool getKeepTimestamp() const;
    bool getDeleteBackup() const;

    // Sets...
    void setAppVersion(wxString value);
    void setLastOpenDir(wxString value);
    void setKeepTimestamp(bool value);
    void setDeleteBackup(bool value);

private:
    wxConfig *mp_config;
};

#endif // CONFIGBASE_H
