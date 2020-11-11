#include "TrieTreeTag.hpp"

using namespace std;

void TrieNodeTag::insert(int movie_id, string tag){
    // starts from the root node
    TrieNodeTag* current = this;

    for(int i = 0; i < tag.size(); i++){
        // if the path doesnt exists uses the constructor to create a new node
        if(current->children[tag[i]] == nullptr)
            current->children[tag[i]] = new TrieNodeTag();

        // walk to the next node
        current = current->children[tag[i]];
    }
    // set current node as the end of the string
    current->isEndOfWord = true;
    bool exists = false;
    for (int i=0;i<current->movieIds.size();i++)
        if(current->movieIds[i] == movie_id)
            exists = true;
    if (!exists)
        current->movieIds.push_back(movie_id);
}

vector<int> TrieNodeTag::search(string input){
    vector<int> j;
    // returns false if the tree is empty
    if(this == nullptr)
        return j;

    TrieNodeTag* current = this;

    for(int i = 0; i < input.size(); i++){
        // go to next node
        current = current->children[input[i]];

        // check if the current character is on the path
        if(current == nullptr)
            return j;
    }
    // returning the flag that says if the current character is the end of the string
    return current->movieIds;
}