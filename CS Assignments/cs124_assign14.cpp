/***********************************************************************
* Program:
*    Assignment 14, Functions
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will prompt the user for an input and translate it into
*    Celsius
*    Estimated:  1.0 hrs
*    Actual:     0.3 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was understanding functions in general
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Peters question
 * This function is stating Peters Question
 ***********************************************************************/
void questionPeter()
{
   //display Peters question
   cout << "Lord, how oft shall my brother sin against me,"
        << " and I forgive him?\n"
        << "Till seven times?\n";

   return;

}


/**********************************************************************
 * Lords Response function
 * This function will calculate the lords response
 ***********************************************************************/
int responseLord()
{
   return 7 * 70;
}

/**********************************************************************
 * Main will not do much here.  First it will display Peter's question,
 * then it will display the Lord's answer
 ***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n"
        << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
