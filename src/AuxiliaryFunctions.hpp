#ifndef AUXILIARY_FUNCTIONS
#define AUXILIARY_FUNCTIONS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>

#include "Movie.hpp"
#include "User.hpp"
#include "HashUsers.hpp"
#include "HashMovies.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"

using namespace std;

    void printVector_int(vector<int> input);

    void printVector_string(vector<string> input);

    vector<Movie*> loadMovie(string name);

    vector<tuple<int, string>> loadTag(string name);

    void loadMiniRating(string name, HashUsers* hash);
    
    TrieNodeMovie* loadTrieTreeMovie(vector<Movie*> movies);

    TrieNodeTag* loadTrieTreeTag(vector<tuple<int, string>> id_name);

    void setRatingByUsers(HashUsers* users, HashMovies* movies);



#endif