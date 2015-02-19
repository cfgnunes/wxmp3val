/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileInfo.h"

FileInfo::FileInfo(const wxString& fileName) : m_fileName(fileName) {
}

FileInfo::~FileInfo() {
}

wxFileName FileInfo::getFileName() const {
    return m_fileName;
}
