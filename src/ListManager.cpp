/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "ListManager.hpp"
#include "Constants.hpp"

#include <wx/dir.h>
#include <wx/tokenzr.h>

ListManager::ListManager(wxListCtrl *listCtrl) : mp_listCtrl(listCtrl) {
    mp_filesData = new std::list<FileData>();
}

ListManager::~ListManager() {
    delete mp_filesData;
}

void ListManager::insertFilesAndDir(const wxArrayString &filenames) {
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

void ListManager::insertFiles(const wxArrayString &filenames) {
    unsigned long int nFiles = filenames.GetCount();

    // Add files in wxListCtrl
    for (unsigned long int n = 0; n < nFiles; n++) {
        wxFileName file(filenames[n]);

        if (checkValidExtension(file)) {
            // Don't insert repeated filenames
            bool repeated = false;

            unsigned long int i = 0;
            std::list<FileData>::iterator fileData = mp_filesData->begin();
            for (; fileData != mp_filesData->end(); fileData++, i++) {
                wxFileName filenameInput = (*fileData).getFileName();
                if (filenameInput.GetFullPath() == filenames[n]) {
                    repeated = true;
                }
            }
            if (!repeated) {
                mp_listCtrl->InsertItem(mp_listCtrl->GetItemCount(), file.GetFullName());
                mp_listCtrl->SetItem(i, 1, file.GetPath());
                mp_filesData->push_back(FileData(filenames[n]));
            }
        }
    }
}

void ListManager::insertDir(const wxString &dirname) {
    wxArrayString files;
    wxDir::GetAllFiles(dirname, &files);

    insertFiles(files);
}

bool ListManager::checkValidExtension(const wxFileName &file) const {
    wxStringTokenizer strToken(APP_OPEN_EXT, _T(";"));
    while (strToken.HasMoreTokens()) {
        wxString token = strToken.GetNextToken();

        if (file.GetExt().CmpNoCase(token) == 0)
            return true;
    }
    return false;
}

void ListManager::deleteItem(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_filesData->begin();
    std::advance(fileData, index);
    mp_filesData->erase(fileData);
}

void ListManager::clear() {
    mp_listCtrl->DeleteAllItems();
    mp_filesData->clear();
}

long unsigned int ListManager::size() {
    return mp_filesData->size();
}

FileData &ListManager::getFileData(unsigned long int index) {
    std::list<FileData>::iterator fileData = mp_filesData->begin();
    std::advance(fileData, index);
    return *fileData;
}

wxListCtrl &ListManager::getListCtrl() {
    return *mp_listCtrl;
}
