/***********************************************************************
* Program:
*    Project 07, Calendar Project
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for a year and month and then
*    display the calendar for said month.
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      Was figuring out an algorithm to find the offset of the month.
* and getting the right spaces at the end of each month.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Array for the number of months in a specific days
// Added a zero to start the count so the numbers actually
// align with the months
int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

/**********************************************************************
 * Basic function that prompts user for a month
 ***********************************************************************/
int getMonth()
{
   float month;
    //Get month
   cout << "Enter a month number: ";
   cin >> month;
   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n";
      cin >> month;
   }
   return month;
}

/**********************************************************************
 * Basic function that promts user for the year
 ***********************************************************************/
int getYear()
{
   int year;
   //Get year
   cout << "Enter year: ";
   cin >> year;
   cout << endl;
   return year;
}


/**********************************************************************
 * Function that calculates wether or not a year is a leap year
 ***********************************************************************/
int isLeapYear(int year)
{
   if (year % 4 == 0 && year % 100 != 0)
   {
      return true;
   }
   if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
   {
      return true;
   }
   return false;
}

/**********************************************************************
 * Function that determines the number of days a year has determined by
 * wether its a leap year or not
 ***********************************************************************/
int numDaysInYear(int year)
{
   bool isLeap = isLeapYear(year);
   if (isLeap)
   {
      return 366;
   }
   else
   {
      return 365;
   }
}

/**********************************************************************
 * Function that determines number of days in month using the year and
 * month given by the user. Looks up the number of days with a global array
 * that was set at the beginning of program
 ***********************************************************************/
int numDaysInMonth(int year, int month)
{
   bool isLeap = isLeapYear(year);
   if (isLeap && month == 2)
   {
      return 29;
   }
   else
   {
      return monthDays[month];
   }
}


/**********************************************************************
 * Function that displays the header of the calendar given the input
 * of the month
 ***********************************************************************/
void displayHeader(int month)
{
   switch (month)
   {
      case 1 : cout << "January";
      break;
      case 2 : cout << "February";
      break;
      case 3 : cout << "March";
      break;
      case 4 : cout << "April";
      break;
      case 5 : cout << "May";
      break;
      case 6 : cout << "June";
      break;
      case 7 : cout << "July";
      break;
      case 8 : cout << "August";
      break;
      case 9 : cout << "September";
      break;
      case 10 : cout << "October";
      break;
      case 11: cout << "November";
      break;
      case 12: cout << "December";
   }
   return;
}

/**********************************************************************
 * Most complicated function in the program. Determines the offset of the
 * month by using the year and month given by the user.
 ***********************************************************************/
int computeOffset(int year, int month)
{
   int totalDaysPassed = 0;

   for (int x = 1753; x < year; x++)
   {
      totalDaysPassed = totalDaysPassed + numDaysInYear(x);
   }
   for (int i = 1; i < month; i++)
   {
      totalDaysPassed = totalDaysPassed + numDaysInMonth(year, i);
   }

   int offset = ((totalDaysPassed + 1) % 7);
   return offset;
}




/**********************************************************************
 * Displays the header of the calendar as well as creates the chart
 * using the year, month, and offset.
 ***********************************************************************/
void display(int year, int month, int offset)
{
   displayHeader(month);

   cout << "," << " " << year << endl;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   for (int i = 0; i < 40; i++)
   {
      int monthValue = i - offset;
      if (i % 7 == 0)
      {
         cout << "  ";
      }
      if (monthValue < 0)
      {
         cout << "    ";
      }

      else if (monthValue < numDaysInMonth(year,month))
      {
         cout << setw(2) << monthValue + 1;

         if ( i % 7 != 6 && (monthValue + 1) != numDaysInMonth(year,month))
         {
            cout << "  ";
         }
      }
      if (i % 7 == 6)
      {
         cout << endl;
      }

      if ( monthValue + 1 >= numDaysInMonth(year,month))
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
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(year, month);
   display (year, month, offset);
   return 0;
}
