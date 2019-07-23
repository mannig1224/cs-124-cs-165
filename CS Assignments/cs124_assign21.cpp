/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    Sues Program: Stub functions for Sues Program
*
*    Estimated:  1.0 hrs
*    Actual:     1.45 hrs
*      Understanding how to pass information from one function
*      to another.
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;


float getUsageCost()
{
   return 0.0;
}

float getPeriodicCost()
{
   return 0.0;
}




float promptDevalue()
{
   return 0.0;
}

float promptInsurance()
{
   return 0.0;
}

float promptParking()
{
   return 0.0;
}

float promptMileage()
{
   return 0.0;
}

float promptGas()
{
   return 0.0;
}

float promptRepairs()
{
   return 0.0;
}

float promptTires()
{
   return 0.0;
}




void display(int period,int usage)
{
   cout << "Success\n";
   return;

}

int main()
{
   double period = getPeriodicCost();
   double usage = getUsageCost();

   display(period,usage);

   return 0;
}
