#include <iostream>

#include "BinarySearchTree.hpp"
#include "HashTable.hpp"
#include "SeparateChaining.hpp"
#include "TrieTree.hpp"

using namespace std;

int main()
{
    TrieNode* trie = new TrieNode();

    trie->insert("thithigrao");
    trie->insert("lolzinho69");
    trie->insert("lolzinho kaisa kda prestigio eu quero");
    trie->insert("lolzeira");
    trie->insert("usguri");
    trie->insert("alex andre");



    if(trie->search("thithigrao"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    
    if(trie->search("lolzinho69"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    if(trie->search("usguri"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    if(trie->search("alex andre"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    if(trie->search("lolzinho"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;



    vector<string> output = trie->search_prefix("lol");
    cout << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << endl;


    return 0;
}
