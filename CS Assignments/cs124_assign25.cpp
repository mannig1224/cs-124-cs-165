/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for number of days in a monthly
*    and also first day of month and then display the calendar for it
*
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * displays Calendar given an offset and number of days in month.
 ***********************************************************************/
void displayTable(int numDays, int offset)
{

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   if (offset == 6)
   {
      offset = -1;
   }
   for (int i = 0; i < 40; i++)
   {
      int monthValue = i - (offset + 1) ;
      if (i % 7 == 0)
      {
         cout << "  ";
      }

      if (monthValue < 0)
      {
         cout << "    ";
      }

      else if (monthValue < numDays)
      {
         cout << setw(2) << monthValue + 1;

         if ( i % 7 != 6 && (monthValue + 1) != numDays)
         {
            cout << "  ";
         }
      }

      if (i % 7 == 6)
      {
         cout << endl;
      }

      if ( monthValue + 1 >= numDays)
      {
         if ( i % 7 != 6)
         {
            cout << endl;
         }
         break;
      }

   }

   return;
}

/**********************************************************************
 * Main will not do much here. It will prompt for an integer and than
 * display its sum of all factors below 100
 ***********************************************************************/
int main()
{
   int numDays;
   int offset;

   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;

   displayTable(numDays, offset);

   return 0;
}
