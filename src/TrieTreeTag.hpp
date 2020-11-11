#ifndef TRIE_TREE_TAG_H
#define TRIE_TREE_TAG_H

#include <iostream>
#include <string>
#include <vector>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNodeTag{

    public:
        TrieNodeTag* children[USED_ALPHABET_SIZE];
        bool isEndOfWord;
        vector<int> movieIds;
        string tag;

        TrieNodeTag(){// Constructor
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++)
                this->children[i] = nullptr;
        }

    void insert(int movie_id, string tag);

    vector<int> search(string input);
};

#endif