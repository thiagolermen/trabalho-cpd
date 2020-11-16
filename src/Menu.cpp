#include "Menu.hpp"

void searchPrefix(Global* global, string prefix){
    cout << endl;
    cout << "===================================================" << endl;
    cout << "                  SEARCH PREFIX                    " << endl;
    cout << "===================================================" << endl;

    vector<int> s = global->movies_tree->search_prefix_id(prefix);
    cout << "Search for: <" << prefix << ">" << endl;
    cout << "MovieID , Title , Genres , Rating_avg , count" << endl << endl;
    for (int i = 0 ; i < s.size() ; i++){
        Movie* m = global->movies->search(s[i]);
        vector<string> g = m->getGenres();
        cout << m->getMovieId() << " , " << m->getTitle() << " , " << "|";
        for (int j = 0 ; j < g.size() ; j++)
            cout << g[j] << "|";
        cout << " , " << (m->rating_avg)/(m->count) << " , " << m->count << endl;
    }
}

void searchUser(Global* global, int user_id){
    cout << endl;
    cout << "===================================================" << endl;
    cout << "                    SEARCH USER                    " << endl;
    cout << "===================================================" << endl;
    cout << "Search for user: " << user_id << endl;
    cout << "User_rating , Title , Global_rating , count" << endl << endl;

    if(user_id < 0){
        cout << "the userID must be greater than 0." << endl;
        return;
    }

    User* u = global->users->search(user_id);

    if(u == nullptr){
        cout << "user not found." << endl;
        return;
    }    
    vector<tuple<int,float>> am = u->getAnalysedMovies();
    for (int i = 0 ; i < am.size() ; i++){
        Movie* m = global->movies->search(get<0>(am[i]));
        cout << get<1>(am[i]) << " , " << m->getTitle() << " , " <<(m->rating_avg)/(m->count) << " , " << m->count << endl;
    }
}

void searchTopGenres(Global* global, int top_x, string genre){
    cout << endl;
    cout << "===================================================" << endl;
    cout << "               SEARCH TOP N GENRE                  " << endl;
    cout << "===================================================" << endl;
    cout << "Search for: top " << top_x << "  <" << genre << ">" << endl;
    cout << "Title , Genres , Rating , Count" << endl << endl;

    Genres* g = global->genres->search(genre);

    if(top_x < 0){
        cout << "top N must be greater than 0" << endl;
        return;
    }

    if(g == nullptr){
        cout << endl << "genre not found" << endl;
        return;
    }
    
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

void searchTags(Global* global, vector<string> tags){
    cout << endl;
    cout << "===================================================" << endl;
    cout << "                   SEARCH TAGS                     " << endl;
    cout << "===================================================" << endl;
    cout << "Search for: ";
    for(int i = 0 ; i < tags.size() ; i++)
        cout << " <" << tags[i] << "> ";
    cout << endl << endl;

    vector<vector<int>> ids;
    for (int i = 0 ; i < tags.size() ; i++)
        ids.push_back(global->tag_tree->search(tags[i]));

    vector<int> common_movies;
    vector<int> aux = ids[0];

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

void stringSplit(string str, string delim, vector<string>& results){
    int cutAt;

    while((cutAt = str.find_first_of(delim)) != str.npos){
        if(cutAt > 0)
            results.push_back(str.substr(0,cutAt));
        str = str.substr(cutAt+1);
    }
    if(str.length() > 0)
        results.push_back(str);
}

vector<string> getCommand(){
    vector<string> command;
    string input;

    bool loop = true;

    while(loop){
        getline(cin, input);
        if(input != "")
            loop = false;
    }

    stringSplit(input, " ", command);

    return command;
}

void menu(){
    system("clear");
    
    cout << endl;
    cout << "========================================================" << endl;
    cout << "               READING DATA FILES AND                   " << endl;
    cout << "              BUILDING DATA STRUCTURES                  " << endl;
    cout << "========================================================" << endl;

    HashMovies* movies = new HashMovies(TABLE_MOVIE_SZ);
    HashGenres* genres = new HashGenres(TABLE_GENRES_SZ);
    HashUsers* users = new HashUsers(TABLE_USER_SZ);

    TrieNodeMovie* movies_tree = new TrieNodeMovie();
    TrieNodeTag* tag_tree = new TrieNodeTag(); 

    // Construct
    Global* global = new Global(movies, genres, users, movies_tree, tag_tree);

    // Init all the structures
    unsigned t = clock();
    global->init();
    cout << "done..." << endl;
    cout << "total time: " << (clock() - t) / CLOCKS_PER_SEC << " seconds"<< endl;
    cout << "type enter to enter console mode..." << endl;
    cin.get();
    system("clear");

    bool loop = true;
    vector<string> command;

    while(loop){
        command = getCommand();
        system("clear");
        cout << endl << "command: " << command[0] << endl;
        cout << "parameters:";
        for(int i = 1; i < command.size(); i++)
            cout << " " << command[i];
        cout << endl << endl;

        if(command[0] == "movie"){
            string name;
            int N = command.size();
            for(int i = 1; i < N; i++){
                if(i == N - 1)
                    name = name + command[i];
                else
                    name = name + command[i] + " ";
            }
            searchPrefix(global, name);
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }
        else if(command[0] == "user"){
            searchUser(global, stoi(command[1]));
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }
        else if(command[0] == "top"){
            int N = stoi(command[1]);
            searchTopGenres(global, N, command[2]);
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }
        else if(command[0] == "tag"){
            vector<string> tags;
            for(int i = 1; i < command.size(); i++)
                tags.push_back(command[i]);
            searchTags(global, tags);
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }
        else if(command[0] == "help"){
            cout << "the symbols < > must not be typed in the call..." << endl << endl;
            cout << "to search a movie type:           movie <prefix>" << endl;
            cout << "to search a user type:            user <user_ID>" << endl;
            cout << "to search a top type:             top <N> <genre>" << endl;
            cout << "to search movies by tag type:     tags <\"tag1\"> <\"tag2\">" << endl;
            cout << "to exit console mode type:        exit" << endl;
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }else if(command[0] == "exit"){
            loop = false;
        }else{
            cout << "invalid command - type help ..." << endl;
            cout << endl << "type enter to continue...";
            cin.get();
            system("clear");
        }
    }
}
