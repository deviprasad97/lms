#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "library.h"
#include "controller.h"
#include "nim.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_new_game_click();        // Create a new game
        void on_button1_click();         // Select one stick from pile
        void on_button2_click();         // Select two sticks from pile
        void on_button3_click();         // Select three sticks from pile

        void on_computer_player_click(); // Enable / disable computer player
        void on_about_click();           // Display About dialog
        void on_quit_click();
        void on_List();
        void on_Add();           // Exit the game
        void on_checkin();
        void on_checkout();
        void on_addpat();
        void on_listpat();
        void on_help();
        void on_easter();

/*
string Publication::to_str_target_age(){
  return target_age.to_string();
}
string Publication::to_str_genre(){
  return genre.to_string();
}
string Publication::to_str_media(){
  return media.to_string();
}
string Publication::to_str_isbn(){
  return isbn;
}
*/

        //Extreme bonus
        void on_button_quit();
        class ModelColumns : public Gtk::TreeModel::ColumnRecord
        {
            public:
            ModelColumns()
            { add(m_col_id); add(m_col_name); add(m_col_author); add(m_col_copyright); add(m_col_age), add(m_col_genre), add(m_col_media), add(m_col_isbn), add(m_col_ava), add(m_col_percentage);}

            Gtk::TreeModelColumn<unsigned int> m_col_id;
            Gtk::TreeModelColumn<Glib::ustring> m_col_name;
            Gtk::TreeModelColumn<Glib::ustring> m_col_author;
            Gtk::TreeModelColumn<Glib::ustring> m_col_copyright;
            Gtk::TreeModelColumn<Glib::ustring> m_col_age;
            Gtk::TreeModelColumn<Glib::ustring> m_col_genre;
            Gtk::TreeModelColumn<Glib::ustring> m_col_media;
            Gtk::TreeModelColumn<Glib::ustring> m_col_isbn;
            Gtk::TreeModelColumn<Glib::ustring> m_col_ava;
            Gtk::TreeModelColumn<int> m_col_percentage;
          };

          ModelColumns m_Columns;

          //Child widgets:
          Gtk::Box m_VBox;

          Gtk::ScrolledWindow m_ScrolledWindow;
          Gtk::TreeView m_TreeView;
          Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

          Gtk::ButtonBox m_ButtonBox;
          Gtk::Button m_Button_Quit;
        //Extreme bonus



    private:
        void set_sticks();                    // Update display, robot move
        Nim *nim;
        Controller *controller;
        Library *library;
        Gtk::Label *sticks;                   // Display of sticks on game board
        Gtk::Label *msg;                      // Status message display
        Gtk::ToolButton *button1;             // Button to select 1 stick
        Gtk::Image *button1_on_image;         //   Image when active
        Gtk::Image *button1_off_image;        //   Image when inactive
        Gtk::Image *button0_on_image;         //   Image when active
        Gtk::Image *button0_off_image;        //   Image when inactive
        Gtk::Image *button4_on_image;         //   Image when active
        Gtk::Image *button4_off_image;        //   Image when inactive
        Gtk::Image *button5_on_image;         //   Image when active
        Gtk::Image *button5_off_image;        //   Image when inactive
        Gtk::ToolButton *button2;             // Button to select 2 sticks
        Gtk::Image *button2_on_image;
        Gtk::Image *button2_off_image;
        Gtk::ToolButton *button3;
        Gtk::ToolButton *button4;
        Gtk::ToolButton *button5;
        Gtk::ToolButton *button0;         // Button to select 3 sticks
        Gtk::Image *button3_on_image;
        Gtk::Image *button3_off_image;
        Gtk::ToggleToolButton *computer_player;  // Button to enable robot
};
#endif
