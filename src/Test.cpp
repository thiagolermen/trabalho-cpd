#include <iostream>
#include <fstream>
#include <tuple>

#include "AuxiliaryFunctions.hpp"
#include "HashMovies.hpp"
#include "HashUsers.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"
#include "Movie.hpp"
#include "User.hpp"

using namespace std;


void testTrieTreeMovie(){

    cout << endl;
    cout << "===========================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE MOVIE" << endl;
    cout << "===========================================" << endl;

    TrieNodeMovie* trie = new TrieNodeMovie();

    vector<Movie*> movies = loadMovie("../data/movie_clean.csv");

    trie = loadTrieTreeMovie(movies);

    cout << "Toy Story (1995):" << trie->search("\"Toy Story (1995)\"") << endl;
    cout << "Four Rooms (1995): " << trie->search("\"Four Rooms (1995)\"") << endl;
    cout << "usguri: "<< trie->search("usguri") << endl;
    
    cout << "-----";
    cout << endl << "Test 'search prefix' Star T" << endl;
    vector<string> output = trie->search_prefix("\"Star T");
    cout << endl;
    cout << "Movie ID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << ";"<< endl;

}

void testTrieTreeTag(){
    cout << endl;
    cout << "=========================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE TAG" << endl;
    cout << "=========================================" << endl;

    TrieNodeTag* trie = new TrieNodeTag();

    vector<tuple<int, string>> movie_tag = loadTag("../data/tag_clean.csv");

    trie = loadTrieTreeTag(movie_tag);
    
    vector<int> aux = trie->search("\"dark hero\"");
    if(!aux.empty()){
        cout << "'dark hero' movies found: ";
        for (int i = 0 ; i < aux.size() ; i++){
            cout << aux[i] << " ";
        }
        cout << endl;
    }  
    else
        cout  << "dark hero: " << "not found" << endl;

    aux = trie->search("Carai tio");
    if(!aux.empty()){
        cout << "Carai tio: ";
        for (int i = 0 ; i < aux.size() ; i++){
            cout << aux[i] << " ";
        }
        cout << endl;
    }  
    else
        cout  << "Carai tio: " << "not found" << endl;

    aux = trie->search("usguri");
    if(!aux.empty()){
        cout << "usguri: ";
        for (int i = 0 ; i < aux.size() ; i++){
            cout << aux[i] << " ";
        }
        cout << endl;
    }  
    else
        cout  << "usguri: " << "not found" << endl;

    aux = trie->search("lolzeira");
    if(!aux.empty()){
        cout << "lolzeira: ";
        for (int i = 0 ; i < aux.size() ; i++){
            cout << aux[i] << " ";
        }
        cout << endl;
    }  
    else
        cout  << "lolzeira: " << "not found" << endl;
}

void testHashMovies(){


    cout << endl;
    cout << "========================================================" << endl;
    cout << "     TESTE DA ESTRUTURA DE DADOS HASH TABLE MOVIES      " << endl;
    cout << "========================================================" << endl;

    Movie m1("thithigrao", 1, {"Comédia", "Terror"});
    Movie m2("lolzinho", 2, {"Comédia"});
    Movie m3("alex andre", 3, {"Comédia"});
    Movie m4("usguri", 4, {"Comédia"});
    Movie m5("Carai tio", 5, {"Comédia"});
    Movie m6("lolzeira", 6, {"Comédia"});

    HashMovies movies = HashMovies(7);

    movies.insertKey(&m1);
    movies.insertKey(&m2);
    movies.insertKey(&m3);
    movies.insertKey(&m4);
    movies.insertKey(&m5);
    movies.insertKey(&m6);


    cout << "-----";
    cout << endl << "Test 'search' " << endl;
    Movie* aux = movies.search(1);
    cout << "MovieID" << ";" << "Title" << ";" <<"Genres" << endl;
    cout << aux->getMovieId() << ";" << aux->getTitle() << ";";
    vector<string> genres = aux->getGenres();
    for (int i=0;i<genres.size();i++)
        cout << genres[i] << "|";
    cout << endl;

    aux = movies.search(12);
    if(aux != nullptr){
        cout << aux->getMovieId() << ";" << aux->getTitle() << ";";
        genres = aux->getGenres();
        for (int i=0;i<genres.size();i++)
            cout << genres[i] << "|";
        cout << endl;
    }else{
        cout << "nf" << ";" << "nf" << ";" << "nf";
        cout << endl;
    }

    aux = movies.search(3);
    cout << aux->getMovieId() << ";" << aux->getTitle() << ";";
    genres = aux->getGenres();
    for (int i=0;i<genres.size();i++)
        cout << genres[i] << "|";
    cout << endl;


}

