/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include "FileInfo.h"
#include "ConfigBase.h"
#include "Global.h"

#include <wx/listctrl.h>

enum {
    TOOL_SCAN = 0,
    TOOL_FIX = 1,
};

class Progress {
public:
    Progress(wxWindow* parent, ConfigBase* configBase, wxListCtrl* listFiles, ArrayOfFiles* lstFilesData, int workType);
    virtual ~Progress();
    void execute();

private:
    void processFile(int fileIterator);
    void processOutputString(int fileIterator);
    wxWindow* mp_parent;
    ConfigBase* mp_configBase;
    wxListCtrl* mp_listFiles;
    ArrayOfFiles* mp_lstFilesData;
    int m_workType;
    wxArrayString m_inputString;
};

#endif // PROGRESS_H
