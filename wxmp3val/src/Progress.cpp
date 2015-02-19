/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "Progress.h"
#include "Constants.h"

#include <wx/filename.h>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>

Progress::Progress(wxWindow *parent, ConfigBase* configBase, FileListManager *fileListManager, int workType)
: mp_parent(parent), mp_configBase(configBase), mp_fileListManager(fileListManager), m_workType(workType) {
}

Progress::~Progress() {
}

void Progress::execute() {
    unsigned long int maxValue = mp_fileListManager->size();
    bool cont = true;

    wxProgressDialog dialog(_("Progress"), _("Wait..."), maxValue, mp_parent, wxPD_CAN_ABORT | wxPD_APP_MODAL | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME);
    dialog.Update(0, wxString::Format(_("Processed %lu files of %lu."), (unsigned long int) 0, maxValue));
    for (unsigned long int i = 0; i < maxValue; i++) {
        processFile(i);

        cont = dialog.Update(i + 1, wxString::Format(_("Processed %lu files of %lu."), i + 1, maxValue));
        if (!cont) {
            if (wxMessageBox(_("Do you want to stop process now?"), APP_NAME, wxYES_NO | wxICON_QUESTION) == wxYES)
                break;
            dialog.Resume();
        }
    }
}

void Progress::processFile(unsigned long int fileIterator) {
    wxString fullCommand = APP_TOOL_EXECUTABLE;
    FileInfo& fileInfo = mp_fileListManager->getItem(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();

    if (m_workType == TOOL_FIX)
        fullCommand.append(_T(" -f ") + mp_configBase->getStringToolOptions());

    // Execute external application
    wxExecute(fullCommand + _T(" \"") + filenameInput.GetFullPath() + _T("\""), m_inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);

    // Process output string and updates the list
    processOutputString(fileIterator);
}

void Progress::processOutputString(unsigned long int fileIterator) {
    wxString tempString;
    int flagState = 0; //0-OK, 1-PROBLEM, 2-FIXED
    int warningCount = 0;

    if (!m_inputString.IsEmpty()) {
        for (unsigned long int i = 0; i < m_inputString.GetCount(); i++) {
            tempString = m_inputString.Item(i);

            if (tempString.Find(_T("MPEG frames")) != wxNOT_FOUND) {
                // Cut the string for: "MPEG frames..."
                tempString = tempString.Right(tempString.Len() - tempString.Find(_T("MPEG frames")));

                // Update Version column
                if (tempString.AfterFirst('(').BeforeFirst(')').Find(_T("MPEG")) != wxNOT_FOUND)
                    mp_fileListManager->getOwner().SetItem(fileIterator, 2, tempString.AfterFirst('(').BeforeFirst(')'));

                // Update Tags column
                mp_fileListManager->getOwner().SetItem(fileIterator, 3, tempString.AfterFirst(',').BeforeFirst(','));

                // Update CBR column
                if (tempString.AfterFirst(',').AfterFirst(',').Find(_T("CBR")) != wxNOT_FOUND)
                    mp_fileListManager->getOwner().SetItem(fileIterator, 4, _T("CBR"));
                else
                    mp_fileListManager->getOwner().SetItem(fileIterator, 4, _T("VBR"));
            }

            if (tempString.StartsWith(_T("WARNING: ")))
                warningCount++;

            if (tempString.Find(_T("tags in the file")) != wxNOT_FOUND)
                warningCount--;

            if (tempString.StartsWith(_T("FIXED: ")))
                flagState = 2;
        }

        if (flagState == 0 && warningCount > 0)
            flagState = 1;

        // Update State column
        switch (flagState) {
            case 0:
                mp_fileListManager->getOwner().SetItem(fileIterator, 5, _("OK"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxBLACK);
                break;
            case 1:
                mp_fileListManager->getOwner().SetItem(fileIterator, 5, _("PROBLEM"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxRED);
                break;
            case 2:
                mp_fileListManager->getOwner().SetItem(fileIterator, 5, _("FIXED"));
                mp_fileListManager->getOwner().SetItemTextColour(fileIterator, *wxBLACK);
                break;
        }

        // Clear the output
        m_inputString.Clear();
    }
}
