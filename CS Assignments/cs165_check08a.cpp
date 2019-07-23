/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
   public:
      string title;
      string author;
      int publicationYear;
      void promptBookInfo()
      {
         cout << "Title: ";
         getline(cin, title);

         cout << "Author: ";
         getline(cin, author);

         cout << "Publication Year: ";
         cin >> publicationYear;
         cin.ignore();

      }
      void displayBookInfo()
      {
         cout << title << " (" << publicationYear << ") " << "by " << author
            << endl;
      }
};

// TODO: Define your TextBook class here
class TextBook: public Book
{
   public:
      string subject;
      void promptSubject()
      {
         cout << "Subject: ";
         getline(cin, subject);
         cout << endl;


      }
      void displaySubject()
      {
         cout << "Subject: " << subject << endl;
      }

};

// TODO: Add your PictureBook class here
class PictureBook: public Book
{
   public:
      string illustrator;
      void promptIllustrator()
      {
         cout << "Illustrator: ";
         getline(cin, illustrator);

      }
      void displayIllustrator()
      {
         cout << "Illustrated by "<< illustrator << endl;
      }
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book b1;
   b1.promptBookInfo();
   cout << endl;
   b1.displayBookInfo();
   cout << endl;

   // Declare a TextBook object here and call its methods
   TextBook t1;
   t1.promptBookInfo();
   t1.promptSubject();
   t1.displayBookInfo();
   t1.displaySubject();
   cout << endl;


   // Declare a PictureBook object here and call its methods
   PictureBook p1;
   p1.promptBookInfo();
   p1.promptIllustrator();
   cout << endl;
   p1.displayBookInfo();
   p1.displayIllustrator();


   return 0;
}
