/***********************************************************************
* Program:
*    Project 03, Monthly Budget
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
 * getIncome() is a function to be late called in main
***********************************************************************/
float getIncome ()
{
   float income;
   //prompt for Income
   cout << "\tYour monthly income: ";
   cin  >> income;
   return income;

}

/**********************************************************************
 * getBudgetLiving() is a function to be late called in main
***********************************************************************/
float getBudgetLiving ()
{
   float bExpenses;
    //prompt for Budgeted living expenses
   cout << "\tYour budgeted living expenses: ";
   cin  >> bExpenses;
   return bExpenses;
}

/**********************************************************************
 * getActualLiving() is a function to be late called in main
***********************************************************************/
float getActualLiving ()
{
   float aExpenses;
    //prompt for Actual Living Expenses
   cout << "\tYour actual living expenses: ";
   cin  >> aExpenses;
   return aExpenses;
}

/**********************************************************************
 * getActualOther() is a function to be late called in main
 ***********************************************************************/
float getActualOther ()
{
   float other;
   //prompt for Actual Other
   cout << "\tYour actual other expenses: ";
   cin  >> other;
   cout << endl;
   return other;
}

/**********************************************************************
 * getActualTithing() is a function to be late called in main
 ***********************************************************************/
float getActualTithing ()
{
   float tithe;
    //prompt for Tithe Offerings
   cout << "\tYour actual tithe offerings: ";
   cin  >> tithe;
   return tithe;
}

/**********************************************************************
 * getActualTax() is a function to be late called in main
 ***********************************************************************/
float getActualTax ()
{
   float taxes;
    //prompt for Actual Taxes Withheld
   cout << "\tYour actual taxes withheld: ";
   cin  >> taxes;
   return taxes;
}





/**********************************************************************
 * computeTax() will compute Tax in later assignments
 ***********************************************************************/
float computeTax ()
{
   return 0.0;
}

/**********************************************************************
 * computeTithing() computes tithing and sends it is used in place
 * for actual tithing
 ***********************************************************************/
float computeTithing (float income)
{

   return income / 10;
}

/**********************************************************************
 * display() Calls all functions from main and displays them
 ***********************************************************************/
void display (float income, float budgetLiving, float actualTax,
     float actualTithing, float actualLiving, float actualOther)
{

    // format the output for money

   cout.setf(ios::fixed);      // no scientific notation
   cout.setf(ios::showpoint);  // always show the decimal point
   cout.precision(2);          // unless you own a gas station, money
                                // is formatted to two decimals

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
       << "    $"  <<  setw(11) << actualTax << endl;

    //Calls a variable for budget to input in the c.out
   float budgetTithing = computeTithing(income);

    //Tithing display
   cout << "\tTithing         "
       << "$"  <<  setw(11) << budgetTithing
       << "    $"  <<  setw(11) << actualTithing << endl;

    //Living display
   cout << "\tLiving          "
       << "$"  <<  setw(11) << budgetLiving
       << "    $"  <<  setw(11) << actualLiving << endl;

    //budget other calculate
   float budgetOther = income - 0.0 - budgetTithing - budgetLiving;

    //Other display
   cout << "\tOther           "
       << "$"  <<  setw(11) << budgetOther
       << "    $"  <<  setw(11) << actualOther << endl;


   cout << "\t=============== =============== ===============\n";

   float actualDifference = income - actualTax
      - actualTithing - actualLiving - actualOther;

   float budgeDifference = income - 0.0 - budgetTithing - budgetLiving
      - actualOther;

   cout << "\tDifference      "
       << "$"  <<  setw(11) << 0.00
       << "    $"  <<  setw(11) << actualDifference << endl;


}

/**********************************************************************
 * main() Calls all functions and sends them to display
 ***********************************************************************/
int main()
{

   // display the first two: rows
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:"
        << endl;

   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float actualLiving = getActualLiving();
   float actualTax = getActualTax();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();
   display (income, budgetLiving, actualTax, actualTithing,
        actualLiving, actualOther);


   return 0;
}
