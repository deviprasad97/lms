 #ifndef __LIBRARY_H
 #define __LIBRARY_H 201609
 #include "patron.h"
 #include "publication.h"

 #include <iostream>
 #include <string>
 #include <vector>

 using namespace std;


 class Library {
   public:
     void add_publication(Publication pub);
     void add_patron(Patron pat);

     void check_out(int publication_index, int patron_index);
     void check_in(int publication_index);

     string publication_to_string(int publication_index);
     string patron_to_string(int patron_index);

     int number_of_publications();
     int number_of_patrons();

    string pub_title_to_string(int publication_index);
    string pub_author_to_string(int publication_index);
    string pub_copyright_to_string(int publication_index);
    string pub_age_to_string(int publication_index);
    string pub_genre_to_string(int publication_index);
    string pub_media_to_string(int publication_index);
    string pub_isbn_to_string(int publication_index);
    string pub_ava_to_string(int publication_index);


     void easter_egg();
   private:
     vector<Publication> publications;
     vector<Patron> patrons;
 };
 #endif
