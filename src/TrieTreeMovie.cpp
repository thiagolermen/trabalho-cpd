#include "TrieTreeMovie.hpp"

using namespace std;

// Insert a word in the tree
void TrieNodeMovie::insert(int movie_id, string title)
{
    // starts from the root node
    TrieNodeMovie* current = this;

    // Goes through each charachter
    for(int i = 0; i < title.size(); i++)
    {
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

// Check if a given node has children
bool TrieNodeMovie::haveChildren(TrieNodeMovie* current)
{
    for(int i = 0; i < USED_ALPHABET_SIZE; i++)
        if(current->children[i])
            return true;
    return false;
}

// Goes through each symbol of the alphabet searching for a specific symbol
void TrieNodeMovie::walkThrough(vector<string> &output){
    
    if (this->isEndOfWord)
        output.push_back(this->word);

    for(int i = 0; i < USED_ALPHABET_SIZE; i++)
        if (this->children[i] != nullptr)
            this->children[i]->walkThrough(output);
}

// Search for a given word in the tree and return all the words that have the given prefix
vector<string> TrieNodeMovie::search_prefix(string input)
{
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

// Search for a given word in the tree and return all the movie_ids that have the given prefix
vector<int> TrieNodeMovie::search_prefix_id(string input)
{
    vector<int> output;

    // Search for all words that have the given prefix
    vector<string> aux = search_prefix(input);

    // Find the movie_ids related to the words found
    for(int i = 0; i< aux.size(); i++){
        int k = search(aux[i]);
        if (k != -1)
            output.push_back(k);
    }
    return output; 
}

