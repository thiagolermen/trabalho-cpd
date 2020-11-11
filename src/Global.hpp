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

class Global{
    
    public:
    
        HashMovies* movies;
        HashGenres* genres;
        HashUsers* users;

        TrieNodeMovie* movies_tree;
        TrieNodeTag* tag_tree;

        Global(HashMovies* movies, HashGenres* genres, HashUsers* users, TrieNodeMovie* movies_tree, TrieNodeTag* tag_tree);

        void init();
};

#endif