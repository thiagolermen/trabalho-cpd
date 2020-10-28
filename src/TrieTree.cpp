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

bool TrieNode::haveChildren(TrieNode* current)
{
    for(int i = 0; i < USED_ALPHABET_SIZE; i++)
    {
        if(current->children[i])
            return true;
    }
    return false;
}

vector<string> TrieNode::search_prefix(string input)
{
    vector<string> output;

    // returns "empty tree" if the tree is empty
    if(this == nullptr)
    {
        output.push_back("empty tree");
        return output;
    }
    
    TrieNode* current = this;

    // cheack if the prefix is on the tree, if not, return
    for(int i = 0; i < input.size(); i++)
    {
        // go to next node
        current = current->children[input[i]];

        // check if the current character is on the path
        if(current == nullptr)
        {
            output.clear();
            output.push_back("string or prefix not found");
            return output;
        }

    }

    // if the prefix is on the tree, return all children
    //  to do ..
}