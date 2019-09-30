#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

typedef unordered_map<string,int> Dicio;

/* Requesitos:
 * - se existir contato, imprimir "Contatinho encontrado: telefone _tel"
 * - caso nao exista, imprimir "Contatinho nao encontrado"
*/
int PesquisaContato(Dicio &cont, string _nam){
    Dicio::iterator itr;

    // se lista estiver vazia, retorna -1
    if(cont.begin() == cont.end()){
        return -1;
    }

    // procura e se achar, retorna telefone
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0)
            return itr->second;
    }

    // se nao achou, retorna 0
    return 0;
}

/* Requesitos:
 * - nao inserir pessoas com nomes iguais
 * - se for igual, imprimir "Contatinho ja inserido"
*/
int InsereContato(Dicio &cont, string _nam, string _tel){

    int _t=stoi(_tel);

    int comp=PesquisaContato(cont, _nam);

    if(comp==0 || comp==-1){
        //se nao achou, insere e retorna 1
        cont.insert(pair<string,int>(_nam, _t));
        return 1;
    }

    //se deu ruim retorna 0
    return 0;
    
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
int RemoveContato(Dicio &cont, string _nam){
    
    int comp=PesquisaContato(cont, _nam);
    if(comp==0 || comp==-1){
        //se nao achou, retorna 0
        return 0;
    }
    cont.erase(_nam);
    return 1;
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
int AlteraContato(Dicio &cont, string _nam, string _tel){

    Dicio::iterator itr;

    int _t=stoi(_tel);

    // procura e se achar, altera telefone
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0){
            itr->second=_t;
            return 1;
        }
    }

    return 0;
}

vector<string> corta(const string& s, char delimita){
    vector<string> tokens;
    string tok;
    istringstream algo(s);
    while(getline(algo, tok, delimita)){
        tokens.push_back(tok);
    }
    return tokens;
}


int main(int argc, char *argv[]){

    
    string all;
    Dicio contatinhos;
    int flag;

    while (1){
        //cout << "entrada:: ";
        getline(cin, all);
        flag=0;
        vector<string> args;

        //Tratamento de dados
        args=corta(all, ' ');

        //Insere 
        if(args[0].compare("I")==0){
            flag = InsereContato(contatinhos, args[1], args[2]);

            if (flag == 0)
                cout << "Contatinho ja inserido" << endl;
        }

        //Pesquisa
        else if(args[0].compare("P")==0){
            flag = PesquisaContato(contatinhos, args[1]);
            
            if (flag == -1 || flag ==0)
                cout<<"Contatinho nao encontrado"<<endl;
            else
                cout <<"Contatinho encontrado: telefone "<< flag<<endl;
        }

        //Remove
        else if(args[0].compare("R")==0){
            flag = RemoveContato(contatinhos, args[1]);

            if (flag == 0)
                cout << "Operacao invalida: contatinho nao encontrado" << endl;
        }

        //Altera
        else if(args[0].compare("A")==0){
            flag = AlteraContato(contatinhos, args[1], args[2]);

            if (flag == 0)
                cout << "Operacao invalida: contatinho nao encontrado" << endl;
        }

        else if(args[0].compare("0")==0)
            break;
    }
    return 0;
}
