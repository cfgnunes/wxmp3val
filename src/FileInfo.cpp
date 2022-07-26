/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileInfo.h"
#include "Constants.h"

FileInfo::FileInfo(const wxString &fileName)
    : m_fileName(fileName), m_stateMP3(STATE_MP3_UNKNOWN) {
}

FileInfo::~FileInfo() {
}

wxFileName FileInfo::getFileName() const {
    return m_fileName;
}

int FileInfo::getStateMP3() const {
    return m_stateMP3;
}

void FileInfo::setStateMP3(int state) {
    m_stateMP3 = state;
}
