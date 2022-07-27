/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ListCtrlManager.hpp"
#include "Constants.hpp"

#include <wx/dir.h>
#include <wx/tokenzr.h>

ListCtrlManager::ListCtrlManager(wxListCtrl *owner)
    : mp_owner(owner) {
    mp_lstFilesData = new std::list<FileData>();
}

ListCtrlManager::~ListCtrlManager() {
    delete mp_lstFilesData;
}

void ListCtrlManager::insertFilesAndDir(const wxArrayString &filenames) {
    wxArrayString files;

    // Check if is a directory or a file
    for (unsigned long int n = 0; n < filenames.GetCount(); n++) {
        wxString filename = filenames[n];
        if (wxFileName::DirExists(filename))
            insertDir(filename);
        else
            files.Add(filename);
    }
    insertFiles(files);
}

void ListCtrlManager::insertFiles(const wxArrayString &filenames) {
    unsigned long int nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for (unsigned long int n = 0; n < nFiles; n++) {
        wxFileName file(filenames[n]);

        if (checkValidExtension(file)) {
            // Don't insert repeated filenames
            bool repeated = false;

            unsigned long int i = 0;
            for (std::list<FileData>::iterator fileData = mp_lstFilesData->begin();
                 fileData != mp_lstFilesData->end(); fileData++, i++) {
                wxFileName filenameInput = (*fileData).getFileName();
                if (filenameInput.GetFullPath() == filenames[n]) {
                    repeated = true;
                }
            }
            if (!repeated) {
                mp_owner->InsertItem(mp_owner->GetItemCount(), file.GetFullName());
                mp_owner->SetItem(i, 1, file.GetPath());
                mp_lstFilesData->push_back(FileData(filenames[n]));
            }
        }
    }
}

void ListCtrlManager::insertDir(const wxString &dirname) {
    wxArrayString files;
    wxDir::GetAllFiles(dirname, &files);

    insertFiles(files);
}

bool ListCtrlManager::checkValidExtension(const wxFileName &file) const {
    wxStringTokenizer strToken(APP_OPEN_EXT, _T(";"));
    while (strToken.HasMoreTokens()) {
        wxString token = strToken.GetNextToken();

        if (file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}

void ListCtrlManager::deleteItem(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_lstFilesData->begin();
    std::advance(fileData, index);
    mp_lstFilesData->erase(fileData);
}

void ListCtrlManager::clear() {
    mp_owner->DeleteAllItems();
    mp_lstFilesData->clear();
}

long unsigned int ListCtrlManager::size() {
    return mp_lstFilesData->size();
}

FileData &ListCtrlManager::getItem(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_lstFilesData->begin();
    std::advance(fileData, index);
    return *fileData;
}

wxListCtrl &ListCtrlManager::getOwner() {
    return *mp_owner;
}