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

// funcao que retorna a media de passageiros por voo
double media_passageiro_por_voo(vector<Voo> &voos);

// funcao para encontrar os passageiros que participaram de mais de 1 voo
void passageiroMaisVoo(vector<Passageiro> &passageiros);

// funçao para listar os voos com mais de 90% da capacidade maxima
void voo_quase_cheio(vector<Voo> &voos);
#endif