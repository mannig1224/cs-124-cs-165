/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector <int> myVector;
   int input = 10;
   while (input != 0)
   {
      cout << "Enter int: ";
      cin >> input;
      cin.ignore();
      myVector.push_back(input);
   }
   cout << "Your list is:" << endl;
   for (int j = 0; j < myVector.size() - 1; j++)
   {
      cout << myVector.at(j) << endl;
   }

   cout << endl;


   vector <string> myStringVector;
   string myString;
   while (myString != "quit")
   {
      cout << "Enter string: ";
      getline(cin, myString);
      myStringVector.push_back(myString);
   }
      cout << "Your list is:" << endl;
      for (int j = 0; j < myStringVector.size() - 1; j++)
   {
      cout << myStringVector.at(j) << endl;
   }


   return 0;
}
