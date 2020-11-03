#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class binaryNode{

    public:
        binaryNode* Lson;
        binaryNode* Rson;
        int movieId = 0;

        binaryNode(){ // constructor
            this->Lson = nullptr;
            this->Rson = nullptr;
        }

    void insert(int movie_id, string title, vector<string> genres);

    void search(int movie_id);
};

#endif