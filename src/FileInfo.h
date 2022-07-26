/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILE_INFO_HPP
#define FILE_INFO_HPP

#include <wx/string.h>
#include <wx/filename.h>

class FileInfo {
public:
    FileInfo(const wxString &fileName);

    virtual ~FileInfo();

    wxFileName getFileName() const;

    int getStateMP3() const;

    void setStateMP3(int state);


private:
    wxFileName m_fileName;
    int m_stateMP3;
};

#endif // FILE_INFO_HPP
