#include "HashGenres.hpp"

using namespace std;

HashGenres::HashGenres(int sz){
    this->TABLE_SIZE = sz;
    table = new list<Genres*>[TABLE_SIZE];
}

void HashGenres::insertKey(string key, int movie_id){
    int index = hashFunction(key); // Get the hash inde
    if (!exists(key, index)){
        Genres* genre = new Genres(key);
        genre->movies.push_back(movie_id);
        table[index].push_back(genre); // Insert 'key' to the linked list at 'index'
    }else{
        Genres* genre = search(key);
        genre->movies.push_back(movie_id);
    }
}

bool HashGenres::exists(string key, int index){
    list<Genres*>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++)
        if ((*i)->getName() == key)// The key has been found
            return true;

    return false;
}

Genres* HashGenres::search(string key){
    int index = hashFunction(key);
    list<Genres*>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++)
        if ((*i)->getName() == key)// The key has been found
            return *i;

    return nullptr;
}

unsigned HashGenres::hashCode(string s){
    unsigned hash = 0;
    for (int i = 0 ; i < s.length() ; i++)
        hash = s[i] + (31 * hash);

    return hash;
}

int HashGenres::hashFunction(string s){
    int index = 0;
    unsigned hash_code = hashCode(s);

    index = (hash_code & 0x7fffffff) % TABLE_SIZE;

    return index;
}

int HashGenres::getTableSize(){
    return this->TABLE_SIZE;
}

void HashGenres::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ; i++){
        cout << i;
        for (auto x : table[i]){
            cout << " --> " << x->getName() << "|";
            for (int i=0 ; i< x->movies.size(); i++)
                cout << x->movies[i] << ",";
            cout << endl; 
        }
        cout << endl;
    }
}