/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void compare(char sequence[][200], char ownSequence[11],
    char names[][200], int size);
int getSize();
void getNames(char names[][200], int size);
void getSequence(char sequence[][200], char names[][200], int size);


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   char sequence[200][200];
   char names[200][200];
   char ownSequence[15];
   cout << "Enter your DNA sequence: ";

   cin.getline (ownSequence,15);
   int size = getSize();

   cout << endl;

   getNames(names,size);

   cout << endl;

   getSequence(sequence, names, size);

   cout << endl;

   compare(sequence, ownSequence, names, size);
   return 0;
}

/**********************************************************************
 * Function: getSize
 * Purpose: Calls for the size of the list from the user
 ***********************************************************************/
int getSize()
{

   int size;
   cout << "Enter the number of potential relatives: ";

   cin >> size;
   cin.ignore();
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: Runs through the array filling it by user input
 ***********************************************************************/
void getNames(char names[][200], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin.getline (names[i], 200);
   }
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: Function that figures out if numbers are divisible by 3
 ***********************************************************************/
void getSequence(char sequence[][200], char names[][200], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Please enter the DNA sequence for ";
      cout << names[i] << ": ";
      cin.getline (sequence[i], 200);
   }

}

/**********************************************************************
 * Function: compare
 * Purpose: compares the original sequence with others
 ***********************************************************************/
void compare(char sequence[][200], char ownSequence[15],
    char names[][200], int size)
{

   for (int i = 0; i < size; i++)
   {
      int count = 0;
      cout << "Percent match for " << names[i] << ": ";
      for (int j = 0; j < 10; j++)
      {
         if (ownSequence[j] == sequence[i][j])
         {
            count = count + 10;

         }

      }
      cout << count << "%";
      cout << endl;
   }

}
