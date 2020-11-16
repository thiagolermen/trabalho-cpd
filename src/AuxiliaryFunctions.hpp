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

    // print an integer vector
    void printVector_int(vector<int> input);

    // print a string vector
    void printVector_string(vector<string> input);

    // read the file "movie_clean.csv" and keep the data
    vector<Movie*> loadMovie(string name);

    // read the file "tag_clean.csv" and keep the data
    vector<tuple<int, string>> loadTag(string name);

    // read the file "rating.csv" and keep the data
        // the name "loadMiniRating were used with "mini" because it was our sample and test file
    void loadMiniRating(string name, HashUsers* hash);
    
    // using the data from "movie_clean.csv" build the TrieTree data structure about the movies
    TrieNodeMovie* loadTrieTreeMovie(vector<Movie*> movies);

    // using the data from "tag_clean.csv" build the TrieTree data structure about the tags
    TrieNodeTag* loadTrieTreeTag(vector<tuple<int, string>> id_name);

    // read the hash table about Users and update the hash table about the movies
    void setRatingByUsers(HashUsers* users, HashMovies* movies);



#endif