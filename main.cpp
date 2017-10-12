//#include "controller.h"
#include "library.h"
#include "main_window.h"
#include <gtkmm.h>

int main (int argc, char *argv[])
{
  int i=0;
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv, "edu.uta.cse1325.Libraryms");

  // Instance a Window
  Main_window win;
  
  // Set the window title
  win.set_title("CSE1325 Library Management");

  //Show the window and returns when it is closed or hidden
  while(i<10){
  return app->run(win);
  i++;
};
}
