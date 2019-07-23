/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will compute what tax bracket you are in depending on
*    your income
*
*    Estimated:  1.0 hrs
*    Actual:     1.45 hrs
*      Syntax for C++ is hard for me. It's differ from Javascript
*      Also trying to remember data types
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Using else if statements we are able to compute which tax bracket
* one belongs depending on the income
***********************************************************************/
int computeTax(int income)
{
   if (income >= 336550)
      return 35;
   else if (income < 336550 && income >= 188450)
      return 33;
   else if (income < 188450 && income >= 123700)
      return 28;
   else if (income < 123700 && income >= 61300)
      return 25;
   else if (income < 61300 && income >= 15100)
      return 15;
   else
      return 10;

}

/**********************************************************************
* Will prompt the user for the income and then send that info to
* the computeTax function using parameter
***********************************************************************/
int main()
{
   int income;

   cout << "Income: ";
   cin  >>  income;

   cout << "Your tax bracket is " << computeTax(income) << "%\n";

   return 0;
}
