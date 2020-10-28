#ifndef TRIE_TREE
#define TRIE_TREE

#include <iostream>
#include <string>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNode{

    public:
        TrieNode* children[USED_ALPHABET_SIZE];
        bool isEndOfWord;

        TrieNode()// Constructor
        {
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++)
            {
                this->children[i] = nullptr;
            }
        }

    void insert(string input);

    bool search(string input);

};

#endif