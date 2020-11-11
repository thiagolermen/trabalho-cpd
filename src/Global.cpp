#include "Global.hpp"

Global::Global(HashMovies* movies, HashGenres* genres, HashUsers* users, TrieNodeMovie* movies_tree, TrieNodeTag* tag_tree){
    this->movies = movies;
    this->genres = genres;
    this->users = users;
    this->movies_tree = movies_tree;
    this->tag_tree = tag_tree;
}

void Global::init(){

// Init movies structure          

    // Load movies in a auxiliary structure
    vector<Movie*> vector_movies = loadMovie("../data/movie_clean.csv");

    // Init hash movies structure
    for(vector<Movie*>::iterator it = vector_movies.begin() ; it != vector_movies.end() ; it++)
        movies->insertKey((*it));

    // Init trie tree movies structure
    movies_tree = loadTrieTreeMovie(vector_movies);


// Init genres structure

    // Init hash genres structure
    for(vector<Movie*>::iterator it = vector_movies.begin(); it != vector_movies.end(); it++){
        movies->insertKey((*it));
        vector<string> genres_v = (*it)->getGenres();
        for (int i = 0 ; i < genres_v.size() ; i++)
            genres->insertKey(genres_v[i], (*it)->getMovieId());
    }


//Init users structure          

    // Init users hash
    loadMiniRating("../data/rating.csv", users);

    // Update hash movies (rating and count)
    // Call the func to update avg and count of each movie
    setRatingByUsers(users, movies);


// Init tag structure          
    vector<tuple<int, string>> movie_tag = loadTag("../data/tag_clean.csv");
    tag_tree = loadTrieTreeTag(movie_tag);
}