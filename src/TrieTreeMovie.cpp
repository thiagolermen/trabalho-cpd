#include "TrieTreeMovie.hpp"

using namespace std;

void TrieNodeMovie::insert(int movie_id, string title){
    // starts from the root node
    TrieNodeMovie* current = this;

    for(int i = 0; i < title.size(); i++){
        // if the path doesnt exists uses the constructor to create a new node
        if(current->children[title[i]] == nullptr)
            current->children[title[i]] = new TrieNodeMovie();

        // walk to the next node
        current = current->children[title[i]];
    }
    // set current node as the end of the string
    current->isEndOfWord = true;
    current->word = title;
    current->movieId = movie_id;
}

int TrieNodeMovie::search(string input){
    // returns false if the tree is empty
    if(this == nullptr)
        return -1;

    TrieNodeMovie* current = this;

    for(int i = 0; i < input.size(); i++){
        // go to next node
        current = current->children[input[i]];

        // check if the current character is on the path
        if(current == nullptr)
            return -1;
    }
    // returning the flag that says if the current character is the end of the string
    return current->movieId;
}

bool TrieNodeMovie::haveChildren(TrieNodeMovie* current){
    for(int i = 0; i < USED_ALPHABET_SIZE; i++)
        if(current->children[i])
            return true;
    return false;
}

void TrieNodeMovie::walkThrough(vector<string> &output){
    
    if (this->isEndOfWord)
        output.push_back(this->word);

    for(int i = 0; i < USED_ALPHABET_SIZE; i++)
        if (this->children[i] != nullptr)
            this->children[i]->walkThrough(output);
}

vector<string> TrieNodeMovie::search_prefix(string input){
    vector<string> output;

    // returns "empty tree" if the tree is empty
    if(this == nullptr){
        output.push_back("empty tree");
        return output;
    }
    
    TrieNodeMovie* current = this;

    // cheack if the prefix is on the tree, if not, return
    for(int i = 0; i < input.size(); i++){
        // go to next node
        current = current->children[input[i]];

        // check if the current character is on the path
        if(current == nullptr){
            output.clear();
            output.push_back("string or prefix not found");
            return output;
        }
    }

    // if the prefix is on the tree, return all children
    current->walkThrough(output);

    return output;
}

vector<int> TrieNodeMovie::search_prefix_id(string input){
    vector<int> output;

    vector<string> aux = search_prefix(input);

    for(int i = 0; i< aux.size(); i++){
        int k = search(aux[i]);
        if (k != -1)
            output.push_back(k);
    }
    return output; 
}

