/***********************************************************************
* Program:
*    Checkpoint 03b, Errors
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void prompt(int *number);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;
   prompt(&number);
   cout << "The number is " << number << ".";
   cout << endl;
   return 0;
}

/**********************************************************************
 * Function: prompt
 * Purpose: This gets a number passed and then check that its not
 * anything else than a number.
 ***********************************************************************/
void prompt(int *number)
{
   cout << "Enter a number: ";
   cin >> *number;
   while (cin.fail())
   {

      cin.clear();              // clear the error state
      cin.ignore(256, '\n');    // ignore all the characters in the buffer
      cout << "Invalid input.\n";
      cout << "Enter a number: ";
      cin >> *number;
   }
}
