#ifndef HASH_USERS_H
#define HASH_USERS_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>

#include "User.hpp"

using namespace std;

class HashUsers{

    // Data members can be accessed using methods
    private:
        int TABLE_SIZE;
    
    // Methods
    public:

        list<User*> *table; // Pointer to an array containing the lists

        HashUsers(int sz); // Constructor
        
        unsigned hashCode(int id); // Generates a hash code for an user id

        int hashFunction(int id); // Generates a hash index for an user id

        void insertKey(User* key); // Insert a new value in the hash table

        User* search(int id); // Search for a key in hash table

        int getTableSize(); // get the table size

        void printHashTable(); // proint the hash table (for tests)
};

#endif