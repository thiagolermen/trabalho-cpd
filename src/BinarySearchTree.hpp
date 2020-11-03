#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <string>
#include <vector>

#include "SortedArray.hpp"

using namespace std;

class binaryNode{

    public:
        binaryNode* Lson;
        binaryNode* Rson;
        int movieId = 0;

        binaryNode(){ // constructor
            this->Lson = nullptr;
            this->Rson = nullptr;
            this->movieId = 0;
        }

    binaryNode* newNode(arrNode a);

    binaryNode* sArr_to_BBST(vector<arrNode> arr, int begin, int end);

    void printLeftWalk(binaryNode* node);
};

#endif