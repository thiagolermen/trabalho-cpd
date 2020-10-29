#include <iostream>

#include "TrieTree.hpp"
#include "BinarySearchTree.hpp"
#include "HashTable.hpp"
#include "SeparateChaining.hpp"

using namespace std;

void testTrieTree(){
    TrieNode* trie = new TrieNode();

    trie->insert(1, "thithigrao", {"Comédia"});
    trie->insert(2,"lolzinho69",{"Comédia"});
    trie->insert(3,"lolzinho kaisa kda prestigio eu quero",{"Comédia"});
    trie->insert(4,"lolzeira",{"Comédia"});
    trie->insert(5,"usguri",{"Comédia"});
    trie->insert(6,"alex andre",{"Comédia"});

    cout << "=====================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE" << endl;
    cout << "=====================================" << endl;
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
    cout << "Movie ID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << ";"<< endl;

    cout << "=====================================" << endl;
}
int main()
{
    testTrieTree();

    return 0;
}
