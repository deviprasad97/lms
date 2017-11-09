#ifndef __VIEW_H
#define __VIEW_H 201609

#include "library.h"

class View {
  public:
    View(Library& lib) : library(lib) { }
    void list_patrons();
    void help();
    void list_publications();
    int select_publication();
    int select_from_menu();
    int select_patron();
    int select_genre();
    int select_age();
    int select_media();
    int get_length();
    string get_pub_title(int i);
    string get_pub_author(int i);
    string get_pub_copyright(int i);
    string get_pub_age(int i);
    string get_pub_genre(int i);
    string get_pub_media(int i);
    string get_pub_isbn(int i);
    string get_pub_ava(int i);

  private:
    string get_publications();
    string get_patrons();
    Library& library;
};
#endif
