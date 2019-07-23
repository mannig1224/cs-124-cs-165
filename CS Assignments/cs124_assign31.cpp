/***********************************************************************
* Program:
*    Assignment 31, Arrays
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will consist of three parts:
*    getGrades(), averageGrades(), and a driver program.
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      Finding resources that are actually useful in regards to the assignment
*      , since the book is hard to understand.
*      .
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
 * prototype function for getGrades
 ***********************************************************************/
void getGrades(int gradeArray[], int size);

/**********************************************************************
 * prototype function for averageGrades
 ***********************************************************************/
int averageGrades(int gradeArray[], int size);

/**********************************************************************
 * main() declares variable and calls functions
 ***********************************************************************/
int main()
{
   // Declare the variables
   const int size = 10;

   int gradeArray[size];

   getGrades(gradeArray, size);

   averageGrades(gradeArray, size);

   if (averageGrades(gradeArray, size) == -1)
   {
      cout << "Average Grade: ---%\n";
   }
   else
   {
      cout << "Average Grade: " << averageGrades(gradeArray, size);
      cout << "%" << endl;
   }
   return 0;
}

/**********************************************************************
 * getGrades creates fills an array using a loop function
 ***********************************************************************/
void getGrades(int gradeArray[], int size)
{

// fills the array

   for (int x = 0; x < size; x++)    // stantard for loop
   {
      cout << "Grade " << x + 1 << ": ";
      cin >> gradeArray[x];

   }

   return;
}

/**********************************************************************
 * averageGrades figures out the total of the numbers in the Array
 * and finds the the average.
 ***********************************************************************/
int averageGrades(int gradeArray[], int size)
{
   int averageNum = 0;
   int negNum = 0;

   for (int x = 0; x < size; x++)
   {
      if (gradeArray[x] != -1)
      {
         averageNum = averageNum + gradeArray[x];
         negNum++;
      }
      if (negNum == 0)
      {
         return -1;
      }
   }
   return averageNum / negNum;
}
