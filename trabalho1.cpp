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
}*/

/* Requesitos:
 * - nao inserir pessoas com nomes iguais
 * - se for igual, imprimir "Contatinho ja inserido"

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
}*/

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"

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
}*/

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"

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
}*/

void operaciones(Dicio &cont, char cmd, string _nam, int _tel){
    
        Dicio::iterator itr;
        
        //Insere 
        if(cmd=='I'){
            itr = cont.find(_nam);
            if (itr != cont.end())
                cout << "Contatinho ja inserido" << endl;
            else
                cont.insert(pair<string,int>(_nam, _tel));
            return;
        }

        //Pesquisa
        if(cmd=='P'){
            itr = cont.find(_nam);
            if (itr != cont.end())
                cout <<"Contatinho encontrado: telefone "<< itr->second <<endl;
            else
                cout<<"Contatinho nao encontrado"<<endl;
            return;
        }
            

        //Remove
        if(cmd=='R'){
            // procura e se achar, apaga
            itr = cont.find(_nam);
            if (itr != cont.end())
                cont.erase (itr);
            else
                cout << "Operacao invalida: contatinho nao encontrado" <<endl;
            return;

        }


        //Altera
        if(cmd=='A'){
            // procura e se achar, altera telefone            
            itr = cont.find(_nam);
            if (itr != cont.end())
                itr->second=_tel;
            else
                cout << "Operacao invalida: contatinho nao encontrado" <<endl;
            return;
        }

}

int main(int argc, char *argv[]){
    
    Dicio contatinhos;
    char cmd;
    string nome;
    int tel;


    while (1){

        cin>>cmd;

        if(cmd=='0')
            return 0;

        cin>>nome;
        if(cmd=='I'||cmd=='A')
            cin>>tel;

        operaciones(contatinhos, cmd, nome, tel);


    }
}
