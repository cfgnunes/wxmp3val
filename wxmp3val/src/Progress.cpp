/*
 * This file is part of the wxMP3gain and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#include "Progress.h"

#include <wx/filename.h>
#include <wx/progdlg.h>
#include <wx/msgdlg.h>

Progress::Progress(wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, ArrayOfFiles* lstFilesData, int workType)
: parent(parent), configBase(configBase), listFiles(listFiles), lstFilesData(lstFilesData), workType(workType)
{
    //ctor
}

Progress::~Progress()
{
    //dtor
}

void Progress::Execute()
{
    int maxValue = listFiles->GetItemCount();
    bool cont = true;

    wxProgressDialog dialog(wxT("Working progress"), wxT("Wait..."), maxValue, parent, wxPD_CAN_ABORT | wxPD_APP_MODAL | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME);
    dialog.Update(0, wxString::Format(wxT("Processed 0 files of %i."), maxValue));
    for (int i = 0; i < maxValue; i++)
    {
        ProcessFile(i);

        cont = dialog.Update(i + 1, wxString::Format(wxT("Processed %i files of %i."), i + 1, maxValue));
        if (!cont)
        {
            if (wxMessageBox(wxT("Do you want to stop process now?"), wxT("Question"), wxYES_NO | wxICON_QUESTION) == wxYES)
                break;
            dialog.Resume();
        }
    }
}

void Progress::ProcessFile(int fileIterator)
{
    wxString fullCommand = configBase->getToolExecutable();
    FileInfo& fileInfo = lstFilesData->Item(fileIterator);
    wxFileName filenameInput = fileInfo.getFileName();;

    if (workType == TOOL_FIX)
        fullCommand.append(wxT(" -f ") + configBase->getStringToolOptions());

    // Execute external application
    wxExecute(fullCommand + wxT(" \"") + filenameInput.GetFullPath() + wxT("\""), inputString, wxEXEC_NODISABLE | wxEXEC_SYNC);

    // Process output string and updates the list
    ProcessOutputString(fileIterator);
}

void Progress::ProcessOutputString(int fileIterator)
{
    wxString tempString;
    int flagState = 0; //0-OK, 1-PROBLEM, 2-FIXED
    int warningCount = 0;

    if (!inputString.IsEmpty())
    {
        for (unsigned int i = 0; i < inputString.GetCount(); i++)
        {
            tempString = inputString.Item(i);

            if (tempString.Find(wxT("MPEG frames")) != wxNOT_FOUND)
            {
                // Cut the string for: "MPEG frames..."
                tempString = tempString.Right(tempString.Len() - tempString.Find(wxT("MPEG frames")));

                // Update Version column
                if (tempString.AfterFirst('(').BeforeFirst(')').Find(wxT("MPEG")) != wxNOT_FOUND)
                    listFiles->SetItem(fileIterator, 1, tempString.AfterFirst('(').BeforeFirst(')'));

                // Update Tags column
                listFiles->SetItem(fileIterator, 2, tempString.AfterFirst(',').BeforeFirst(','));

                // Update CBR column
                if (tempString.AfterFirst(',').AfterFirst(',').Find(wxT("CBR")) != wxNOT_FOUND)
                    listFiles->SetItem(fileIterator, 3, wxT("CBR"));
                else
                    listFiles->SetItem(fileIterator, 3, wxT("VBR"));
            }

            if (tempString.StartsWith(wxT("WARNING: ")))
                warningCount++;

            if (tempString.Find(wxT("tags in the file")) != wxNOT_FOUND)
                warningCount--;

            if (tempString.StartsWith(wxT("FIXED: ")))
                flagState = 2;
        }

        if (flagState == 0 && warningCount > 0)
            flagState = 1;

        // Update State column
        switch (flagState)
        {
        case 0:
            listFiles->SetItem(fileIterator, 4, wxT("OK"));
            listFiles->SetItemTextColour(fileIterator, *wxBLACK);
            break;
        case 1:
            listFiles->SetItem(fileIterator, 4, wxT("PROBLEM"));
            listFiles->SetItemTextColour(fileIterator, *wxRED);
            break;
        case 2:
            listFiles->SetItem(fileIterator, 4, wxT("FIXED"));
            listFiles->SetItemTextColour(fileIterator, *wxBLACK);
            break;
        }

        // Clear the output
        inputString.Clear();
    }
}
