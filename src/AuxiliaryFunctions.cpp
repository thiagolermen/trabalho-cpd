#include "AuxiliaryFunctions.hpp"

using namespace std;

void printVector_string(vector<string> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << endl;
    }
}

void printVector_int(vector<int> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << endl;
    }
}

template<class T> T max(T a, T b){
    if(a > b)
        return a;
    return b;
}