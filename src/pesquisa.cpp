
#include "pesquisa.h"
using namespace std;


// retorna a posiçao da aeronave no vector
// é passado o codigo da aeronava
// caso esse codigo nao esteja no vetor, retorna -1
int encontrarIndiceAeronavePorCodigo(const vector<Aeronave> &aeronaves, int codigo)
{
    for (int i = 0; i < (int)aeronaves.size(); i++)
    {
        if (aeronaves[i].getCodigo() == codigo)
        {
            return i;
        }
    }
    return -1; 
}


// retorna a posiçao do piloto no vector
// é passado a matricula do piloto
// caso essa matricula nao esteja no vetor, retorna -1
int encontrarIndicePilotoPorMatricula(const vector<Piloto> &pilotos, string matricula)
{
    for (int i = 0; i < pilotos.size(); i++)
    {
        if (pilotos[i].getMatricula() == matricula)
        {
            return i;
        }
    }
    return -1; 
}


// retorna a posiçao do passageiro no vector
// é passado seu cpf
// caso esse cpf nao esteja no vetor, retorna -1
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


// retorna a posiçao do voo no vector
// é passado o codigo do voo 
// caso esse codigo nao esteja no vetor, retorna -1
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
