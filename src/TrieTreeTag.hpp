#ifndef TRIE_TREE_TAG_H
#define TRIE_TREE_TAG_H

#include <iostream>
#include <string>
#include <vector>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNodeTag{

    public:
        // array of alphabet symbols (pointer to a charachter related to the last charachter)
        TrieNodeTag* children[USED_ALPHABET_SIZE];
        bool isEndOfWord; // boolean to check if the node is th end of word
        vector<int> movieIds; // vector including all movies_id that that have the prefix
        string tag; // if isEndOfWord is true include the string tag

        // Constructor
        TrieNodeTag(){
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++){
                this->children[i] = nullptr;
            }
        }

    void insert(int movie_id, string tag); // insert a new tag

    // given a input, search for the string given and returns a vector of movies_ids that have the input 
    vector<int> search(string input); 

};

#endif