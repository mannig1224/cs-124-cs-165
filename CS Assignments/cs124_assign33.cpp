/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will consist of three parts:
*
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * Prototype for the display function
***********************************************************************/
void display(float *sam, float *sue);

/**********************************************************************
 * getBalance gets passed by the addresses to sam and sue then changes
 * the value
***********************************************************************/
float getBalance(float *sam, float *sue)
{
   cout << "What is Sam's balance? ";
   cin >> *sam;
   cout << "What is Sue's balance? ";
   cin >> *sue;
   return 0;
}

/**********************************************************************
 * Basic function that prompts for the costs of date
***********************************************************************/
float getCost()
{
   float dinner;
   float movie;
   float iceCream;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;
   float totalCost = dinner + movie + iceCream;
   return totalCost;
}

/**********************************************************************
 * Basic function. Determines who has more money
 ***********************************************************************/
int main()
{
   float sam;
   float sue;
   getBalance(&sam, &sue);
   float totalCost = getCost();
   if (sam > sue)
   {
      sam = sam - totalCost;
   }
   else
   {
      sue = sue - totalCost;
   }
   display(&sam, &sue);
   return 0;
}

/**********************************************************************
 * Basic display function
***********************************************************************/
void display(float *sam, float *sue)
{
   cout << "Sam's balance: " << "$" << *sam << "\n";
   cout << "Sue's balance: " << "$" << *sue << "\n";
}
