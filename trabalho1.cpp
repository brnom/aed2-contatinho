#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map <string, int> Dicio;


bool InsereContato(Dicio &cont, string _nam, int _tel){
    cont.insert(pair<string,int>(_nam, _tel));
    return 1;
}

bool PesquisaContato(Dicio &cont, string _nam){
    return 1;
}

bool RemoveContato(Dicio &cont, string _nam){
    return 1;
}

bool AlteraContato(Dicio &cont, string _nam, int _tel){
    return 1;
}

int main(int argc, char *argv[]){

    string cmd, nam;
    int tel;
    Dicio contatinhos;

    while (cmd.compare("0")!=0){
        cout << "Digite o entrada: ";
        cin >> cmd;
        bool flag=0;


        if(cmd.compare("I")==0){
            cin >> nam >> tel;

            flag = InsereContato(contatinhos, nam, tel);
            if (flag == 1)
                cout << "contatinho ja inserido" << endl;
        }

        if(cmd.compare("P")==0){
            cin >> nam;

            flag = PesquisaContato(contatinhos, nam);
            if (flag == 1)
                cout << "contatinho pesquisado" << endl;
        }

        if(cmd.compare("R")==0){
            cin >> nam;

            flag = RemoveContato(contatinhos, nam);
            if (flag == 1)
                cout << "contatinho removido" << endl;
        }
        
        if(cmd.compare("A")==0){
            cin >> nam >> tel;

            flag = AlteraContato(contatinhos, nam, tel);
            if (flag == 1)
                cout << "contatinho alterado!" << endl;
        }
        
    }
    
    


    return 0;
}
