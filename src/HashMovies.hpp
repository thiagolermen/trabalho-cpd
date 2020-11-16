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

        // Pointer to an array containing the lists
        list<Movie*> *table;

        // Constructor
        HashMovies(int sz);
        
        // receives a string and returns a unsigned value representing this string
        unsigned hashCode(int id);

        // receives an integer and return the respective code to the hash
        int hashFunction(int id);

        // insert the movie in the hash
        void insertKey(Movie* key);

        // returns a pointer to the movie node by searching for the respective ID
        Movie* search(int id);

        int getTableSize();

        void printHashTable();
};

#endif