
#include "pesquisa.h"
using namespace std;

int encontrarIndiceAeronavePorCodigo(const vector<Aeronave> &aeronaves, int codigo)
{
    for (int i = 0; i < (int)aeronaves.size(); i++)
    {
        if (aeronaves[i].getCodigo() == codigo)
        {
            return i;
        }
    }
    return -1; // Não encontrado
}

int encontrarIndicePilotoPorMatricula(const vector<Piloto> &pilotos, string matricula)
{
    for (int i = 0; i < pilotos.size(); i++)
    {
        if (pilotos[i].getMatricula() == matricula)
        {
            return i;
        }
    }
    return -1; // Não encontrado
}

int encontrarIndicePassageiroPorCpf(const vector<Passageiro> &passageiros, const string &cpf)
{
    for (int i = 0; i < (int)passageiros.size(); i++)
    {
        if (passageiros[i].getCpf() == cpf)
        {
            return i;
        }
    }
    return -1;
}

int encontrarIndiceVooPorCodigo(const vector<Voo> &voos, int codigo)
{
    for (int i = 0; i < (int)voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            return i;
        }
    }
    return -1;
}
