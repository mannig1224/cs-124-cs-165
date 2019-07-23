/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Ridges, CS124
* Author:
*    Emmanuel Gatica
* Summary:
*      Program that reads a sudoku board and lets you play it.
*
*
*    Estimated:
*    Actual:     6.0 hrs
*
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(int sudokuBoard[][9], char fileName[]);
void getName(char fileName[]);
void display(int sudokuBoard[][9]);
void interact();
void getSecondFile(char secondFile[]);
void writeFile (int sudokuBoard[][9]);
void modifyValue(int sudokuBoard[][9]);

/**********************************************************************
* Main: Calls other functions. Starting of program.
***********************************************************************/
int main()
{
   //Creating Space to read file into
   int sudokuBoard[9][9];
   // Create an empty array for the name of the file to be opened
   char fileName[256];

   //Calling other functions/pass array
   getName(fileName);

   readFile(sudokuBoard,fileName);
   interact();
   display(sudokuBoard);

   while (true)
   {
      char x;
      cout << endl << "> ";
      cin >> x;
      switch (x)
      {
         case '?':
            interact();
            break;
         case 'D':
            display(sudokuBoard);
            break;
         case 'E':
            modifyValue(sudokuBoard);
            break;
         case 'S':
            break;
         case 'Q':
            writeFile(sudokuBoard);
            exit(0);
            break;
         default:
            cout << "ERROR: Invalid command\n";
            interact();
      }
   }



   return 0;
}


/**********************************************************************
* readFile: reads file into array originally stated in main
***********************************************************************/
void readFile(int sudokuBoard[][9], char fileName[])
{



   ifstream sudokuFile(fileName);


   if (sudokuFile.fail())            // checking if the file fails to open
   {
      cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
      exit(0);
   }

   int i = 0;
   int j = 0;
   char temp[10];
   for (i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         if (!(sudokuFile >> temp))
         {
            break;
         }
         sudokuBoard[i][j] = (int)(temp[0] - '0');
      }

   }

   sudokuFile.close();
}


/**********************************************************************
* getName: Gets name of file we are reading from
***********************************************************************/
void getName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
   cin.ignore();

}

/**********************************************************************
* display: displays sudokuBoard called from main
***********************************************************************/
void display(int sudokuBoard[][9])
{

    //Display Column Header
   cout << "   A B C D E F G H I" << endl;



   int i = 0;
   int j = 0;
   for (i = 0; i < 9; i++)
   {
      if (i == 3 || i == 6)
      {
         cout << "   -----+-----+-----\n";
      }

      cout << i + 1 << " ";
      for (j = 0; j < 9; j++)
      {
         if (j == 3 || j == 6)
         {
            cout << '|';
         }
         else
         {
            cout << " ";
         }


         if (sudokuBoard[i][j] == 0)
         {
             cout << ' ';
         }
         else
         {
            cout << sudokuBoard[i][j];
         }



      }

      cout << endl;

   }
}


/*************************************************************************
* Interact: Allows the user to interact and manipulate the game board.
************************************************************************/
void interact()
{

   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << "\n";

   return;
}

/**********************************************************************
* writeFile: saves file. called from main
***********************************************************************/
void writeFile (int sudokuBoard[][9])
{
   char secondFile[256];
   ofstream fileTwo;
   getSecondFile(secondFile);
   fileTwo.open(secondFile);

   int i = 0;
   int j = 0;
   for (i = 0; i < 9; i++)
   {
      for (j = 0; j < 9; j++)
      {

         fileTwo << sudokuBoard[i][j];
         fileTwo << ' ';

      }

      fileTwo << endl;

   }
   cout << "Board written successfully\n";
}

/**********************************************************************
* getSecondFile: gets the name of the destination file
***********************************************************************/
void getSecondFile(char secondFile[])
{
   cout << "What file would you like to write your board to: ";
   cin >> secondFile;
}

/**********************************************************************
* modifyValue: Lets you modify the value of the board
***********************************************************************/
void modifyValue(int sudokuBoard[][9])
{

   char letter;
   int number;
   int value = 0;


   cout << "What are the coordinates of the square: ";
   cin  >> letter >> number;

   if (sudokuBoard[number - 1][letter - 65] != 0)
   {
      cout << "ERROR: Square \'" << letter << number << "\' is filled\n";


   }
   else
   {
      //Gets value to place in specified coordinates
      cout << "What is the value at \'" << letter << number << "\': ";
      cin  >> value;

      //Makes sure value is within correct range
      if (value < 1 || value > 9)
      {
         cout << "ERROR: Value \'" <<
            value << "\' in square \'" << letter << number << "\' is invalid\n";
         cout << "\n";

      }

      sudokuBoard[number - 1][letter - 65] = value;

   }

   return;
}
