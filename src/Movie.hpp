#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie{
    private:
        string title; // title of the movie
        int movie_id;
        vector<string> genres;
        
    public:
        float rating_avg; // the sum of all averages given for the movie
        int count; // how many users rated the movie

        // Constructor
        Movie(string title, int movie_id, vector<string> genres);
        Movie();

        // Getters and Setters
        string getTitle();
        void setTitle(string title);
        int getMovieId();
        void setMovieId(int movie_id);
        vector<string> getGenres();
        void setGenres(vector<string> genres);

};

#endif
