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

void aeronaves_mais_usadas(vector<Aeronave> &aeronaves){
    int maior = 0;
    int maior2 = 0;
    for(int i = 0; i < aeronaves.size(); i++)
    {
        if(aeronaves[i].qtd_voo() > aeronaves[maior].qtd_voo())
            maior = i;
    }

    for(int j = 0; j < aeronaves.size(); j++)
    {
        if( (j != maior) && aeronaves[j].qtd_voo() > aeronaves[maior2].qtd_voo())
            maior2 = j;
    }
    cout << "   "<< aeronaves[maior].getModelo() << endl;
    cout << "   "<< aeronaves[maior2].getModelo() << endl;
}

void dist_total_aeronave(vector<Aeronave> &aeronaves, vector<Voo> &voos){
    for(int i = 0; i < aeronaves.size(); i++)
    {
        int total = 0;
        for(int j = 0; j < aeronaves[i].qtd_voo(); j++)
        {
            int voo_cod = aeronaves[i].getCodVoo(j);
            int voo_posic = encontrarIndiceVooPorCodigo(voos, voo_cod);
            total += voos[voo_posic].getDistancia();
        }
        cout << "   "<< aeronaves[i].getModelo() << " = " << total << " km rodados" << endl;
    }
}