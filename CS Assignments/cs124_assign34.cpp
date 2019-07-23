/***********************************************************************
* Program:
*    Assignment 34, Pointers Arithmetic
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will consist of two parts:
*    main() int countLetters(). This program
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prototype for countLetters... Lets me have functions in any order
 ***********************************************************************/
int countLetters(char letter, char *text);

/**********************************************************************
 * Basic function that prompts for a letter and text
 ***********************************************************************/
int main()
{
   // input
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;

   char text[256];

   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);


   cout << "Number of '" << letter << "'s: "
      << countLetters(letter, text) << endl;

   return 0;
}

/**********************************************************************
 * countLetters figures out the amount of letters in text
 ***********************************************************************/
int countLetters(char letter, char *text)
{
   int count = 0;

   for (int x = 0; x < 256; x++)
   {
      if (*(text + x) == letter)
      {
         count++;
      }
      if (*(text + x) == '\0')
      {
         break;
      }
   }
   return count;

}
