#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "Dicionario.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype            >


using namespace std;

string minusculo(string palavra){
    for(unsigned int i = 0; i < palavra.length(); i++){
        palavra[i] = tolower(palavra[i]);    //toupper()–> Retorna a minúscula de uma letra
    }
    return palavra;
}

string retira_caracter(string palavra){
    string s = palavra;
    unsigned int i, j = 0;
    for(i = 0; i < palavra.length(); i++){
        if(isalnum(palavra[i])){   //isalnum() -> Retorna verdadeiro se o argumento é uma letra do alfabeto ou um dígito; falso em caso contrário.
            s[j] = palavra[i];
            j += 1;
        }
    }
    i = (i - j);
    s.erase(j,i);   //Apaga sub-string de j até k;
    return s;
}

bool busca_no_txt(string palavra, string n_arq){
    string s1;
    char *a = &(n_arq[0]);    //Converte string para stringC
    ifstream streamDeEntrada(a);

    //Testa se o arquivo foi aberto com sucesso
    if(streamDeEntrada.fail()){
        cout << "Problema na abertura do arquivo" << endl;
        exit(1);
    }

    //O loop é enserrado caso chege o fim o arquivo ou a palavra procurada seja encontrada
    do{
        //Lê strings do arquivo uma a uma
        streamDeEntrada >> s1;
        s1 = minusculo(s1);
        s1 = retira_caracter(s1);

        //Verifica se a string lida é igual a string procurada
        if(s1 == palavra){
            return true;
        }
    }while(streamDeEntrada.eof() == false && s1 != palavra);
    streamDeEntrada.close();

    return false;
}

int main()
{
    string objetivo;
    do{
        cout << "Digite o que deseja buscar:" << endl << "Digite sair, para sair" << endl;
        Dicionario linha;
        cin >> objetivo;
        objetivo = minusculo(objetivo);
        objetivo = retira_caracter(objetivo);
        string n_arq;
        for(int i = 1; i < 4; i++){
                //Define qual arquivo será aberto
            switch(i){
                case 1:
                    n_arq = "d1.txt";
                break;
                case 2:
                    n_arq = "d2.txt";
                break;
                case 3:
                    n_arq = "d3.txt";
                break;
            }

            if(busca_no_txt(objetivo,n_arq) == 1){
                linha.inserir(objetivo,n_arq); //Insere palavra encontrada no dicionário
            }
        }
        //Busca
        vector<string> item;
        item = linha.busca(objetivo);
        for(unsigned int i = 0; i < item.size(); i++){
            cout << item[i] << endl;
        }
        cout << endl;
    }while(objetivo != "sair");
    return 0;
}
