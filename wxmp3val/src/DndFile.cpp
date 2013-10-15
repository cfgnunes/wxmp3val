/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "DndFile.h"

DndFile::DndFile(wxListCtrl *owner)
{
    m_owner = owner;
}

DndFile::~DndFile()
{
    //dtor
}

bool DndFile::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
    wxArrayString files;

    // Check if is a directory or a file
    for ( size_t n = 0; n < filenames.GetCount(); n++ )
    {
        if(wxFileName::DirExists(filenames[n]))
            InsertFileListDir(m_owner, filenames[n]);
        else
            files.Add(filenames[n]);
    }
    InsertFileList(m_owner, files);

    return true;
}

void DndFile::InsertFileList(wxListCtrl* m_owner, const wxArrayString& filenames)
{
    wxFileName file;
    size_t nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for ( size_t n = 0; n < nFiles; n++ )
    {
        file.SetFullName(filenames[n]);

        if(CheckValidExtension(file))
        {
            // Don't insert repeated filenames
            bool repeated = false;
            for (int i=0; i<m_owner->GetItemCount(); i++)
            {
                if(m_owner->GetItemText(i) == filenames[n])
                {
                    repeated = true;
                }
            }
            if(!repeated)
            {
                m_owner->InsertItem(n, filenames[n]);

                // Workaround to force wxListCtrl update insert event (on Windows)
                if(m_owner->GetItemCount() == 1)
                {
                    m_owner->InsertItem(1, wxT(""));
                    m_owner->DeleteItem(1);
                }
            }
        }
    }
}

void DndFile::InsertFileListDir(wxListCtrl* m_owner, const wxString& dirname)
{
    wxArrayString files;
    wxDir::GetAllFiles (dirname, &files);

    InsertFileList(m_owner, files);
}

bool DndFile::CheckValidExtension(const wxFileName& file)
{
    wxStringTokenizer strToken(APP_OPEN_EXT, wxT(";"));
    while ( strToken.HasMoreTokens() )
    {
        wxString token = strToken.GetNextToken();

        if(file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}
