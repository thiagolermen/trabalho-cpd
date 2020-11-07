#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "Movie.hpp"

using namespace std;

class User{
    private:
        int user_id;
        vector<tuple<int,float>> analysed_movies;

    public:
        // Constructor
        User(int user_id);

        // Getters and Setters
        int getUserId();
        void setUserId(int movie_id);
        vector<tuple<int,float>>  getAnalysedMovies();
        void setAnalysedMovies(tuple<int,float>  analysed_movies);

};

#endif