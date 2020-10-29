#ifndef TRIE_TREE
#define TRIE_TREE

#include <iostream>
#include <string>
#include <vector>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNode{

    public:
        TrieNode* children[USED_ALPHABET_SIZE];
        bool isEndOfWord;
        int movie_id;
        string word;
        vector<string> genres;

        TrieNode()// Constructor
        {
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++)
            {
                this->children[i] = nullptr;
            }
        }

    void insert(int movie_id, string title, vector<string> genres);

    bool search(string input);

    bool haveChildren(TrieNode* current);

    void walkThrough(vector<string> &output);

    vector<string> search_prefix(string input);

};

#endif