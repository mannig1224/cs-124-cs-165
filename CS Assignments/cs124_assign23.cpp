/***********************************************************************
* Program:
*    Assignment 23, Functions
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for an integer and then find the sum
*    the sum of that integer factors up to 100
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was figuring out how to add the sum
*      of the factors
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will not do much here. It will prompt for an integer and than
 * display its sum of all factors below 100
 ***********************************************************************/
int main()
{
   // start
   cout << "What multiples are we adding? ";
   int math;
   int sum = 0;
   cin >> math;


   // for loop that calculates all the math
   for (int count = math; count < 100; count += math)
      sum = sum + count;
         cout << "The sum of multiples of "
           << math
           << " less than 100 are: "
           << sum << endl;

   return 0;
}
