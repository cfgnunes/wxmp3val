/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef CONFIGBASE_H
#define CONFIGBASE_H

#include <wx/string.h>
#include <wx/config.h>

// Config Group Strings
const wxString	CONFIG_SYSTEM_GROUP				= wxT("/System/");
const wxString	CONFIG_GENERAL_GROUP			= wxT("/General/");

// Config Strings
const wxString	CONFIG_STR_LastOpenDir			= wxT("LastOpenDir");

const wxString	CONFIG_STR_ToolExecutable	    = wxT("ToolExecutable");
const wxString	CONFIG_STR_KeepTimestamp		= wxT("KeepTimestamp");
const wxString	CONFIG_STR_DeleteBackup			= wxT("DeleteBackup");

// Default Values
const wxString	DEFAULT_VALUE_LastOpenDir		= wxEmptyString;

const wxString	DEFAULT_VALUE_ToolExecutable	= wxT("mp3val");
const bool		DEFAULT_VALUE_KeepTimestamp		= true;
const bool		DEFAULT_VALUE_DeleteBackup  	= true;

class ConfigBase
{
public:
    ConfigBase(const wxString & appName = wxEmptyString);
    ~ConfigBase();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions();

    //gets...
    wxString getLastOpenDir();
    wxString getToolExecutable();
    bool getKeepTimestamp();
    bool getDeleteBackup();

    //sets...
    void setLastOpenDir(wxString value);
    void setToolExecutable(wxString value);
    void setKeepTimestamp(bool value);
    void setDeleteBackup(bool value);

private:
    wxConfig *config;
};

#endif
