#ifndef hash_h
#define hash_h

#include <iostream>
#include <string>


/*

  name: Joshua Paytosh
  Program: hash.h
  Purpose: the header file to create a hash table for the purposes of searching


*/
using namespace std;
template <class W>
struct hashtable{
  int valstatus;
  W item;
};

// Hash class
template <class W>
class Hash
{
  // Private members
  private:
    int size;
    // Struct with data and whether it is set or not
    hashtable<W>* hashtab;
    // Keeps track of data for the table
    int probes;
    int success;
    int fail;
  public:
    // Constructors
    Hash();
    Hash(int a);
    // Member functions
    void insert(int index, W data);
    int getSize();
    int search(W data, int startIndex);
    int getProbes();
    int getSuccess();
    int getFail();

};



template <typename W>
Hash<W>::Hash()
{
  size = 0;
  success = 0;
  fail = 0;
  probes = 1;
  hashtab = new hashtable<W>[size];
  for(int i = 0; i < size; i++)
  {
    hashtab[i].valstatus = 0;
  }
}


template <typename W>
Hash<W>::Hash(int a)
{
  success = 0;
  fail = 0;
  size = a;
  probes = 0;
  hashtab = new hashtable<W>[size];
  for(int i = 0; i < size; i++)
  {
    hashtab[i].valstatus = 0;
  }
}
template <typename W>
int Hash<W>::search(W data, int startIndex)
{

  int tempindex;
  tempindex = startIndex;
  if(hashtab[startIndex].item == data)
  {
    // initial search
    probes++;
    success++;
    return startIndex;
  }
  else
  {
    // increment startIndex so it works
    startIndex++;
    // If the array reaches a full loop
    while(startIndex!=tempindex)
    {
      if(hashtab[startIndex].valstatus == 0)
      {
        // not here
        probes++;
        fail++;
        return -1;
      }
      else
      {
        // val may be in here
        if(hashtab[startIndex].item == data)
        {
          probes++;
          success++;
          return startIndex;
        }
        else
        {
          // continue iterating
          probes++;
          startIndex++;
        }
      }

    }
  }

}


template <typename W>
int Hash<W>::getSize()
{
  return size;
}

template <typename W>
void Hash<W>::insert(int index, W data)
{


// loop until you find a 1
  while(hashtab[index].valstatus == 1)
  {
    index = (index + 1)%size;
  }
  // insert it
  hashtab[index].item = data;
  hashtab[index].valstatus = 1;


}

template <typename W>
int Hash<W>::getProbes()
{
  return probes;
}
template <typename W>
int Hash<W>::getSuccess()
{
  return success;
}
template <typename W>
int Hash<W>::getFail()
{
  return fail;
}


#endif
