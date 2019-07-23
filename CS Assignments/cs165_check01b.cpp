/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

int getSize();
void getList(int list[], int size);
void displayMultiples(int list[], int size);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int list[20];
   int size = getSize();
   getList(list, size);
   displayMultiples(list, size);
   return 0;
}

/**********************************************************************
 * Function: getSize
 * Purpose: Calls for the size of the list from the user
 ***********************************************************************/
int getSize()
{

   int size;
   cout << "Enter the size of the list: ";
   cin >> size;
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: Runs through the array filling it by user input
 ***********************************************************************/
void getList(int list[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: Function that figures out if numbers are divisible by 3
 ***********************************************************************/
void displayMultiples(int list[], int size)
{
   cout << endl;
   cout << "The following are divisible by 3:";
   for (int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
      {
         cout << endl;
         cout << list[i];
      }
   }
   cout << endl;
}
