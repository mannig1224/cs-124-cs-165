/***********************************************************************
* Program:
*    Assignment 03, Digital Forensic
*    Brother Alvey, CS165
* Author:
*    Emmanuel Gatica
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

typedef struct accessRecord
{
   string username;
   string filename;
   long timestamp;
}
accessRecord;

void getName(string &filename);
void promptTime(long &start, long &stop);
int parseFile(accessRecord data[], string fileName);
void parseLine(string str, accessRecord *tempStruct);
void sortList(accessRecord input[500], int len);
void printRecordsInInterval(accessRecord recs [],
     int len, long start, long stop);
void printRecord(accessRecord rec);


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   accessRecord data[500];
   long start;
   long stop;
   string fileName;
   getName(fileName);

   int len = parseFile(data, fileName);
   promptTime(start, stop);
   cout << endl;
   sortList(data, len);
   printRecordsInInterval(data, len, start, stop);

}

/**********************************************************************
 * Function: getName
 * Purpose: This function gets the file name from the user
 ***********************************************************************/
void getName(string &fileName)
{
   cout << "Enter the access record file: ";
   getline(cin, fileName);


}

/**********************************************************************
 * Structure: promptTime
 * Purpose: Asks the user for the start and stop timestamp
 ***********************************************************************/
void promptTime(long &start, long &stop)
{
   cout << endl;
   cout << "Enter the start time: ";
   cin >> start;
   cin.ignore();
   cout << "Enter the end time: ";
   cin >> stop;
   cin.ignore();

}



/**********************************************************************
 * Structure: sortList
 * Purpose: Copies the structure into another structure in the order
 * least to greatest.
 ***********************************************************************/
void sortList(accessRecord input[500], int len)
{
   accessRecord output[500];

   for (int i = 0; i < len; i++)
   {
      accessRecord tempStruct = {};
      long minTimeStamp = 100000000000000;
      int minIndex = 0;

      for (int j = 0; j < len; j++)
      {
         // accessRecord data == accessRecord input
         if (input[i].timestamp < minTimeStamp)
         {
            minTimeStamp = input[i].timestamp;
            minIndex = i;
         }
      }
      output[minIndex] = input[minIndex];
      input[minIndex].timestamp = 100000000000000 + 1;
   }

   for (int i = 0; i < len; i++)
   {
      input[i] = output[i];
   }
}

/**********************************************************************
 * Structure: printRecordsInInterval
 * Purpose: This prints the format and also goes through the data and
 * picks out the ones the are between the start and end given by the
 * user.
 ***********************************************************************/
void printRecordsInInterval(accessRecord recs [],
    int len, long start, long stop)
{
   cout << "The following records match your criteria:";
   cout << endl;
   cout << endl;
   cout << setw(15) << "Timestamp" << setw(20) << "File"
      << setw(20) << "User";
   cout << endl;
   cout << "--------------- ------------------- -------------------";
   cout << endl;

   for (int i = 0; i < len; i++)
   {
      if (recs[i].timestamp > start && recs[i].timestamp < stop)
      {
         printRecord(recs[i]);
         cout << "\n";
      }

   }
   cout << "End of records";
   cout << endl;
}

/**********************************************************************
 * Structure: printRecord
 * Purpose: Prints the data
 ***********************************************************************/
void printRecord(accessRecord rec)
{
   cout << setw(15) << rec.timestamp
      << setw(20) << rec.filename
      << setw(20) << rec.username;
}

/**********************************************************************
 * Function: parseLine
 * Purpose: Goes through file line by line saving it into our struct of
 * arrays and checking for errors
 ***********************************************************************/
void parseLine(string str, accessRecord *tempStruct)
{
   string threeStrings[3];
   int arrayIndex = 0;

   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == ' ')
      {
         arrayIndex++;
         continue;
      }

      threeStrings[arrayIndex] += str[i];

   }

   tempStruct->filename = threeStrings[0];
   tempStruct->username = threeStrings[1];
   stringstream ss(threeStrings[2]);
   ss >> tempStruct->timestamp;




   if (ss.fail())
   {
      throw "Error parsing line: " + str;
   }
   if (tempStruct->timestamp < 1000000000)
   {
      throw "Error parsing line: " + str;
   }
   if (tempStruct->timestamp > 10000000000)
   {
      throw "Error parsing line: " + str;
   }
   if (arrayIndex != 2)
   {
      throw "Error parsing line: " + str;
   }

}


/**********************************************************************
 * Function: parseFile
 * Purpose: Opens file and calls parseLine through a try function to find
 * errors
 ***********************************************************************/
int parseFile(accessRecord data[], string fileName)
{
   ifstream input(fileName.c_str());
   string str;
   int index = 0;

   while (getline(input, str))
   {

      accessRecord tempStruct = {};
      try
      {
         parseLine(str, &tempStruct);
      }
      catch (string except)
      {
         cout << except << endl;
      }

      data[index] = tempStruct;
      index++;
   }

   return index;
}
