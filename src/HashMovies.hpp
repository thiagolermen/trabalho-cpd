#ifndef HASH_MOVIES_H
#define HASH_MOVIES_H

#include <list>
#include <cmath>
#include <string>
#include <iostream>

#include "Movie.hpp"

using namespace std;

// Hash Map, using separate chaining, declaration
class HashMovies{

    // Data members can be accessed using methods
    private:
        int TABLE_SIZE;
    
    // Methods
    public:

        list<Movie*> *table; // Pointer to an array containing the lists

        HashMovies(int sz); // Constructor
        
        unsigned hashCode(int id);

        int hashFunction(int id);

        void insertKey(Movie* key);

        Movie* search(int id);

        int getTableSize();

        void printHashTable();
};

#endif