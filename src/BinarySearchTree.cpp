#include "BinarySearchTree.hpp"

using namespace std;

binaryNode* binaryNode::newNode(arrNode a){
    binaryNode* node = new binaryNode();
    node->movieId = a.movieId;

    return node;
}

binaryNode* binaryNode::sArr_to_BBST(vector<arrNode> arr, int start, int end){

    if(start > end)
        return nullptr;

    // gets the array middle element and make it a root
    int middle = (start + end) / 2;
    binaryNode* root = newNode(arr[middle]);

    // recursively build the left subtree
    root->Lson = sArr_to_BBST(arr, start, middle - 1);

    // recursively build the right subtree
    root->Rson = sArr_to_BBST(arr, middle + 1, end);

    return root;
}

void binaryNode::printLeftWalk(binaryNode* node){

    if(node->movieId == 0)
        return;
    
    cout << node->movieId << "ate aki ";
    printLeftWalk(node->Lson);
    printLeftWalk(node->Rson);
}