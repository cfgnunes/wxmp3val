/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMMAIN_H
#define FRMMAIN_H

#include "ConfigBase.h"
#include "FileInfo.h"

//(*Headers(frmMain)
#include <wx/toolbar.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/timer.h>
//*)

class frmMain : public wxFrame {
public:
    frmMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmMain();
    void setFilesCmdLine(const wxArrayString& filenames);

    //(*Declarations(frmMain)
    wxToolBarToolBase* ToolBarItem5;
    wxMenuItem* MenuItem12;
    wxStatusBar* g_mainStatusBar;
    wxToolBarToolBase* ToolBarItem6;
    wxListCtrl* g_lstFiles;
    wxMenuItem* MenuItem15;
    wxTimer Timer1;
    wxToolBarToolBase* ToolBarItem7;
    wxToolBarToolBase* ToolBarItem2;
    wxToolBarToolBase* ToolBarItem4;
    wxToolBar* g_mainToolBar;
    wxToolBarToolBase* ToolBarItem1;
    wxMenu g_mainMenu;
    wxToolBarToolBase* ToolBarItem3;
    wxMenuItem* MenuItem13;
    wxToolBarToolBase* ToolBarItem8;
    wxMenuBar* g_mainMenuBar;
    wxMenuItem* MenuItem14;
    //*)

protected:
    //(*Identifiers(frmMain)
    static const long ID_LISTCTRL1;
    static const long ID_MENUITEM14;
    static const long ID_MENUITEM2;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM3;
    static const long ID_MENUITEM4;
    static const long ID_MENUITEM6;
    static const long ID_MENUITEM7;
    static const long ID_MENUITEM8;
    static const long ID_MENUITEM10;
    static const long ID_MENUITEM11;
    static const long ID_MENUITEM9;
    static const long ID_STATUSBAR1;
    static const long ID_TOOLBARITEM8;
    static const long ID_TOOLBARITEM1;
    static const long ID_TOOLBARITEM2;
    static const long ID_TOOLBARITEM3;
    static const long ID_TOOLBARITEM4;
    static const long ID_TOOLBARITEM5;
    static const long ID_TOOLBARITEM6;
    static const long ID_TOOLBARITEM7;
    static const long ID_TOOLBAR1;
    static const long ID_MENUITEM15;
    static const long ID_MENUITEM5;
    static const long ID_MENUITEM12;
    static const long ID_MENUITEM13;
    static const long ID_TIMER1;
    //*)

private:
    //(*Handlers(frmMain)
    void mnuAddFiles(wxCommandEvent& event);
    void mnuExit(wxCommandEvent& event);
    void mnuClearList(wxCommandEvent& event);
    void mnuRemoveFiles(wxCommandEvent& event);
    void OnlstFilesItemRClick(wxListEvent& event);
    void mnuAbout(wxCommandEvent& event);
    void mnuWebsite(wxCommandEvent& event);
    void mnuToolWebsite(wxCommandEvent& event);
    void mnuSettings(wxCommandEvent& event);
    void mnuScan(wxCommandEvent& event);
    void mnuFix(wxCommandEvent& event);
    void mnuAddDirectory(wxCommandEvent& event);
    void OnlstFilesDeleteItem(wxListEvent& event);
    void OnTimer1Trigger(wxTimerEvent& event);
    void OnlstFilesInsertItem(wxListEvent& event);
    void OnlstFilesKeyDown(wxListEvent& event);
    //*)

    void updateControls();
    void loadResources();
    ConfigBase *mp_configBase;
    ArrayOfFiles *mp_lstFilesData;
    wxString m_exeTool;
    wxArrayString m_exeInputString;
    wxArrayString m_exeInputErrorString;

    DECLARE_EVENT_TABLE()
};

#endif // FRMMAIN_H
