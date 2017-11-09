#ifndef __CONTROLLER_H
#define __CONTROLLER_H 201609

#include "library.h"
#include "view.h"

class Controller {
  public:
    Controller (Library& lib) : library(lib), view(View(library)) { }
    void cli();
    string title_getter(int i);
    string author_getter(int i);
    string copyright_getter(int i);
    string age_getter(int i);
    string genre_getter(int i);
    string media_getter(int i);
    string isbn_getter(int i);
    string ava_getter(int i);
    void execute_cmd(int cmd);
    int pub_size();
  private:
    Library& library;
    View view;
};
#endif
