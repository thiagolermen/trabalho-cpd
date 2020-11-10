#ifndef GENRES_H
#define GENRES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Genres{
    private:
        string name;
        
    public:
        vector<int> movies;
        
        // Constructor
        Genres(string name);

        // Getters and Setters
        string getName();
        void setName(string title);

};

#endif