#ifndef TRIE_TREE_MOVIE_H
#define TRIE_TREE_MOVIE_H

#include <iostream>
#include <string>
#include <vector>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNodeMovie{

    public:
        TrieNodeMovie* children[USED_ALPHABET_SIZE];
        bool isEndOfWord;
        int movieId;
        string word;

        TrieNodeMovie(){// Constructor
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++)
                this->children[i] = nullptr;
        }

    void insert(int movie_id, string title);

    int search(string input);

    bool haveChildren(TrieNodeMovie* current);

    void walkThrough(vector<string> &output);

    vector<string> search_prefix(string input);

    vector<int> search_prefix_id(string input);
};

#endif