#include <iostream>

#include "TrieTree.hpp"
#include "BinarySearchTree.hpp"
#include "SeparateChaining.hpp"
#include "AuxiliaryFunctions.hpp"

using namespace std;

void testTrieTree(){
    TrieNode* trie = new TrieNode();

    trie->insert(1, "thithigrao", {"Comédia"});
    trie->insert(2,"lolzinho69",{"Comédia"});
    trie->insert(3,"lolzinho kaisa kda prestigio eu quero",{"Comédia"});
    trie->insert(4,"lolzeira",{"Comédia"});
    trie->insert(5,"usguri",{"Comédia"});
    trie->insert(6,"alex andre",{"Comédia"});
    trie->insert(7,"Carálho irmão",{"Comédia"});
    trie->insert(7,"mãno do céu: 2",{"Comédia"});

    cout << "=====================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS TRIE TREE" << endl;
    cout << "=====================================" << endl;
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
    cout << "Movie ID" << ";" << "Title" << ";" <<"Genres" << endl;
    for(int i = 0 ; i < output.size(); i++)
        cout << output[i] << ";"<< endl;

}

void testSeparateChaining(){

    SeparateChainingHash movies = SeparateChainingHash(7);

    movies.insertKey("thithigrao");
    movies.insertKey("lolzinho eu quero uma skin do jax cajado divino");
    movies.insertKey("lolzinho");
    movies.insertKey("o brabo");
    movies.insertKey("alex andre");
    movies.insertKey("os guris");

    cout << "========================================================" << endl;
    cout << "TESTE DA ESTRUTURA DE DADOS HASH TABLE SEPARATE CHAINING" << endl;
    cout << "========================================================" << endl;

    cout << "thithigrao: " << movies.search("thithigrao") << endl;
    cout << "lolzinho: " << movies.search("lolzinho") << endl;
    cout << "lol: " << movies.search("lol") << endl;
    cout << "alex andre: " << movies.search("alex andre") << endl;
    cout << "usguri: " << movies.search("usguri") << endl;


}

void testFunctions(){

    vector<string> meuVetor;

    meuVetor.push_back("coe");
    meuVetor.push_back("thithigrao");    
    meuVetor.push_back("alex andre");    
    meuVetor.push_back("lolzinho");
    meuVetor.push_back("quero a skin cajado divino do jax, rito gomes!");

    printVector_string(meuVetor);


    cout << "TESTE FUNCAO TEMPLATE MAX" << endl;
    cout << max(1.32, 1.33) << endl;// pode usar o max<tipo> pra pre definir o tipo dos parametros, ou void pra ser o tipo que recebe
}

int main()
{
    // Trie Tree Test
    //testTrieTree();

    // Separate Chaining Test
    //testSeparateChaining();

    // auxiliary functions test
    testFunctions();

    return 0;
}
