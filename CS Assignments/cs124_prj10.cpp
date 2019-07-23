/***********************************************************************
* Program:
*    Project 10, MadLib
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
*      Trying to edit the file while running through it!
************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
void askQuestion(char text[50], bool addSpace, bool addSpaceSpecial);

/**********************************************************************
 * Prototype for symbolCase
 ***********************************************************************/
void symbolCase(char* text, bool addSpace);


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
 * Basic function gets name of file
 ***********************************************************************/
bool shoudAddSpace(char madLib[][50], int x, int length)
{
   if (x == length)
   {
      return false;
   }
   return !(strcmp (madLib[x + 1],".") == 0
      || strcmp (madLib[x + 1],",") == 0
      || strcmp (madLib[x + 1],"!") == 0
      || strcmp (madLib[x + 1],"<#>") == 0
      || strcmp (madLib[x + 1],"<{>") == 0
      || strcmp (madLib[x + 1],"<}>") == 0
      || strcmp (madLib[x + 1],"<[>") == 0
      || strcmp (madLib[x + 1],"<]>") == 0
      || strcmp (madLib[x + 1],"?") == 0
      || strcmp (madLib[x],"<#>") == 0);
}

/**********************************************************************
 * Basic function gets name of file
 ***********************************************************************/
bool shoudAddSpaceSpecial(char madLib[][50], int x, int length)
{
   if (x == length)
   {
      return false;
   }
   return !(strcmp (madLib[x - 1],"\n") == 0
        || ((strcmp (madLib[x + 1],"<{>") == 0)
        && (strcmp (madLib[x], "<}>") == 0))
        || ((strcmp (madLib[x + 1],"<#>") == 0)
        && (strcmp (madLib[x], "<}>") == 0)));
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
   int i = 0;

   for (i = 0; i < 300; i++)
   {
      if (!(txtFile >> madLib[i]))
      {
         break;
      }
   }

   cin.ignore();
   for (x = 0; x <= i; x++)      // basic for loop
   {
      if (madLib[x][0] == '<')
      {
         askQuestion(madLib[x], shoudAddSpace(madLib, x, i),
            shoudAddSpaceSpecial(madLib,x,i));
      }
      else
      {
         if (shoudAddSpace(madLib, x, i))
         {
            strcat(madLib[x], " ");
         }
      }

   }
   cout << endl;
   txtFile.close();
   return x;





}

/**********************************************************************
 * Function that gets called whenever there is a "<" in the file
 * it checks to see if a string is a letter or symbol
 ***********************************************************************/
void askQuestion(char text[50], bool addSpace, bool addSpaceSpecial)
{
   if (!isalpha(text[1]))
   {
      symbolCase(text, addSpaceSpecial);
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
   cin.getline(text, 256);

   if (addSpace)
   {
      strcat(text, " ");
   }

}

/**********************************************************************
 * Function that subs symbols with specific cases
 ***********************************************************************/
void symbolCase(char* text, bool addSpace)
{
   switch (text[1])
   {
      case '#' :
         strcpy(text, "\n");
         break;
      case '{' :
         if (addSpace)
         {
            strcpy(text, " \"");
         }
         else
         {
            strcpy(text, "\"");
         }
         break;
      case '}' :
         if (addSpace)
         {
            strcpy(text, "\" ");
         }
         else
         {
            strcpy(text, "\"");
         }

         break;
      case '[' :
         if (addSpace)
         {
            strcpy(text, " \'");
         }
         else
         {
            strcpy(text, "\'");
         }
         break;
      case ']' :
         if (addSpace)
         {
            strcpy(text, "\' ");
         }
         else
         {
            strcpy(text, "\'");
         }
         break;


   }
}

/**********************************************************************
 * Basic display function in prep for next section of this project
 ***********************************************************************/
void display (char madLib[][50], int length)
{
   for (int x = 0; x < length; x++)
   {
      cout << madLib[x] ;
   }
   cout << endl;
}

/**********************************************************************
 * Simple main function that creates space for the file to be copied
 ***********************************************************************/
int main()
{
   char cont = 'y';
   char madLib[300][50];
   while (cont == 'y')
   {
      int length = readFile(madLib);
      display(madLib, length);
      cout << "Do you want to play again (y/n)? ";
      cin >> cont;
      //Clear madLib
      for (int k = 0; k < 300; k++)
      {
         for (int j = 0; j < 50; j++)
         {
            madLib[k][j] = '\0';
         }
      }
   }

   cout << "Thank you for playing.\n";
   return 0;
}
