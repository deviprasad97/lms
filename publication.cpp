 #include "publication.h"
 #include <string>
 #include <iostream>

 using namespace std;


 bool Publication::is_checked_out() {return checked_out;}
 void Publication::check_out(Patron& p_patron) {
   if (checked_out) {
     throw Invalid_transaction();
   } else {
     patron = p_patron;
     checked_out = true;
   }
 }

 void Publication::check_in() {
   if (checked_out) {
     checked_out = false;
   } else {
     throw Invalid_transaction();
   }
 }

 string Publication::to_string() {
   string pub = "\"" + title + "\"" + " by " + author + ", \n      " + copyright +
     " (" + target_age.to_string() + " " + genre.to_string() + " "
         + media.to_string() + ") \n      " + "ISBN: " + isbn;
   if (checked_out) {
      pub += "\n      Checked out to " + patron.get_patron_name() +
             " (" + patron.get_patron_phone_number() + ")";
   }
   return pub;
 }
 string Publication::to_strtitle(){
   return title;
 }
 string Publication::to_strauthor(){
   return author;
 }
 string Publication::to_strcopyright(){
   return copyright;
 }
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
 string Publication::to_str_ava(){
   if (checked_out) {
      return "Not Avaliable";
   }
   else{
     return "Avaliable";
   }
 }
