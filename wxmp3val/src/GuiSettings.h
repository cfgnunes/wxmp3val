/*
 * This file is part of the wxMP3val and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef GUISETTINGS_H
#define GUISETTINGS_H

#include "Gui.h"
#include "ConfigBase.h"

class GuiSettings : public Settings {
public:
    GuiSettings(wxWindow* parent, ConfigBase* configBase);

protected:
    void OnbtnDefaultClick(wxCommandEvent& event);
    void OnbtnOKClick(wxCommandEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);

private:
    void updateValueControls();
    void defaultValueControls();
    void saveValuesConfig();
    void setLabelsControls();

    ConfigBase* mp_configBase;
};

#endif // GUISETTINGS_H
