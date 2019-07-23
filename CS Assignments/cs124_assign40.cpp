/***********************************************************************
* Program:
*    Assignment 40, MULTI-DIMENSIONAL ARRAYS
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*    This program will display a tic tac toe board from a file
*
*    Estimated:  1.0 hrs
*    Actual:     4.3 hrs
*      putting in the lines in between and also saving the file
*      .
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


// Basic prototypes
void getName(char fileName[]);
void readFile(char ticTac[][3]);
void display(char ticTac[][3]);

/**********************************************************************
 * Gets File Name from user
 ***********************************************************************/
void getName(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;

}

/**********************************************************************
 * Gets file destination from user
 ***********************************************************************/
void getSecondFile(char secondFile[])
{
   cout << "Enter destination filename: ";
   cin >> secondFile;
}

/**********************************************************************
 * Opens file and reads it unto an array
 ***********************************************************************/
void readFile(char ticTac[][3])
{
   char fileName[256];
   getName(fileName);
   ifstream txtFile(fileName);


   if (txtFile.fail())            // checking if the file fails to open
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
      exit(0);
   }


   int x = 0;
   int i = 0;
   char temp[10];
   for (i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (!(txtFile >> temp))

         {
            break;
         }
         ticTac[i][j] = temp[0];
      }

   }


   txtFile.close();

}



/**********************************************************************
 * displays data from file with added spaces and characters
 ***********************************************************************/
void display(char ticTac[][3])
{
   int i = 0;
   int j = 0;
   for (i = 0; i < 3; i++)
   {
      if (i == 1 || i == 2)
      {
         cout << "---+---+---\n";
      }
      for (j = 0; j < 3; j++)
      {
         cout << " ";
         if (ticTac[i][j] == '.')
         {
            ticTac[i][j] = ' ';
         }
         cout << ticTac[i][j];
         cout << " ";
         if (j == 0 || j == 1)
         {
            cout << '|';
         }

      }

      cout << endl;
   }

}

/**********************************************************************
 * Saves unto file given by user
 ***********************************************************************/
void displayTwoFile (char ticTac[][3])
{
   char secondFile[256];
   ofstream fileTwo;
   getSecondFile(secondFile);
   fileTwo.open(secondFile);

   int i = 0;
   int j = 0;
   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
      {

         if (ticTac[i][j] == ' ')
         {
            ticTac[i][j] =  '.';
         }
         fileTwo << ticTac[i][j];
         fileTwo << ' ';

      }
      fileTwo << endl;

   }

}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   char ticTac[3][3];
   readFile(ticTac);
   display(ticTac);
   displayTwoFile(ticTac);
   cout << "File written\n";
   return 0;
}
