/* file handling
ofstream: Stream class to write on files
ifstream: Stream class to read from files
fstream: Stream class to both read and write from/to files.

A file must be opened before you can read from it or write to it.


*/

#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   string data;

   // open a file in write mode.
   ofstream outfile;
   outfile.open("afile.dat", ios::out | ios::app);

   cout << "Enter your full name: "; 
   getline(cin, data);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();//istream& ignore (streamsize n = 1, int delim = EOF);
   
   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   //============================
   // open a file in read mode.
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // again read the data from the file and display it.
   infile >> data; 
   cout << data << endl; 

   // close the opened file.
   infile.close();

   return 0;
   
}
