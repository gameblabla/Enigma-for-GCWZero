/*
 * Copyright (C) 2002,2003,2004,2005,2006 Daniel Heck
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#ifndef GUI_OPTIONSMENU_HH_INCLUDED
#define GUI_OPTIONSMENU_HH_INCLUDED

#include "gui/Menu.hh"
#include "gui/TextField.hh"

namespace enigma { namespace gui {
    class VideoModeButton;
    
/* -------------------- OptionsMenu -------------------- */

    class OptionsMenu : public Menu {
    public:
        OptionsMenu(ecl::Surface *background_);
        ~OptionsMenu();
        virtual void quit();

    private:
        // ActionListener interface.
        bool on_event (const SDL_Event &e);
        void on_action(gui::Widget *w);
        
        // Menu interface.
        void draw_background(ecl::GC &gc);
        void tick(double dtime) {}

        // Page structure.
        //senquack - added numerous controls specific to GCW port, removed PATHS and CONFIG screens
//        enum OptionsPage { OPTIONS_MAIN, OPTIONS_VIDEO, OPTIONS_AUDIO,
//                           OPTIONS_CONFIG, OPTIONS_PATHS };
        enum OptionsPage { OPTIONS_MAIN, OPTIONS_CONTROLS, OPTIONS_AUDIO, OPTIONS_DEFAULTS };
        void open_page(OptionsPage new_page);
        void close_page();

        // Variables.
        VList *pagesVList;
        HList *commandHList;
        VList *optionsVList;
        //senquack - got rid of language button (useless on GCW's firmware lacking LOCALE)
//        gui::Widget *back, *language;
        gui::Widget *back;

        //senquack - added new "load control defaults" button
        gui::Widget *control_defaults;

        //senquack - added button to recalibrate gsensor:
        gui::Widget *but_recalibrate_gsensor;

        gui::StaticTextButton *but_main_options;
        //senquack - added numerous options specific to GCW port:
//        gui::StaticTextButton *but_video_options;
        gui::StaticTextButton *but_controls_options;

        gui::StaticTextButton *but_audio_options;

        //senquack - added new "defaults" page to options
        gui::StaticTextButton *but_defaults_options;

        //senquack - removed PATHS part of option, as well as others:
//        gui::StaticTextButton *but_config_options;
//        gui::StaticTextButton *but_paths_options;
//        gui::BoolOptionButton *fullscreen;
//        gui::VideoModeButton *videomode;
//        gui::TextField *userNameTF;
//        gui::TextField *userPathTF;
//        gui::TextField *userImagePathTF;
//        gui::TextField *menuMusicTF;
        ecl::Surface *background;
        std::string  previous_caption;
    };

/* -------------------- Options Buttons -------------------- */

    //senquack
//    class FullscreenButton : public BoolOptionButton {
//    public:
//        FullscreenButton(ActionListener *al = 0);
//    };
//
//
//    class VideoModeButton : public ValueButton {
//        int get_value() const;
//        void set_value(int value);
//        std::string get_text(int value) const;
//    public:
//        VideoModeButton();
//        void reinit();
//    };

    class StereoButton : public ValueButton {
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
    public:
        StereoButton();
    };


    class SoundSetButton : public ValueButton {
    public:
        SoundSetButton();
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
    };

    class MenuMusicButton : public ValueButton {
    public:
        MenuMusicButton();
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
    };
    
    //senquack - got rid of language button (useless on GCW's firmware lacking LOCALE)
//    class LanguageButton : public ValueButton {
//        int get_value() const;
//        void set_value(int value);
//        std::string get_text(int value) const;
//        bool inInit;
//        ActionListener *myListener;
//    public:
//        // second user action listener: first one is misused by ValueButton 
//        LanguageButton (ActionListener *al = 0);        
//    };

    //senquack - added button to recalibrate gsensor:
    class GsensorCalibrateButton : public ValueButton {
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
        bool inInit;
        ActionListener *myListener;
    public:
        // second user action listener: first one is misused by ValueButton 
        GsensorCalibrateButton (ActionListener *al = 0);        
    };

     //senquack - added new "load controls defaults" button
    class ControlDefaultsButton : public ValueButton {
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
        bool inInit;
        ActionListener *myListener;
    public:
        // second user action listener: first one is misused by ValueButton 
        ControlDefaultsButton (ActionListener *al = 0);        
    };

    class GammaButton : public ValueButton {
        int get_value() const;
        void set_value(int value);
        std::string get_text(int value) const;
    public:
        GammaButton();        
    };
    
/* -------------------- Functions -------------------- */

    void ShowOptionsMenu(ecl::Surface *background);

}} // namespace enigma::gui
#endif
