/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Ridges, CS124
* Author:
*    Emmauel Gatica
* Summary:
*    This program will convert feet to meters
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Learning the array to float syntax
************************************************************************/

#include <cstdlib>      // the library for atof()
#include <iostream>     // the library for atof()
#include <iomanip>      // set precision
using namespace std;

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.
 ***********************************************************************/
int main(int argc, char** argv)
{
   for (int i = 1; i < argc; i++)
   {
      cout << setprecision(1);
      float feet = atof(argv[i]);
      float meters = 0.3048 * feet;
      cout << fixed << setprecision(1) << feet
         << " feet is " << meters << " meters\n";
   }
   return 0;
}
