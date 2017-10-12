#include "main_window.h"
#include "library.h"
#include "controller.h"
#include <time.h>
const int NUM_SECONDS = 5;
Library lib;
Controller control(lib);
Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);





    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //     P U B L I C A T I O N
    // Create a publication menu and add to the menu bar
    Gtk::MenuItem *menuitem_pub = Gtk::manage(new Gtk::MenuItem("_Publication", true));
    menubar->append(*menuitem_pub);
    Gtk::Menu *pubmenu = Gtk::manage(new Gtk::Menu());
    menuitem_pub->set_submenu(*pubmenu);

    //     P U B L I C A T I O N
    // Create a publication menu and add to the menu bar
    Gtk::MenuItem *menuitem_pat = Gtk::manage(new Gtk::MenuItem("_Patron", true));
    menubar->append(*menuitem_pat);
    Gtk::Menu *patmenu = Gtk::manage(new Gtk::Menu());
    menuitem_pat->set_submenu(*patmenu);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_addpat = Gtk::manage(new Gtk::MenuItem("_Add Patron", true));
    menuitem_addpat->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_addpat));
    patmenu->append(*menuitem_addpat);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_listpat = Gtk::manage(new Gtk::MenuItem("_List Patron", true));
    menuitem_listpat->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_listpat));
    patmenu->append(*menuitem_listpat);


    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_list = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_List));
    pubmenu->append(*menuitem_list);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add", true));
    menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_Add));
    pubmenu->append(*menuitem_add);

    Gtk::MenuItem *menuitem_ester = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
    menuitem_ester->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_easter));
    pubmenu->append(*menuitem_ester);

    //         N E W   G A M E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_checkin = Gtk::manage(new Gtk::MenuItem("_Check in", true));
    menuitem_checkin->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_checkin));
    pubmenu->append(*menuitem_checkin);
    //         N E W   G A M E
      // Append New to the File menu
      Gtk::MenuItem *menuitem_checkout = Gtk::manage(new Gtk::MenuItem("_Check out", true));
      menuitem_checkout->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_checkout));
      pubmenu->append(*menuitem_checkout);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    Gtk::MenuItem *menuitem_help1 = Gtk::manage(new Gtk::MenuItem("Help", true));
    menuitem_help1->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_help));
    helpmenu->append(*menuitem_help1);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    button0_on_image = Gtk::manage(new Gtk::Image("new.png"));
    button0_off_image = Gtk::manage(new Gtk::Image("new.png"));
    button0 = Gtk::manage(new Gtk::ToolButton(*button0_on_image));
    button0->set_tooltip_markup("Add Publication");
    button0->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_Add));
    toolbar->append(*button0);

    //     O N E   S T I C K
    // Add a icon for taking one stick
    button1_on_image = Gtk::manage(new Gtk::Image("list.png"));
    button1_off_image = Gtk::manage(new Gtk::Image("list.png"));
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_on_image));
    button1->set_tooltip_markup("View all publication");
    button1->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_List));
    toolbar->append(*button1);

    //     T W O   S T I C K S
    // Add a icon for taking two sticks
    button2_on_image = Gtk::manage(new Gtk::Image("checkin.png"));
    button2_off_image = Gtk::manage(new Gtk::Image("checkin.png"));
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_on_image));
    button2->set_tooltip_markup("Check in a publication");
    button2->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkin));
    toolbar->append(*button2);

    //     T H R E E   S T I C K S
    // Add a icon for taking three sticks
    button3_on_image = Gtk::manage(new Gtk::Image("checkout.png"));
    button3_off_image = Gtk::manage(new Gtk::Image("checkout.png"));
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_on_image));
    button3->set_tooltip_markup("Checkout a publication");
    button3->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkout));
    toolbar->append(*button3);


    button4_on_image = Gtk::manage(new Gtk::Image("addpat.png"));
    button4_off_image = Gtk::manage(new Gtk::Image("addpat.png"));
    button4 = Gtk::manage(new Gtk::ToolButton(*button4_on_image));
    button4->set_tooltip_markup("Add a Patron");
    button4->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addpat));
    toolbar->append(*button4);

    button5_on_image = Gtk::manage(new Gtk::Image("listpat.png"));
    button5_off_image = Gtk::manage(new Gtk::Image("listpat.png"));
    button5 = Gtk::manage(new Gtk::ToolButton(*button5_on_image));
    button5->set_tooltip_markup("List all Patron(s)");
    button5->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_listpat));
    toolbar->append(*button5);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *help_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HELP));
    help_button->set_tooltip_markup("Help");
    help_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_help));
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    sep1->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep1);
    toolbar->append(*help_button);

    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    toolbar->append(*quit_button);



    //Extreme bonus
    /////////////////////////
    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    vbox->pack_start(m_ScrolledWindow);
    vbox->pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

    /*m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
    m_ButtonBox.set_border_width(5);
    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
    m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,
                &Main_window::on_button_quit) );*/

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);
    Gtk::TreeModel::Row row;
    control.execute_cmd(99);
    int i=0;
    for (int i=0; i<control.pub_size(); ++i) {
      row = *(m_refTreeModel->append());
      row[m_Columns.m_col_id] = i;
      row[m_Columns.m_col_name] = control.title_getter(i);
      row[m_Columns.m_col_author] = control.author_getter(i);
      row[m_Columns.m_col_copyright] = control.copyright_getter(i);
      row[m_Columns.m_col_age] = control.age_getter(i);
      row[m_Columns.m_col_genre] = control.genre_getter(i);
      row[m_Columns.m_col_media] = control.media_getter(i);
      row[m_Columns.m_col_isbn] = control.isbn_getter(i);
      row[m_Columns.m_col_ava] = control.ava_getter(i);
    }

    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Title", m_Columns.m_col_name);

    m_TreeView.append_column("Author", m_Columns.m_col_author);
    m_TreeView.append_column("Copyright", m_Columns.m_col_copyright);
    m_TreeView.append_column("Target Age", m_Columns.m_col_age);
    m_TreeView.append_column("Genre", m_Columns.m_col_genre);
    m_TreeView.append_column("Media", m_Columns.m_col_media);
    m_TreeView.append_column("ISBN", m_Columns.m_col_isbn);
    m_TreeView.append_column("Availability", m_Columns.m_col_ava);
    show_all_children();

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
  //  on_new_game_click();
}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////
void Main_window::on_addpat(){
  control.execute_cmd(5);
}
void Main_window::on_easter(){
  control.execute_cmd(99);
}
void Main_window::on_help(){
  control.execute_cmd(9);
}
void Main_window::on_listpat(){
  control.execute_cmd(6);
}
void Main_window::on_List() {
  control.execute_cmd(2);
}
void Main_window::on_checkin() {
  control.execute_cmd(3);
}
void Main_window::on_checkout() {
  control.execute_cmd(4);
}
void Main_window::on_Add() {
  control.execute_cmd(1);

}


void Main_window::on_quit_click() {
    close();
}

void Main_window::on_about_click() {
    Glib::ustring s = "<span size='24000' weight='bold'>Nim</span>\n<span size='large'>CSE1325 Homework</span>\n<span size='small'>Licensed under Creative Commons Attribution 4.0 International\nRobot icon created by Freepik, used under free attribution license</span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}
