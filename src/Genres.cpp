#include "Genres.hpp"

using namespace std;

Genres::Genres(string name){
    this->name = name;
    this->movies = {};
}

string Genres::getName(){
    return this->name;
}

void Genres::setName(string name){
    this->name = name;
}