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

        HashGenres(int sz); // Constructor
        
        // Inserts a key into hash table
        void insertKey(string x, int movie_id);

        Genres* search(string key);

        bool exists(string key, int index);

        unsigned hashCode(string s);

        // Hash function from map values to (hash) key
        int hashFunction(string s);

        int getTableSize();

        void printHashTable();

};
#endif