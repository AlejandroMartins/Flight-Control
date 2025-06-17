#include "extra.h"
using namespace std;

double media_passageiro_por_voo(vector<Voo> &voos){
    int total = 0;
    for (int i = 0; i < (int)voos.size(); i++)
    {
        total += voos[i].qtdPassageiros();
    }

    double totVoos = (double) voos.size();

    return (total / totVoos);
}

void passageiroMaisVoo(vector<Passageiro> &passageiros){
    for(int i = 0; i < passageiros.size(); i++)
    {
        if(passageiros[i].qtd_voos() > 1)
        {
            cout << "   "<< passageiros[i].getNome() << ": " << passageiros[i].qtd_voos() << " voos"<< endl;
        }
    }
}

void voo_quase_cheio(vector<Voo> &voos){
    bool teste;
    teste = false;
    for(int i = 0; i < voos.size(); i++)
    {
        if(voos[i].qtdPassageiros() >= (0.9 * voos[i].getAeronave().getCapacidade()))
        {
            cout << "   voo "<< voos[i].getCodigo() << endl;
            teste = true;
        }
    }
    if(!teste)
        cout<< "    nenhum" << endl;
}