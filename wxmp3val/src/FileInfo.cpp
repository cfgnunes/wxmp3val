/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "FileInfo.h"

// LIST (start)
#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfFiles);
// LIST (end)

FileInfo::FileInfo(const wxString& fileName) : fileName(fileName)
{

}

FileInfo::~FileInfo()
{
    //dtor
}

//sets..


//gets..

wxFileName FileInfo::getFileName()
{
    return fileName;
}
