/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;


/**********************************************************************
 * Structure: ComplexNumber
 * Purpose: This holds the tags real and imaginary
 ***********************************************************************/
struct ComplexNumber
{
   double real;
   double imaginary;
};


void prompt(ComplexNumber &c1, ComplexNumber &c2);
void addComplex(ComplexNumber &c1, ComplexNumber &c2,
   ComplexNumber &c3);
void display(const ComplexNumber &c3);


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   ComplexNumber c1;
   ComplexNumber c2;
   ComplexNumber c3;
   prompt(c1,c2);         // since it is pass-by- reference, nu1 changes
   cout << endl;
   addComplex(c1,c2,c3);
   display(c3);

   return 0;
}

/**********************************************************************
 * Function: prompt
 * Purpose: This function gets input from user
 ***********************************************************************/
void prompt(ComplexNumber &c1, ComplexNumber &c2)
{
   cout << "Real: ";
   cin >> c1.real;
   cout << "Imaginary: ";
   cin >> c1.imaginary;
   cout << "Real: ";
   cin >> c2.real;
   cout << "Imaginary: ";
   cin >> c2.imaginary;
}

/**********************************************************************
 * Function: addComplex
 * Purpose: This function adds two structures and fills in a 3rd one
 ***********************************************************************/
void addComplex(ComplexNumber &c1, ComplexNumber &c2,
   ComplexNumber &c3)
{
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
}

/**********************************************************************
 * Function: display
 * Purpose: This function will display
 ***********************************************************************/
void display(const ComplexNumber &c3)
{
   cout << "The sum is: " << c3.real << " + " << c3.imaginary << "i";
   cout << endl;
}
