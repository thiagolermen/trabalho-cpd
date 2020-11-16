#ifndef GLOBAL_H
#define GLOBAL_H

#include "AuxiliaryFunctions.hpp"
#include "HashMovies.hpp"
#include "HashUsers.hpp"
#include "HashGenres.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"
#include "Movie.hpp"
#include "User.hpp"

using namespace std;


// the class global is used to keeps all the other classes implemented and used in this project
class Global{
    
    public:
        // initialize the Hash Table classes
        HashMovies* movies;
        HashGenres* genres;
        HashUsers* users;

        // initialize the Trie Tree classes
        TrieNodeMovie* movies_tree;
        TrieNodeTag* tag_tree;

        // define the class constructor 
        Global(HashMovies* movies, HashGenres* genres, HashUsers* users, TrieNodeMovie* movies_tree, TrieNodeTag* tag_tree);

        // call all other functions to load the data
        void init();
};

#endif