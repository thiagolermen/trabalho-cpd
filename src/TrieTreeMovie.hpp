#ifndef TRIE_TREE_MOVIE_H
#define TRIE_TREE_MOVIE_H

#include <iostream>
#include <string>
#include <vector>

#define USED_ALPHABET_SIZE 128

using namespace std;

class TrieNodeMovie{

    public:
        // array with all alphabet symbols, pointer to a new charachter
        TrieNodeMovie* children[USED_ALPHABET_SIZE];
        bool isEndOfWord; // boolean to check the node is end of any word
        int movieId; // if isEndOfWord is true includes the movie_id of the current word
        string word; // if isEndOfWord is true includes the name(string) of the current word

        // Constructor
        TrieNodeMovie(){
            this->isEndOfWord = false;

            for(int i = 0; i < USED_ALPHABET_SIZE; i++){
                this->children[i] = nullptr;
            }
        }

    // Inser a new word in the tree
    void insert(int movie_id, string title);
    // Given an input, search for a word in a tree and retrurn the movie_id if found
    int search(string input);

    // Check if a given node has a children
    bool haveChildren(TrieNodeMovie* current);

    // Goes through the vector of alphabet symbols
    void walkThrough(vector<string> &output);

    // Search for a given input (prefix) in the trie and returns all the words that have the given prefix
    vector<string> search_prefix(string input);

    // Search for a given input (prefix) in the trie and returns all the movie_ids that have the given prefix
    vector<int> search_prefix_id(string input);

};

#endif