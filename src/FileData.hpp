/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FILE_DATA_HPP
#define FILE_DATA_HPP

#include <wx/filename.h>
#include <wx/string.h>

class FileData {
  public:
    FileData(const wxString &fileName);
    virtual ~FileData();

    wxFileName getFileName() const;
    int getStateMP3() const;
    void setStateMP3(int state);

  private:
    wxFileName m_fileName;
    int m_stateMP3;
};

#endif // FILE_DATA_HPP
