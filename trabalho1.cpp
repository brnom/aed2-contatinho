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
void PesquisaContato(Dicio &cont, string _nam){
    Dicio::iterator itr;
    
    // procura e se achar, printa telefone
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0){
            cout <<"Contatinho encontrado: telefone "<< itr->second <<endl;
            return;
        }
    }

    // se nao achou, printa aq
    cout<<"Contatinho nao encontrado"<<endl;
}

/* Requesitos:
 * - nao inserir pessoas com nomes iguais
 * - se for igual, imprimir "Contatinho ja inserido"
*/
void InsereContato(Dicio &cont, string _nam, int _tel){

    Dicio::iterator itr;
    
    // procura e se achar, printa telefone
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0){
            cout << "Contatinho ja inserido" << endl;
            return;
        }
    }

    //se nao achou, insere
    cont.insert(pair<string,int>(_nam, _tel));

    
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
void RemoveContato(Dicio &cont, string _nam){
    
    Dicio::iterator itr;
    
    // procura e se achar, apaga
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0){
            cont.erase(_nam);
            return;
        }
    }
    
    cout << "Operacao invalida: contatinho nao encontrado" <<endl;
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
void AlteraContato(Dicio &cont, string _nam, int _tel){

    Dicio::iterator itr;

    // procura e se achar, altera telefone
    for (itr = cont.begin(); itr != cont.end(); ++itr){
        if((itr->first).compare(_nam)==0){
            itr->second=_tel;
            return;
        }
    }

    cout << "Operacao invalida: contatinho nao encontrado" <<endl;
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
    
    Dicio contatinhos;

    while (1){
        //cout << "entrada:: ";
        int number=0;
        string all;
        getline(cin, all);
    

        //Tratamento de dados
        vector<string> args;
        args=corta(all, ' ');
        if(args.size()==3)
            number=stoi(args[2]);

        //Insere 
        if(args[0].compare("I")==0)
            InsereContato(contatinhos, args[1], number);                

        //Pesquisa
        else if(args[0].compare("P")==0)
            PesquisaContato(contatinhos, args[1]);                

        //Remove
        else if(args[0].compare("R")==0)
            RemoveContato(contatinhos, args[1]);

        //Altera
        else if(args[0].compare("A")==0)
            AlteraContato(contatinhos, args[1], number);

        //Para
        else if(args[0].compare("0")==0)
            return 0;
    }
    return 0;
}
