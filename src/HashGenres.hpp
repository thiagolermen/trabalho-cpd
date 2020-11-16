#ifndef HASH_GENRES_H
#define HASH_GENRES_H

#include <list>
#include <string>
#include <cmath>
#include "Genres.hpp"

using namespace std;

// Hash Map, using separate chaining, declaration
class HashGenres{

    // Data members can be accessed using methods
    private:
        int TABLE_SIZE;
        list<Genres*> *table; // Pointer to an array containing the lists
    
    // Methods
    public:

        // Constructor
        HashGenres(int sz);
        
        // Inserts a key into hash table
        void insertKey(string x, int movie_id);

        // search for a string and returns a pointer to this string in the hash structure
        Genres* search(string key);

        // search for a string and return true if it exists, else false
        bool exists(string key, int index);

        // receives a string and returns a unsigned value representing this string
        unsigned hashCode(string s);

        // Hash function from map values to (hash) key
        int hashFunction(string s);

        int getTableSize();

        void printHashTable();

};
#endif