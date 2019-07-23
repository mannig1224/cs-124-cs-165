/***********************************************************************
* Program:
*    Checkpoint 04a, Classes
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Class Book
 * Purpose: Class that describes the book.
 ***********************************************************************/
class Book
{
   private: string title;
   private: string author;


   public:
/**********************************************************************
 * Class Function: prompt
 * Purpose: Prompts the user for and author and title
 ***********************************************************************/
      void prompt()
      {
         cout << "Title: ";
         getline(cin, title);
         cout << "Author: ";
         getline(cin, author);
      }


   public:
/**********************************************************************
 * Class Function: prompt
 * Purpose: Displays the user for and author and title
 ***********************************************************************/
      void display()
      {
         cout << "\"" << title << "\" by " << author;
         cout << endl;
      }
};




/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book bookObject;
   bookObject.prompt();
   bookObject.display();
   return 0;
}
