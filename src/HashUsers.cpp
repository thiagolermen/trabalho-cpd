#include "HashUsers.hpp"

using namespace std;

HashUsers::HashUsers(int sz){
    this->TABLE_SIZE = sz;
    table = new list<User*>[TABLE_SIZE];
}

// Hash function from map values to (hash) key
int HashUsers::hashFunction(int id){
    int index = 0;

    index = (id & 0x7fffffff) % TABLE_SIZE;

    return index;
}

void HashUsers::insertKey(User* key){
    int index = hashFunction(key->getUserId()); // Get the hash index
    table[index].push_back(key); // Insert 'key' to the linked list at 'index'
}

User* HashUsers::search(int key){
    int index = hashFunction(key); // Get the hash index

    // Find the key in the list
    list<User*>::iterator i;
    for (i = table[index].begin() ; i != table[index].end() ; i++)
        if ((*i)->getUserId() == key) // The key has been found
            return *i;
    return nullptr;
}

int HashUsers::getTableSize(){
    return this->TABLE_SIZE;
}

void HashUsers::printHashTable(){
    for (int i = 0 ; i < 10 ; i++){
        cout << i;
        for (auto x : table[i]){
            cout << "-->" << x->getUserId() << ",";
            vector<tuple<int, float>> aux = x->getAnalysedMovies();
            for(int i=0;i<aux.size();i++)
                cout << get<0>(aux[i]) << "," << get<1>(aux[i]) << "|";
        }
        cout << endl;
    }
}