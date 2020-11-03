#ifndef SORTED_ARRAY
#define SORTED_ARRAY

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class arrNode{
    public:
        int movieId;
        string title;
        vector<string> genres;

        arrNode(int movieId, string title, vector<string> genres){// constructor
            this->movieId = movieId;
            this->title = title;
            this->genres = genres;
        }
};



#endif