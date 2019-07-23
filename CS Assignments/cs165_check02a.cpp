/***********************************************************************
* Program:
*    Checkpoint 02a, Structs
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;



struct User
{
   char firstName[25];
   char lastName[25];
   int id;
};


void displayStudent(const User &student);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   User student;
   cout << "Please enter your first name: ";
   cin.getline (student.firstName,25);

   cout << "Please enter your last name: ";
   cin.getline (student.lastName,25);

   cout << "Please enter your id number: ";
   cin >> student.id;

   displayStudent(student);

   return 0;
}

/**********************************************************************
 * Function: displayStudent
 * Purpose: This function recieves the info from the structure tag student
 * and displays it.
 ***********************************************************************/
void displayStudent(const User &student)
{
   cout << endl;
   cout << "Your information:";
   cout << endl;
   cout << student.id << " - " << student.firstName
      << " " << student.lastName << endl;
}
