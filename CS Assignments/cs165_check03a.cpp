/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void prompt(int *number);    // Simple Prototype



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;

   try
   {
      prompt(&number);
   }

   catch (const char* exception)
   {
      cout << "Error: ";
      cout << exception;
      return 0;
   }

   cout << "The number is " << number << ".";
   cout << endl;
   return 0;
}


/**********************************************************************
 * Function: prompt
 * Purpose: Receives input from main than determines if it falls under
 * any of three situations.
 ***********************************************************************/
void prompt(int *number)
{
   cout << "Enter a number: ";
   cin >> *number;

   while (*number < 0)
   {
      throw "The number cannot be negative.\n";
      cin >> *number;
   }
   while (*number > 100)
   {
      throw "The number cannot be greater than 100.\n";
      cin >> *number;
   }
   while (*number % 2 != 0)
   {
      throw "The number cannot be odd.\n";
      cin >> *number;
   }
}