void testHashUsers(){

    User u1(1);
    User u2(2);
    User u3(3);
    User u4(4);
    User u5(5);
    User u6(6);

    HashUsers Users = HashUsers(7);

    Users.insertKey(&u1);
    Users.insertKey(&u2);
    Users.insertKey(&u3);
    Users.insertKey(&u4);
    Users.insertKey(&u5);
    Users.insertKey(&u6);

    tuple<int, float> t = make_tuple(1, 8.5);
    u1.setAnalysedMovies(t);

    cout << "========================================================" << endl;
    cout << "      TESTE DA ESTRUTURA DE DADOS HASH TABLE USERS      " << endl;
    cout << "========================================================" << endl;


    cout << "-----";
    cout << endl << "Test 'search' " << endl;
    User* aux = Users.search(1);
    cout << "UserID" << ";" << "AnalysedMovies" << endl;
    cout << aux->getUserId() << ";";
    vector<tuple<int, float>> am = aux->getAnalysedMovies();
    for (int i=0;i<am.size();i++)
        cout << get<0>(am[i]) << ";" << get<1>(am[i]) << "|";
    cout << endl;

    aux = Users.search(12);
    if(aux != nullptr){
        cout << aux->getUserId() << ";";
        am = aux->getAnalysedMovies();
        for (int i=0;i<am.size();i++)
            cout << get<0>(am[i]) << ";" << get<1>(am[i]) << "|";
        cout << endl;
    }else{
        cout << "nf";
        cout << endl;
    }

    aux = Users.search(3);
    cout << aux->getUserId() << ";";
    am = aux->getAnalysedMovies();
    for (int i=0;i<am.size();i++)
        cout << get<0>(am[i]) << ";" << get<1>(am[i]) << "|";
    cout << endl;


}

void testLoadMovies(){

    cout << "========================================================" << endl;
    cout << "               TESTE DA FUNÇÃO LOAD MOVIES              " << endl;
    cout << "========================================================" << endl;

    vector<Movie*> movies = loadMovie("../data/movie_clean.csv");

    cout << "MovieID , Title , Genres" << endl;
    for(int i=0;i<10;i++){
        cout << movies[i]->getMovieId() << " , " << movies[i]->getTitle() << " , ";
        vector<string> genres = movies[i]->getGenres();
        for (int i=0;i<genres.size();i++)
            cout << genres[i] << "|";
        cout << endl;
    }
    cout << "..." << endl << endl;
}

void testLoadTags(){

    cout << endl;
    cout << "========================================================" << endl;
    cout << "                TESTE DA FUNÇÃO LOAD TAGS               " << endl;
    cout << "========================================================" << endl;

    vector<tuple<int, string>> movie_tag = loadTag("../data/tag_clean.csv");

    cout << "MovieID , Tag" << endl;
    for(int i=0;i<10;i++){
        cout << get<0>(movie_tag[i]) << " , " << get<1>(movie_tag[i]) << endl;
    }
    cout << "..." << endl << endl;
}

void testloadMiniRating(){
    cout << "========================================================" << endl;
    cout << "           TESTE DA FUNÇÃO LOAD MINI RATING             " << endl;
    cout << "========================================================" << endl;

    HashUsers h(138493);
    loadMiniRating("../data/minirating.csv", &h);

    h.printHashTable();
}

int main()
{
    // Trie Tree Movie Test
    testTrieTreeMovie();

    // Trie Tree Tag Test
    testTrieTreeTag();

    // Hash Movies test
    testHashMovies();

    // Hash Users test
    testHashUsers();

    // Load Movies test
    // testLoadMovies();

    // Load Tags test
    // testLoadTags();

    // Load Mini Rating Test
    testloadMiniRating();

    return 0;
}
