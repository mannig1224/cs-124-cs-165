/***********************************************************************
* Program:
*    Assignment 11, Money Alignment
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will display a budget in an orderly fashion.
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      Learning how to use the tools and sign in to linux and copy the template
*      .
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // format the output for money
   cout.setf(ios::fixed);      // no scientific notation
   cout.setf(ios::showpoint);  // always show the decimal point
   cout.precision(2);          // unless you own a gass station, money
                               //    is formatted to two decimals

   // display the first row
   cout << "\tItem           Projected\n";
   // display the second row
   cout << "\t=============  ==========\n";
   cout << "\tIncome         " << "$" <<  setw(9) << 1000.0 << endl;
   cout << "\tTaxes          " << "$" <<  setw(9) << 100.0 << endl;
   cout << "\tTithing        " << "$" <<  setw(9) << 100.0 << endl;
   cout << "\tLiving         " << "$" <<  setw(9) << 650.0 << endl;
   cout << "\tOther          " << "$" <<  setw(9) << 90.0 << endl;
   cout << "\t=============  ==========\n";
   cout << "\tDelta          " << "$" <<  setw(9) << 60.0 << endl;

   return 0;
}
