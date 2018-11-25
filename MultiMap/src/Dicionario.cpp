#include "Dicionario.h"
#include <map>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

Dicionario::Dicionario(string chave, string valor){
    elem_.insert(pair <string, string> (chave, valor));
}

Dicionario::Dicionario(){
    elem_.insert(pair <string, string> ("", ""));
}

Dicionario::~Dicionario(){
    //delete elem_;
    //delete valores_;
}

void Dicionario::inserir(string chave, string valor){
    elem_.insert(pair <string, string> (chave, valor));
}

vector<string> Dicionario::busca(string chave){

    multimap<string, string>::iterator itr;    //Ponteiro para multimap<string, string>

    for (itr = elem_.begin(); itr != elem_.end(); ++itr)
    {
        if(itr->first == chave){
            valores_.push_back(itr->second);    //-> sintax usada para acessar elementos da classe via ponteiro
        }
    }
    return valores_;
}

