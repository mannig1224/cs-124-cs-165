/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will ask the user for inputs and then display
*    them on the screen.
*    Estimated:  2.0 hrs
*    Actual:     4.0 hrs
*      Please describe briefly what was the most difficult part.
*      Organizing my functions and inserting the right memory types.
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
   cout.precision(2);          // unless you own a gas station, money
                               //    is formatted to two decimals

   // declare the variables
   float income;
   float bExpenses;
   float aExpenses;
   float taxes;
   float tithe;
   float other;

   // display the first two: rows
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:"
        << endl;

   //prompt for Income
   cout << "\tYour monthly income: ";
   cin  >> income;


   //prompt for Budgeted living expenses
   cout << "\tYour budgeted living expenses: ";
   cin  >> bExpenses;

   //prompt for Actual Living Expenses
   cout << "\tYour actual living expenses: ";
   cin  >> aExpenses;

   //prompt for Actual Taxes Withheld
   cout << "\tYour actual taxes withheld: ";
   cin  >> taxes;

   //prompt for Tithe Offerings
   cout << "\tYour actual tithe offerings: ";
   cin  >> tithe;

   //prompt for Actual Other
   cout << "\tYour actual other expenses: ";
   cin  >> other;
   cout << endl;

   // Controls decimals
   cout.precision(2);          // unless you own a gas station, money
                                //    is formatted to two decimals

   //Starting display
   cout << "The following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual"
        << endl;
   cout << "\t=============== =============== ===============\n";
   //Income display
   cout << "\tIncome          "
      << "$"  <<  setw(11) << income
      << "    $"  <<  setw(11) << income << endl;
   //Taxes display
   cout << "\tTaxes           "
      << "$"  <<  setw(11) << 0.00
      << "    $"  <<  setw(11) << taxes << endl;
   //Tithing display
   cout << "\tTithing         "
      << "$"  <<  setw(11) << 0.00
      << "    $"  <<  setw(11) << tithe << endl;
   //Living display
   cout << "\tLiving          "
      << "$"  <<  setw(11) << bExpenses
      << "    $"  <<  setw(11) << aExpenses << endl;
   //Other display
   cout << "\tOther           "
      << "$"  <<  setw(11) << 0.00
      << "    $"  <<  setw(11) << other << endl;


   cout << "\t=============== =============== ===============\n";

   cout << "\tDifference      "
      << "$"  <<  setw(11) << 0.00
      << "    $"  <<  setw(11) << 0.00 << endl;


   return 0;
}
