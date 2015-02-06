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

class frmMain : public wxFrame
{
public:

    frmMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmMain();

    //(*Declarations(frmMain)
    wxToolBarToolBase* ToolBarItem5;
    wxStatusBar* StatusBar1;
    wxMenuItem* MenuItem12;
    wxToolBarToolBase* ToolBarItem6;
    wxListCtrl* lstFiles;
    wxMenuItem* MenuItem15;
    wxTimer Timer1;
    wxToolBarToolBase* ToolBarItem7;
    wxToolBarToolBase* ToolBarItem2;
    wxToolBar* ToolBar1;
    wxToolBarToolBase* ToolBarItem4;
    wxToolBarToolBase* ToolBarItem1;
    wxMenuBar* MenuBar1;
    wxToolBarToolBase* ToolBarItem3;
    wxMenuItem* MenuItem13;
    wxToolBarToolBase* ToolBarItem8;
    wxMenu Menu1;
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
    ConfigBase *configBase;
    ArrayOfFiles *lstFilesData;
    wxString exeTool;
    wxArrayString exeInputString;
    wxArrayString exeInputErrorString;

    DECLARE_EVENT_TABLE()
};

#endif
