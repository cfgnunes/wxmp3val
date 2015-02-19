/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include "FileInfo.h"
#include "ConfigBase.h"
#include "Constants.h"
#include "FileListManager.h"

#include <wx/window.h>
#include <wx/arrstr.h>

enum {
    TOOL_SCAN = 0,
    TOOL_FIX = 1,
};

class Progress {
public:
    Progress(wxWindow *parent, ConfigBase* configBase, FileListManager *fileListManager, int workType);
    virtual ~Progress();
    void execute();

private:
    void processFile(unsigned long int fileIterator);
    void processOutputString(unsigned long int fileIterator);

    wxWindow *mp_parent;
    ConfigBase *mp_configBase;
    FileListManager *mp_fileListManager;
    int m_workType;
    wxArrayString m_inputString;
};

#endif // PROGRESS_H
