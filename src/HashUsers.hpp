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
        
        unsigned hashCode(int id);

        int hashFunction(int id);

        void insertKey(User* key);

        User* search(int id);

        int getTableSize();

        void printHashTable();
};

#endif