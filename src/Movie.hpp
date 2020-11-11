#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie{
    private:
        string title;
        int movie_id;
        vector<string> genres;
        
    public:
        float rating_avg;
        int count;

        // Constructor
        Movie(string title, int movie_id, vector<string> genres);

        // Getters and Setters
        string getTitle();
        void setTitle(string title);
        int getMovieId();
        void setMovieId(int movie_id);
        vector<string> getGenres();
        void setGenres(vector<string> genres);
};

#endif
