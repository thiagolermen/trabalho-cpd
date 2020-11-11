#include <iostream>
#include <fstream>
#include <tuple>

#include "AuxiliaryFunctions.hpp"
#include "HashMovies.hpp"
#include "HashUsers.hpp"
#include "HashGenres.hpp"
#include "TrieTreeMovie.hpp"
#include "TrieTreeTag.hpp"
#include "Movie.hpp"
#include "User.hpp"
#include "Menu.hpp"
#include "Global.hpp"

#define TABLE_USER_SZ 138493
#define TABLE_MOVIE_SZ 27280
#define TABLE_GENRES_SZ 101

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

void testHashGenres(){
    cout << endl;
    cout << "========================================================" << endl;
    cout << "         TESTE DA ESTRUTURA DE DADOS HASH USERS         " << endl;
    cout << "       CONTROI E PREENCHE HASHMOVIES E HASHUSERS        " << endl;
    cout << "========================================================" << endl;

    vector<Movie*> vector_movies = loadMovie("../data/movie_clean.csv");

    HashMovies* movies = new HashMovies(TABLE_MOVIE_SZ);
    HashGenres* genres = new HashGenres(TABLE_GENRES_SZ);

    // Init genres hash
    for(vector<Movie*>::iterator it = vector_movies.begin() ; it != vector_movies.end() ; it++){
        movies->insertKey((*it));
        vector<string> genres_v = (*it)->getGenres();
        for (int i = 0 ; i < genres_v.size() ; i++){
            genres->insertKey(genres_v[i], (*it)->getMovieId());
        }  
    }
    genres->printHashTable();   
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
    cout << endl;
    cout << "========================================================" << endl;
    cout << "           TESTE DA FUNÇÃO LOAD MINI RATING             " << endl;
    cout << "========================================================" << endl;

    HashUsers h(138493);
    loadMiniRating("../data/minirating.csv", &h);

    h.printHashTable();
}

void testSetRatingByUsers(){
    cout << endl;
    cout << "========================================================" << endl;
    cout << "           TESTE DA FUNÇÃO SET RATING BY USERS          " << endl;
    cout << "========================================================" << endl;

    vector<Movie*> vector_movies = loadMovie("../data/movie_clean.csv");

    HashMovies* movies = new HashMovies(TABLE_MOVIE_SZ);
    HashUsers* users = new HashUsers(TABLE_USER_SZ);

    // Init movies hash
    for(vector<Movie*>::iterator it = vector_movies.begin() ; it != vector_movies.end() ; it++)
        movies->insertKey((*it));
    
    // Init users hash
    loadMiniRating("../data/minirating.csv", users);

    // Call the func to update avg and count of each movie
    setRatingByUsers(users, movies);

    cout << "PASSEI" << endl;
    cout << "MovieID ; Title ; Rating ; Count" << endl;
    for (int i=0 ; i < 100 ;i++){
        // All the movies of i
        for (list<Movie*>::iterator it = movies->table[i].begin();it != movies->table[i].end() ; it++){
            cout << (*it)->getMovieId() << " , " << 
            (*it)->getTitle() << " , "<< (*it)->rating_avg << " , " << (*it)->count << endl;
        }
    }
    cout << "..." << endl << endl;

    Movie* printed = movies->search(260);
    cout << printed->getMovieId() << " , " << 
            printed->getTitle() << " , "<< printed->rating_avg << " , " << printed->count << endl;



}

void testSearchPrefix(Global* global, string prefix){
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "                TEST SEARCH PREFIX                 " << endl;
    vector<int> s = global->movies_tree->search_prefix_id(prefix);
    cout << "Busca por " << "'" << prefix << "'" << endl;
    cout << "MovieID , Title , Genres , Rating_avg , count" << endl;
    for (int i = 0 ; i < s.size() ; i++){
        Movie* m = global->movies->search(s[i]);
        vector<string> g = m->getGenres();
        cout << m->getMovieId() << " , " << m->getTitle() << " , " << "|";
        for (int j = 0 ; j < g.size() ; j++){
            cout << g[j] << "|";
        }
        cout << " , " << (m->rating_avg)/(m->count) << " , " << m->count << endl;
    }
}

void testSearchUser(Global* global, int user_id){
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "                TEST SEARCH USER                 " << endl;
    cout << "Busca por " << user_id << endl;
    cout << "User_rating , Title , Global_rating , count" << endl;

    User* u = global->users->search(user_id);
    vector<tuple<int,float>> am = u->getAnalysedMovies();
    for (int i = 0 ; i < am.size() ; i++){
        Movie* m = global->movies->search(get<0>(am[i]));
        cout << get<1>(am[i]) << " , " << m->getTitle() << " , " <<(m->rating_avg)/(m->count) << " , " << m->count << endl;
    }
}

