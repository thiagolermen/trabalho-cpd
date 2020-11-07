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

using namespace std;


// Sorted list of the implemented auxiliary functions

    void printVector_int(vector<int> input);

    void printVector_string(vector<string> input);

    vector<Movie*> loadMovie(string name);

    vector<tuple<int, string>> loadTag(string name);

    void loadMiniRating(string name, HashUsers* hash);
    
    TrieNodeMovie* loadTrieTreeMovie(vector<Movie*> movies);



#endif