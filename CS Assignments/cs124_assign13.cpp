/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for an input and translate it into
*    Celsius
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was understanding the data types
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * main()... Only one main function
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);      // no scientific notation

   //declare the variables
   float fahrenheit;
   double celsius;

    //prompt for temperature
   cout << "Please enter Fahrenheit degrees: ";
   cin  >> fahrenheit;
   celsius = float(5.0 / 9.0) * (fahrenheit - 32);


    // display the results
   cout << setprecision(0) << "Celsius: "
        << celsius
        << endl;

   return 0;
}
