/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef APP_SETTINGS_HPP
#define APP_SETTINGS_HPP

#include <wx/config.h>
#include <wx/string.h>

class AppSettings {
  public:
    AppSettings(const wxString &appName = wxEmptyString);
    ~AppSettings();

    void setDefaultConfig();
    void setConfigFlush();
    wxString getStringToolOptions() const;

    // Gets
    wxString getAppVersion() const;
    wxString getLastOpenDir() const;
    bool getDeleteBackup() const;

    // Sets
    void setAppVersion(wxString value);
    void setLastOpenDir(wxString value);
    void setDeleteBackup(bool value);

  private:
    wxConfig *mp_config;
};

#endif // APP_SETTINGS_HPP
