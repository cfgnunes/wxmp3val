/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef WXMP3VAL_H
#define WXMP3VAL_H

#include <wx/app.h>

class wxMP3valApp : public wxApp
{
public:
    virtual bool OnInit();

private:
    wxLocale *m_locale;
    wxArrayString *m_filesCmdLine;
};

#endif
