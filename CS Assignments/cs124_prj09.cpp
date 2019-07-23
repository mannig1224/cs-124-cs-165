/***********************************************************************
* Program:
*    Project 09, MadLib
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
* A program that reads a file in order to play a game called
* madLib reads through the file and copies it to an array in which
* we modify the file as we copy it into the array.
*
*
*    Estimated:  1.0 hrs
*    Actual:     4.0 hrs
*      Understanding pass-by reference and passing only addresses
*
************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
/**********************************************************************
 * Prototype for readFile
 ***********************************************************************/
int readFile(char madLib[][50]);

/**********************************************************************
 * Prototype for getName
 ***********************************************************************/
void getName(char fileName[]);

/**********************************************************************
 * Prototype for askQuestion
 ***********************************************************************/
void askQuestion(char text[50]);

/**********************************************************************
 * Prototype for symbolCase
 ***********************************************************************/
const char* symbolCase(char text);

/**********************************************************************
 * Prototype for display
 ***********************************************************************/
void display (char madLib[][50], int length);


/**********************************************************************
 * Basic function gets name of file
 ***********************************************************************/
void getName(char fileName[])      // function that calls for the file name
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;

}

/**********************************************************************
 * Function the gets name of file from getName, opens it, copies it
 * and closes file
 ***********************************************************************/
int readFile(char madLib[][50])   // function that opens the file and copies it
{
   char fileName[300];
   getName(fileName);
   ifstream txtFile(fileName);

   if (txtFile.fail())            // checking if the file fails to open
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
      exit(0);
   }

   int x = 0;
   for (x = 0; x < 300; x++)      // basic for loop
   {
      if (!(txtFile >> madLib[x]))
      {
         break;
      }
      if (madLib[x][0] == '<')
      {
         askQuestion(madLib[x]);
      }
   }
   return x;





}

/**********************************************************************
 * Function that gets called whenever there is a "<" in the file
 * it checks to see if a string is a letter or symbol
 ***********************************************************************/
void askQuestion(char text[50])
{
   if (!isalpha(text[1]))
   {
      symbolCase(text[1]);
      return;
   }

   cout << "\t" << (char) toupper(text[1]);
   for (int x = 2; x < 50; x++ )
   {

      if (text[x] == '>')
      {
         break;
      }

      if (text[x] != '_')
      {
         cout << text[x];

      }
      else
      {
         cout << " ";
      }


   }
   cout << ": ";
   cin.ignore();
   cin.getline(text, 256);

}

/**********************************************************************
 * Function that subs symbols with specific cases
 ***********************************************************************/
const char*  symbolCase(char text)
{
   switch (text)
   {
      case '#' : return "\n";
      break;
      case '{' : return " \"";
      break;
      case '}' : return "\" ";
      break;
      case '[' : return " \'";
      break;
      case ']' : return "\' ";
      break;

   }
   return "BAD THINGS HAPPENED";
}

/**********************************************************************
 * Basic display function in prep for next section of this project
 ***********************************************************************/
void display (char madLib[][50], int length)
{
   for (int x = 0; x < length; x++)
   {

   }
   cout << "Thank you for playing.\n";
}

/**********************************************************************
 * Simple main function that creates space for the file to be copied
 ***********************************************************************/
int main()
{
   char madLib[300][50];
   int length = readFile(madLib);
   display(madLib, length);
   return 0;
}
