#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <ctime>

#include "AuxiliaryFunctions.hpp"
#include "HashMovies.hpp"
#include "HashUsers.hpp"
#include "HashGenres.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"
#include "Movie.hpp"
#include "User.hpp"
#include "Global.hpp"

#define TABLE_USER_SZ 138493
#define TABLE_MOVIE_SZ 27280
#define TABLE_GENRES_SZ 101

using namespace std;


// search functions
    void searchPrefix(Global* global, string prefix);
    void searchUser(Global* global, int user_id);
    void searchTopGenres(Global* global, int top_x, string genre);
    void searchTags(Global* global, vector<string> tags);

// menu functions
    void stringSplit(string str, string delim, vector<string>& results);

    // return in the first pos the command, others pos have the parameters
    vector<string> getCommand();

// menu
    void menu();

#endif