/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileData.hpp"
#include "Constants.hpp"

FileData::FileData(const wxString &fileName)
    : m_fileName(fileName), m_stateMP3(STATE_MP3_UNKNOWN) {
}

FileData::~FileData() {
}

wxFileName FileData::getFileName() const {
    return m_fileName;
}

int FileData::getStateMP3() const {
    return m_stateMP3;
}

void FileData::setStateMP3(int state) {
    m_stateMP3 = state;
}
