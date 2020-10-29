#ifndef SEPARATE_CHAINING
#define SEPARATE_CHAINING

#include <list>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;


// Hash Map, using separate chaining, declaration
class SeparateChainingHash{

    // Data members can be accessed using methods
    private:
        int TABLE_SIZE;
        list<string> *table; // Pointer to an array containing the lists
    
    // Methods
    public:

        SeparateChainingHash(int sz); // Constructor
        
        unsigned hashCode(string s);

        int hashFunction(string s);

        void insertKey(string key);

        bool search(string key);

        int getTableSize();

        void printHashTable();

        

};

#endif