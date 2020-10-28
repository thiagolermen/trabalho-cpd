#include "TrieTree.hpp"

using namespace std;


void TrieNode::insert(string input)
{
    // starts from the root node
    TrieNode* current = this;

    for(int i = 0; i < input.size(); i++)
    {
        // if the path doesnt exists uses the constructor to create a new node
        if(current->children[input[i]] == nullptr)
            current->children[input[i]] = new TrieNode();

        // walk to the next node
        current = current->children[input[i]];
    }
    // set current node as the end of the string
    current->isEndOfWord = true;
}

bool TrieNode::search(string input)
{
    // returns false if the tree is empty
    if(this == nullptr)
        return false;

    TrieNode* current = this;

    for(int i = 0; i < input.size(); i++)
    {
        // go to next node
        current = current->children[input[i]];

        // check if the current character is on the path
        if(current == nullptr)
            return false;
    }
    // returning the flag that says if the current character is the end of the string
    return current->isEndOfWord;
}