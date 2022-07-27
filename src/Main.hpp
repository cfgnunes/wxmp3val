/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <wx/app.h>

class Main : public wxApp {
  public:
    virtual bool OnInit();

  private:
    wxLocale *mp_locale;
    wxArrayString *mp_filesCmdLine;
};

#endif // MAIN_HPP
