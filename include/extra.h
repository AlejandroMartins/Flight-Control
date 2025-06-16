#ifndef EXTRA_H
#define EXTRA_H  

#include <string>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

double media_passageiro_por_voo(vector<Voo> &voos);

void passageiroMaisVoo(vector<Passageiro> &passageiros);

#endif