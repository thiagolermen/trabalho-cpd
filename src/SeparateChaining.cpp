#include "SeparateChaining.hpp"

using namespace std;

SeparateChainingHash::SeparateChainingHash(int sz){
    this->TABLE_SIZE = sz;
    table = new list<string>[TABLE_SIZE];
}

unsigned SeparateChainingHash::hashCode(string s){
    unsigned hash = 0;
    for (int i = 0 ; i < s.length() ; i++){
        hash = s[i] + (31 * hash);
    }
    return hash;
}

// Hash function from map values to (hash) key
int SeparateChainingHash::hashFunction(string s){

    int index = 0;
    unsigned hash_code = hashCode(s);

    index = (hash_code & 0x7fffffff) % TABLE_SIZE;

    return index;
}


void SeparateChainingHash::insertKey(string key){

    int index = hashFunction(key); // Get the hash index
    //int index = hashFunction2(key); // Get the hash index
    table[index].push_back(key); // Insert 'key' to the linked list at 'index'

}

bool SeparateChainingHash::search(string key){

    int index = hashFunction(key); // Get the hash index

    // Find the key in the list
    list<string>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++)
        if (*i == key) // The key has been found
            return true;
    return false;
}

int SeparateChainingHash::getTableSize(){
    return this->TABLE_SIZE;
}

void SeparateChainingHash::printHashTable(){
    for (int i = 0 ; i < TABLE_SIZE ; i++){
        cout << i;
        for (auto x : table[i]){
            cout << "-->" << x;
        }
        cout << endl;
    }
}