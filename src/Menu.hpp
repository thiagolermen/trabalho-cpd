#ifndef MENU_H
#define MENU_H

#include "AuxiliaryFunctions.hpp"
#include "HashMovies.hpp"
#include "HashUsers.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"
#include "Movie.hpp"
#include "User.hpp"

// menu
    void menu();

// menu functions

    // returns a 2 position vector with the command and the parameters
    vector<string> getCommand();

#endif