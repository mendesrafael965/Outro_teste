#ifndef DICIONARIO_H
#define DICIONARIO_H
#include <map>
#include <string>
#include <iterator>
#include <vector>


using namespace std;

class Dicionario
{
    public:
        Dicionario();
        Dicionario(string chave, string valor);
        virtual ~Dicionario();
        void inserir(string chave, string valor);
        vector<string> busca(string chave);


    private:
        multimap<string, string> elem_;  //
        vector<string> valores_;        //Vetor dinâmico que recebe valores associados a chave passada como parâmetro
};

#endif // DICIONARIO_H
