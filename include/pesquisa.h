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

int encontrarIndiceAeronavePorCodigo(const vector<Aeronave> &aeronaves, int codigo);

int encontrarIndicePilotoPorMatricula(const vector<Piloto> &pilotos, string matricula);

int encontrarIndicePassageiroPorCpf(const vector<Passageiro> &passageiros, const string &cpf);

int encontrarIndiceVooPorCodigo(const vector<Voo> &voos, int codigo);

#endif