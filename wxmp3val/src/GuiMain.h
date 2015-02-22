/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUIMAIN_H
#define GUIMAIN_H

#include "Gui.h"
#include "ConfigBase.h"
#include "FileListManager.h"
#include "DndFile.h"

class GuiMain : public Main {
public:
    GuiMain(wxWindow* parent);
    virtual ~GuiMain();
    void setFilesCmdLine(const wxArrayString& filenames);

protected:
    void OnlstFilesDeleteItem(wxListEvent& event);
    void OnlstFilesInsertItem(wxListEvent& event);
    void OnlstFilesItemSelect(wxListEvent& event);
    void OnlstFilesItemRClick(wxListEvent& event);
    void OnlstFilesKeyDown(wxListEvent& event);
    void btnProcessStop(wxCommandEvent& event);
    void mnuAddDirectory(wxCommandEvent& event);
    void mnuAddFiles(wxCommandEvent& event);
    void mnuExit(wxCommandEvent& event);
    void mnuRemoveFiles(wxCommandEvent& event);
    void mnuClearList(wxCommandEvent& event);
    void mnuSettings(wxCommandEvent& event);
    void mnuScan(wxCommandEvent& event);
    void mnuRepair(wxCommandEvent& event);
    void mnuWebsite(wxCommandEvent& event);
    void mnuToolWebsite(wxCommandEvent& event);
    void mnuAbout(wxCommandEvent& event);
    void OnTimer1Trigger(wxTimerEvent& event);

private:
    void updateControls();
    void loadResources();
    void processExecute();
    void processFile(unsigned long int fileIterator);
    int processOutputString(unsigned long int fileIterator);

    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    DndFile *mp_dndFile;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;
    int m_processType;
    bool m_processRunning;
};

#endif // GUIMAIN_H
