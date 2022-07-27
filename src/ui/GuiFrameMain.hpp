/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUI_FRAME_MAIN_HPP
#define GUI_FRAME_MAIN_HPP

#include "../AppSettings.hpp"
#include "../DndFile.hpp"
#include "../FileListManager.hpp"
#include "Gui.h"

class GuiFrameMain : public FrameMain {
  public:
    GuiFrameMain(wxWindow *parent);
    virtual ~GuiFrameMain();

    void setFilesCmdLine(const wxArrayString &filenames);

  protected:
    void OnlstFilesDeleteItem(wxListEvent &event);
    void OnlstFilesInsertItem(wxListEvent &event);
    void OnlstFilesItemSelect(wxListEvent &event);
    void OnlstFilesItemRClick(wxListEvent &event);
    void OnlstFilesKeyDown(wxListEvent &event);
    void btnProcessStop(wxCommandEvent &event);
    void mnuAddDirectory(wxCommandEvent &event);
    void mnuAddFiles(wxCommandEvent &event);
    void mnuExit(wxCommandEvent &event);
    void mnuRemoveFiles(wxCommandEvent &event);
    void mnuClearList(wxCommandEvent &event);
    void mnuSettings(wxCommandEvent &event);
    void mnuScan(wxCommandEvent &event);
    void mnuRepair(wxCommandEvent &event);
    void mnuWebsite(wxCommandEvent &event);
    void mnuToolWebsite(wxCommandEvent &event);
    void mnuAbout(wxCommandEvent &event);
    void OnTimer1Trigger(wxTimerEvent &event);

  private:
    void updateControls();
    void loadResources();
    void processExecute();
    void processFile(unsigned long int fileIterator);
    int processOutputString(unsigned long int fileIterator);

    AppSettings *mp_appSettings;
    FileListManager *mp_fileListManager;
    DndFile *mp_dndFile;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;
    int m_processType;
    bool m_processRunning;
};

#endif // GUI_FRAME_MAIN_HPP
