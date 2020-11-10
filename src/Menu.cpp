#include "Menu.hpp"

vector<string> getCommand(){
    vector<string> command;
    string input;

    getline(cin, input);

    command.push_back(input.substr(0, input.find_first_of(" ")));

    input.erase(0, input.find_first_of(" ")+1);

    command.push_back(input);

    return command;
}

void menu(){
    system("clear");
    
    vector<string> command;
    command = getCommand();

    cout << "command: ";
    for(int i = 0; i < command.size(); i++)
        cout << command[i] << endl;
}
