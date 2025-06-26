#ifndef PESQUISA_H
#define PESQUISA_H  

#include <string>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

// retorna a posiçao da aeronave no vector
// é passado o codigo da aeronava
// caso esse codigo nao esteja no vetor, retorna -1
int encontrarIndiceAeronavePorCodigo(const vector<Aeronave> &aeronaves, int codigo);


// retorna a posiçao do piloto no vector
// é passado a matricula do piloto
// caso essa matricula nao esteja no vetor, retorna -1
int encontrarIndicePilotoPorMatricula(const vector<Piloto> &pilotos, string matricula);


// retorna a posiçao do passageiro no vector
// é passado seu cpf
// caso esse cpf nao esteja no vetor, retorna -1
int encontrarIndicePassageiroPorCpf(const vector<Passageiro> &passageiros, const string &cpf);


// retorna a posiçao do voo no vector
// é passado o codigo do voo 
// caso esse codigo nao esteja no vetor, retorna -1
int encontrarIndiceVooPorCodigo(const vector<Voo> &voos, int codigo);

#endif