/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMABOUT_H
#define FRMABOUT_H

//(*Headers(frmAbout)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/hyperlink.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)

class frmAbout : public wxDialog
{
public:

    frmAbout(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmAbout();

    //(*Declarations(frmAbout)
    wxStaticLine* StaticLine2;
    wxStaticText* lblEmail;
    wxStaticText* lblAppName;
    wxStaticText* StaticText1;
    wxHyperlinkCtrl* linkEmail;
    wxStaticLine* StaticLine1;
    wxStaticText* lblVersion;
    wxStaticLine* StaticLine3;
    wxStaticText* lblWebsite;
    wxStaticText* lblAuthor;
    wxHyperlinkCtrl* linkWebsite;
    wxStaticBitmap* StaticBitmap1;
    wxButton* btnOK;
    wxHyperlinkCtrl* linkLicense;
    wxStaticBitmap* StaticBitmap2;
    //*)

protected:

    //(*Identifiers(frmAbout)
    static const long ID_STATICBITMAP1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT1;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT6;
    static const long ID_HYPERLINKCTRL2;
    static const long ID_STATICTEXT5;
    static const long ID_HYPERLINKCTRL1;
    static const long ID_STATICLINE3;
    static const long ID_STATICTEXT3;
    static const long ID_HYPERLINKCTRL3;
    static const long ID_STATICBITMAP2;
    static const long ID_STATICLINE2;
    static const long ID_BUTTON1;
    //*)

private:

    //(*Handlers(frmAbout)
    void OnbtnOKClick(wxCommandEvent& event);
    //*)
    void loadResources();

    DECLARE_EVENT_TABLE()
};

#endif
