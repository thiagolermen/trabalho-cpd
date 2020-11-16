#include "AuxiliaryFunctions.hpp"

#define TABLE_SZ 138493

using namespace std;

void printVector_string(vector<string> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << endl;
    }
}

void printVector_int(vector<int> input){
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << endl;
    }
}

vector<string> split_string(string s){
    string delimiter = "|";
    vector<string> output;

    size_t pos = 0;
    string token;

    // keep the current substr "the string until found the delimiter string" in the output vector
    // erase this substr from the original string to keep doing the same thing again
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        output.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    output.push_back(s);
    return output;
}

vector<Movie*> loadMovie(string name){
    ifstream file;
    string first_line;
    string movie_id;
    string title;
    string genre;
    string aux;

    vector<string> genres;
    vector<Movie*> movies;

    // by default open mode = ios::in mode 
    file.open(name);

    // the getline func with 2 parameters gets the "file_name" in 'file', read the current line and keeps it in a string 'first_line'
    // after this, move the pointer to the next line in the file
    getline(file, first_line);

    // the getline func with 3 parameters do the allmost the same but, instead of read until the end-line, read until find the third parameter
    while (getline(file, movie_id, ',')) {

        getline(file, title, '\"') ;
        getline(file, title, '\"') ;

        getline(file, genre,'\"') ;
        getline(file, genre,'\"') ;
        getline(file, aux) ;

        genres = split_string(genre);

        Movie* aux =  new Movie(title, stoi(movie_id), genres);
        movies.push_back(aux);
    }

    file.close();

    return movies;
}

vector<tuple<int, string>> loadTag(string name){
    ifstream file;
    string first_line;
    string user_id;
    string movie_id;
    string tag;
    string timestamp;

    vector<tuple<int, string>> output;

    // by default open mode = ios::in mode 
    file.open(name);

    // the getline func with 2 parameters gets the "file_name" in 'file', read the current line and keeps it in a string 'first_line'
    // after this, move the pointer to the next line in the file
    getline(file, first_line);

    // the getline func with 3 parameters do the allmost the same but, instead of read until the end-line, read until find the third parameter
    while (getline(file, user_id, ',')) {

        getline(file, movie_id, ',');

        getline(file, tag, ',');

        getline(file, timestamp);

        output.push_back(make_tuple(stoi(movie_id), tag));
    }

    file.close();

    return output;
}

void loadMiniRating(string name, HashUsers* hash){

    ifstream file;
    string first_line;
    string user_id;
    string movie_id;
    string rating;
    string timestamp;

    // by default open mode = ios::in mode 
    file.open(name);

    // the getline func with 2 parameters gets the "file_name" in 'file', read the current line and keeps it in a string 'first_line'
    // after this, move the pointer to the next line in the file
    getline(file, first_line);

    // the getline func with 3 parameters do the allmost the same but, instead of read until the end-line, read until find the third parameter
    while (getline(file, user_id, ',')) {

        getline(file, movie_id, ',') ;

        getline(file, rating, ',') ;

        getline(file, timestamp) ;

        User* aux = hash->search(stoi(user_id));
        if (aux == nullptr){
            aux = new User(stoi(user_id));
            hash->insertKey(aux);
        }
        aux->setAnalysedMovies(make_tuple(stoi(movie_id), stof(rating)));
    }

    file.close();
}

TrieNodeMovie* loadTrieTreeMovie(vector<Movie*> movies){

    // create a new pointer to the Trie Tree structure about movies
    TrieNodeMovie* output = new TrieNodeMovie();

    // reading the vector wich contains the movies data, buil the Trie Tree
    for (vector<Movie*>::iterator it = movies.begin(); it != movies.end();it++)
        output->insert((*it)->getMovieId(), (*it)->getTitle());

    // return the pointer to the Trie Tree
    return output;
}

TrieNodeTag* loadTrieTreeTag(vector<tuple<int, string>> id_name){

    // create a new pointer to the Trie Tree structure about tags
    TrieNodeTag* output = new TrieNodeTag();

    // reading the vector wich contains the movies data, buil the Trie Tree
    for (vector<tuple<int, string>>::iterator it = id_name.begin(); it != id_name.end();it++)
        output->insert(get<0>(*it), get<1>(*it));

    // return the pointer to the Trie Tree
    return output;
}

void setRatingByUsers(HashUsers* users, HashMovies* movies){
    // for each user we found in the Users hash table data structure, do...
    for (int i = 0; i < users->getTableSize(); i++){
        
        //for each User, get the analysed movies 
        for (list<User*>::iterator it = users->table[i].begin(); it != users->table[i].end() ; it++){
            vector<tuple<int, float>> analised_movies = (*it)->getAnalysedMovies();
            for (int j = 0; j < analised_movies.size(); j++){

                // keeps the movie_id 'flag'
                int movie_id = get<0>(analised_movies[j]);
                // search this flag in the movies and keeps in an auxiliary Movie type
                Movie* aux = movies->search(movie_id);
                // using the pointer pointing to the current movie, update the rating
                aux->rating_avg += get<1>(analised_movies[j]);
                (aux->count)++;
            }
        }
    }
}