void testSearchTopGenres(Global* global, int top_x, string genre){
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "             TEST SEARCH TOP GENRES              " << endl;
    cout << "Busca por " << genre << " top "<< top_x << endl;
    cout << "Title , Genres , Rating , Count" << endl;

    Genres* g = global->genres->search(genre);
    
    vector<int> m = g->movies;
    vector<Movie*> selected_movies;
    for (int i = 0 ; i < m.size() ; i++){
        Movie* aux = global->movies->search(m[i]);
        if (aux->count >= 1000)
            selected_movies.push_back(global->movies->search(m[i]));  
    }

    vector<Movie*> top_rating;
    for (int i = 0 ; i < top_x ; i++){
        Movie* max = selected_movies[0];
        float max_avg = selected_movies[0]->rating_avg/selected_movies[0]->count;
        int max_index = 0;

        for (int j = 0 ; j < selected_movies.size() ; j++){
            float aux_avg = (selected_movies[j]->rating_avg/selected_movies[j]->count);
            if (aux_avg > max_avg){
                max_avg = aux_avg;
                max = selected_movies[j];
                max_index = j;
            }
        }
        top_rating.push_back(max);
        selected_movies.erase(selected_movies.begin()+max_index);
    }

    for (int i = 0 ; i < top_rating.size() ; i++){
        cout << top_rating[i]->getTitle() << " , " << "|";
        vector<string> g = top_rating[i]->getGenres();
        for (int j = 0 ; j < g.size() ; j++){
            cout << g[j] << "|";
        }
        cout << " , " << (top_rating[i]->rating_avg)/(top_rating[i]->count) << " , " << top_rating[i]->count << endl;
    }



}

void testSearchTags(Global* global, vector<string> tags){
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "                TEST SEARCH TAGS                 " << endl;
    cout << "Busca por ";
    for(int i = 0 ; i < tags.size() ; i++)
        cout << "'" << tags[i] << "'" << " , ";
    cout << endl;

    vector<vector<int>> ids;
    for (int i = 0 ; i < tags.size() ; i++){
        ids.push_back(global->tag_tree->search(tags[i]));
    }

    vector<int> common_movies;
    vector<int> aux = ids[0];

    // aux
    for(int i = 0; i < aux.size(); i++){
        bool isFound = true;
        for(int j = 0; j < ids.size(); j++){
            if(isFound){
                for(int k = 0; k < ids[j].size(); k++){
                    if(aux[i] == ids[j][k])
                        break;
                    else 
                    if(k == ids[j].size() - 1)
                        isFound = false;
                }
            }
        }
        if(isFound)
            common_movies.push_back(aux[i]);
    }

    cout << "Title , Genres , Rating, Count" << endl;
    for (int i = 0 ; i < common_movies.size() ; i++){
        Movie* m = global->movies->search(common_movies[i]);
        cout << m->getTitle() << " , " << "|";
        vector<string> g = m->getGenres();
        for (int j = 0 ; j < g.size() ; j++){
            cout << g[j] << "|";
        }
        cout << " , " << (m->rating_avg)/(m->count) << " , " << m->count << endl;
    }


}

void testGlobal(){

    cout << endl;
    cout << "========================================================" << endl;
    cout << "                TESTE DA CLASSE GLOBAL                  " << endl;
    cout << "========================================================" << endl;


    HashMovies* movies = new HashMovies(TABLE_MOVIE_SZ);
    HashGenres* genres = new HashGenres(TABLE_GENRES_SZ);
    HashUsers* users = new HashUsers(TABLE_USER_SZ);

    TrieNodeMovie* movies_tree = new TrieNodeMovie();
    TrieNodeTag* tag_tree = new TrieNodeTag(); 

    // Construct
    Global* global = new Global(movies, genres, users, movies_tree, tag_tree);

    // Init all the structures
    global->init();
    cout << "DIGITE ALGO" << endl;
    cin.get();

    testSearchPrefix(global, "Star T");
    testSearchUser(global, 48644);
    testSearchTopGenres(global, 10, "Romance");
    testSearchTags(global, {"\"Brazil\"", "\"drugs\""});


    

}

int main()
{
    // Trie Tree Movie Test
    //testTrieTreeMovie();

    // Trie Tree Tag Test
    //testTrieTreeTag();

    // Hash Movies test
    //testHashMovies();

    // Hash Users test
    //testHashUsers();

    // Hash Genres test
    //testHashGenres();

    // Load Movies test
    // testLoadMovies();

    // Load Tags test
    // testLoadTags();

    // Load Mini Rating Test
    //testloadMiniRating();

    // Set Rating By Users Test
    //testSetRatingByUsers();

    // Global class test
    //testGlobal();

    // test Menu
    menu();

    return 0;
}
