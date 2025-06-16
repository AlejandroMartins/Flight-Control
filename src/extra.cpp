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