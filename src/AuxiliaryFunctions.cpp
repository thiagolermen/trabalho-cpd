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

    getline(file, first_line);

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

    getline(file, first_line);

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

    getline(file, first_line);

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

    TrieNodeMovie* output = new TrieNodeMovie();

    for (vector<Movie*>::iterator it = movies.begin(); it != movies.end();it++)
        output->insert((*it)->getMovieId(), (*it)->getTitle());

    return output;
}

TrieNodeTag* loadTrieTreeTag(vector<tuple<int, string>> id_name){

    TrieNodeTag* output = new TrieNodeTag();

    for (vector<tuple<int, string>>::iterator it = id_name.begin(); it != id_name.end();it++)
        output->insert(get<0>(*it), get<1>(*it));

    return output;
}

void setRatingByUsers(HashUsers* users, HashMovies* movies){
    for (int i = 0; i < users->getTableSize(); i++){
        //cout << "DALE0" << endl;
        for (list<User*>::iterator it = users->table[i].begin(); it != users->table[i].end() ; it++){
            //cout << "DALE1" << endl;
            vector<tuple<int, float>> analised_movies = (*it)->getAnalysedMovies();
            for (int j = 0; j < analised_movies.size(); j++){
                //cout << "DALE2" << endl;
                int movie_id = get<0>(analised_movies[j]);
                Movie* aux = movies->search(movie_id);
                aux->rating_avg += get<1>(analised_movies[j]);
                (aux->count)++;
                //cout << movie_id << "," << aux->rating_avg << "," << aux->count << endl;
            }
        }
    }
}

