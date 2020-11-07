#include "User.hpp"

using namespace std;

User::User(int user_id){
    this->user_id = user_id;
}

int User::getUserId(){
    return this->user_id;
}

void User::setUserId(int movie_id){
    this->user_id = user_id;
}

vector<tuple<int,float>> User::getAnalysedMovies(){
    return this->analysed_movies;
}

void User::setAnalysedMovies(tuple<int,float> analysed_movies){
    this->analysed_movies.push_back(analysed_movies);
}