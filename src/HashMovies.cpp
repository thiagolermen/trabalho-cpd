#include "HashMovies.hpp"
#include "Movie.hpp"

using namespace std;

HashMovies::HashMovies(int sz){
    this->TABLE_SIZE = sz;
    table = new list<Movie*>[TABLE_SIZE];
}

// Hash function from map values to (hash) key
int HashMovies::hashFunction(int id){
    int index = 0;

    index = (id & 0x7fffffff) % TABLE_SIZE;

    return index;
}

void HashMovies::insertKey(Movie* key){
    int index = hashFunction(key->getMovieId()); // Get the hash index
    table[index].push_back(key); // Insert 'key' to the linked list at 'index'
}

Movie* HashMovies::search(int key){
    int index = hashFunction(key); // Get the hash index

    // Find the key in the list
    list<Movie*>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++)
        if ((*i)->getMovieId() == key) // The key has been found
            return *i;
    return nullptr;
}

int HashMovies::getTableSize(){
    return this->TABLE_SIZE;
}

void HashMovies::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ; i++){
        cout << i;
        for (auto x : table[i])
            cout << "-->" << x;
        cout << endl;
    }
}