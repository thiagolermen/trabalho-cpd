#include "Movie.hpp"

using namespace std;

Movie::Movie(string title, int movie_id, vector<string> genres){
    this->title = title;
    this->movie_id = movie_id;
    this->genres = genres;
    this->rating_avg = 0;
    this->count = 0;
}

string Movie::getTitle(){
    return this->title;
}

void Movie::setTitle(string title){
    this->title = title;
}

int Movie::getMovieId(){

    return this->movie_id;
}

void Movie::setMovieId(int movie_id){
    this->movie_id = movie_id;
}

vector<string> Movie::getGenres(){
   return this->genres;
}

void Movie::setGenres(vector<string> genres){
    this->genres = genres;
}