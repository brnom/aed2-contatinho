#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<string,int> Dicio;

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
int InsereContato(Dicio &cont, string _nam, int _tel){

    int comp=PesquisaContato(cont, _nam);

    if(comp==0 || comp==-1){
        //se nao achou, insere e retorna 1
        cont.insert(pair<string,int>(_nam, _tel));
        return 1;
    }

    //se deu ruim retorna 0
    return 0;
    
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
int RemoveContato(Dicio &cont, string _nam){
    return 0;
}

/* Requesitos:
 * - se nao existir contato, imprimir "Operacao invalida: contatinho nao encontrado"
*/
int AlteraContato(Dicio &cont, string _nam, int _tel){
    return 0;
}


/* Funcao com intuito de entender como funfa
 * o map e sua impressao de chaves e valores
int ImprimeContato(Dicio &cont){
    Dicio::iterator itr;
    if(cont.begin() == cont.end()){
        return 0;
    } 
    cout << "\nLista de contatos: \n"; 
    cout << "\tNOME\tCELULAR\n"; 
    for (itr = cont.begin(); itr != cont.end(); ++itr) { 
        cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
    } 
    cout << endl;
    return 1;
}*/

int main(int argc, char *argv[]){

    string cmd, nam;
    int tel;
    Dicio contatinhos;

    while (1){
        cout << "entrada:: ";
        cin >> cmd;
        int flag=0;

        //Insere 
        if(cmd.compare("I")==0){
            cin >> nam >> tel;
            flag = InsereContato(contatinhos, nam, tel);

            if (flag == 0)
                cout << "contatinho ja inserido" << endl;
        }

        //Pesquisa
        else if(cmd.compare("P")==0){
            cin >> nam;
            flag = PesquisaContato(contatinhos, nam);
            
            if (flag == -1 || flag ==0)
                cout<<"Contatinho nao encontrado"<<endl;
            else
                cout <<"Contato encontrado: telefone "<< flag<<endl;
        }

        else if(cmd.compare("R")==0){
            cin >> nam;
            flag = RemoveContato(contatinhos, nam);

            if (flag == 0)
                cout << "contatinho removido" << endl;
        }

        else if(cmd.compare("A")==0){
            cin >> nam >> tel;
            flag = AlteraContato(contatinhos, nam, tel);

            if (flag == 0)
                cout << "contatinho alterado!" << endl;
        }

        /*
        else if(cmd.compare("Pr")==0){
            flag = ImprimeContato(contatinhos);
            if (flag==0)
                cout<<"lista vazia baby.."<<endl;

        }*/

        else if(cmd.compare("0")==0)
            break;

        else
            cout<<"operacao inexistente!"<<endl;

    }
    
    


    return 0;
}
