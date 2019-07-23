/***********************************************************************
* Program:
*    Assignment 12, Input and Variable
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for their monthly income and then
*    display on screen.
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      Learning how to use the tools and navigate the terminal. For this
*      one it was also hard remember data types.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * main()... Only one main function
 ***********************************************************************/
int main()
{
    // format the output for money
   cout.setf(ios::fixed);      // no scientific notation
   cout.setf(ios::showpoint);  // always show the decimal point


    //declare the variables
   float income;

    //prompt for Income
   cout << "\tYour monthly income: ";
   cin  >> income;

   cout.precision(2);          // unless you own a gas station, money
                                //    is formatted to two decimals

    // display the results
   cout << "Your income is: $"
         << setw(9)
         << income
         << endl;

   return 0;
}
