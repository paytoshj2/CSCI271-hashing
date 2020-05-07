#include <iostream>
#include <string>
#include "hash.h"
#include <cstdlib>
#include <fstream>
using namespace std;

/*
  NAME: Joshua Paytosh
  PROGRAM: main.cpp
  PURPOSE: to test the hash class

*/


// hash function
int hashfunction(string word, int size);


int main(int argc, char* argv[])
{
  // keeps track of index
  int index;

  // Makes sure arg was entered
  if(argc < 2)
  {
    cout << "Please enter table size as an argument\n";
    exit(1);
  }

  int size = atoi(argv[1]);
  Hash<string> test(size);

  ifstream infile;
  infile.open("DATAFILE.dat", ios::in);
  if(infile.fail())
  {
    cout << "File failed to open, please check the filename in the code!\n";
    exit(1);
  }


// Read in
  string data;
  int foundstatus;
  infile >> data;
  for(int i = 0; i < 200000; i++)
  {
      test.insert(hashfunction(data, size), data);

      infile >> data;

  }





  ifstream infile2;
  infile2.open("/home/win.thackerw/271/search.dat", ios::in);
  if(infile2.fail())
  {
    cout << "SECOND FILE FAILED TO OPEN\n";
    exit(1);
  }


  int i = 0;
  while(infile2 >> data)
  {
    foundstatus = -1;

    index = hashfunction(data, size);
    // Foundstatus returns the index at which it is found
    foundstatus = test.search(data, index);
  i++;
  }
  // Returns values were keeping track of
  cout << "ITEMS NOT FOUND " << test.getFail() << endl;
  cout << "ITEMS FOUND " << test.getSuccess() << endl;
  cout << "NUMBER OF PROBES " << test.getProbes() << endl;

}

// Hash function
int hashfunction(string word, int size)
{

  long sum = word[0];
  for(int k = 1;k < word.length(); k++)
  {
    sum += (((sum * (int)word[k]) / 19) + 13) % size;
  }
  return sum % size;

}
