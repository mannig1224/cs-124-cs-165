/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will read integers from another txt file and figure
*    out the average
*    Estimated:  1.0 hrs
*    Actual:     7.0 hrs
*      Please describe briefly what was the most difficult part.
*      I find the concepts of the book really hard to understand.
*      Personally I found more usefull information watching Youtube
*      videos than from the book.
************************************************************************/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

/**********************************************************************
 * display() Calls all functions from main and displays them
 ***********************************************************************/
void getFileName(char fileName[100])
{
   return;
}

/**********************************************************************
 * reads file and gets average of sum
 ***********************************************************************/
float readFile(char fileName[100])
{

   ifstream gpaFile(fileName);



   if (gpaFile.fail())
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
      exit(EXIT_FAILURE);
   }


   char* gpa;
   float total = 0;
   int counter = 0;

   while (gpaFile >> gpa)
   {
      total += atoi (gpa);
      counter++;
   }

   if (counter != 10)
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
      exit(EXIT_FAILURE);
   }

   float average = total / counter;

   return average;
}

/**********************************************************************
 * displays Average Grade
 ***********************************************************************/
void display(float average)
{

   cout << fixed;
   cout << setprecision(0);
   cout << "Average Grade: " << average << '%' << endl;
}

/**********************************************************************
 * Basic main function that calls info and send info
 ***********************************************************************/
int main()
{
   char fileName[256];
   cout << "Please enter the filename: ";
   cin.getline(fileName, 256);
   getFileName(fileName);
   display(readFile(fileName));
   return 0;
}
