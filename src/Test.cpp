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
    TrieNodeMovie* trie = new TrieNodeMovie();

    Movie m1("thithigrao", 1, {"Comédia"});
    Movie m2("lolzinho", 2, {"Comédia"});
    Movie m3("alex andre", 3, {"Comédia"});
    Movie m4("usguri", 4, {"Comédia"});
    Movie m5("Carai tio", 5, {"Comédia"});
    Movie m6("lolzeira", 6, {"Comédia"});

    trie->insert(m1.getMovieId(), m1.getTitle());
    trie->insert(m2.getMovieId(), m2.getTitle());
    trie->insert(m3.getMovieId(), m3.getTitle());
    trie->insert(m4.getMovieId(), m4.getTitle());
    trie->insert(m5.getMovieId(), m5.getTitle());
    trie->insert(m6.getMovieId(), m6.getTitle());

    cout << "===========================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE MOVIE" << endl;
    cout << "===========================================" << endl;
    if(trie->search("thithigrao"))
        cout << "thithigrao: "<< "found" << endl;
    else
        cout  << "thithigrao: " << "not found" << endl;
    
    if(trie->search("lolzinho69"))
        cout  << "lolzinho69: " << "found" << endl;
    else
        cout  << "lolzinho69: " << "not found" << endl;

    if(trie->search("usguri"))
        cout  << "usguri: " << "found" << endl;
    else
        cout  << "usguri: " << "not found" << endl;

    if(trie->search("alex andre"))
        cout  << "alex andre: " << "found" << endl;
    else
        cout  << "alex andre: " << "not found" << endl;

    if(trie->search("lolzinho"))
        cout  << "lolzinho: " << "found" << endl;
    else
        cout  << "lolzinho: " << "not found" << endl;
    
    if(trie->search("mãno do céu: 2"))
        cout  << "mãno do céu: 2: " << "found" << endl;
    else
        cout  << "mãno do céu: 2: " << "not found" << endl;

    cout << "-----";
    cout << endl << "Test 'search prefix' " << endl;
    vector<string> output = trie->search_prefix("lol");
    cout << endl;
    cout << "Movie ID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << ";"<< endl;

    output = trie->search_prefix("Cara");
    cout << endl;
    cout << "MovieID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << ";"<< endl;

    cout << "-----";
    cout << endl << "Test 'search prefix' id" << endl;
    vector<int> output_id = trie->search_prefix_id("Cara");
    cout << "Movie ID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output_id.size(); i++)
        cout << output_id[i] << ";"<< endl;

    output_id = trie->search_prefix_id("lol");
    for(int i = 0 ; i < output_id.size(); i++)
        cout << output_id[i] << ";"<< endl;

}

void testTrieTreeTag(){

    TrieNodeTag* trie = new TrieNodeTag();

    trie->insert(1, "thithigrao");
    trie->insert(2, "lolzinho");
    trie->insert(3, "alex andre");
    trie->insert(4, "thithigrao");
    trie->insert(5, "Carai tio");
    trie->insert(5, "usguri");

    cout << "=========================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE TAG" << endl;
    cout << "=========================================" << endl;
    vector<int> aux = trie->search("thithigrao");
    if(!aux.empty()){
        cout << "thithigrao: ";
        for (int i = 0 ; i < aux.size() ; i++){
            cout << aux[i] << " ";
        }
        cout << endl;
    }  
    else
        cout  << "thithigrao: " << "not found" << endl;

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

    cout << "========================================================" << endl;
    cout << "     TESTE DA ESTRUTURA DE DADOS HASH TABLE MOVIES      " << endl;
    cout << "========================================================" << endl;


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
    for(int i=0;i<20;i++){
        cout << movies[i]->getMovieId() << " , " << movies[i]->getTitle() << " , ";
        vector<string> genres = movies[i]->getGenres();
        for (int i=0;i<genres.size();i++)
            cout << genres[i] << "|";
        cout << endl;
    }
    cout << "..." << endl << endl;
}

void testLoadTags(){

    cout << "========================================================" << endl;
    cout << "                TESTE DA FUNÇÃO LOAD TAGS               " << endl;
    cout << "========================================================" << endl;

    vector<tuple<int, string>> movie_tag = loadTag("../data/tag_clean.csv");

    cout << "MovieID , Tag" << endl;
    for(int i=0;i<20;i++){
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
    testLoadMovies();

    // Load Tags test
    testLoadTags();

    // Load Mini Rating Test
    testloadMiniRating();

    return 0;
}
