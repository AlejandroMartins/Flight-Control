#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <vector>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"
#include "pesquisa.h"

void salvarDados( std::vector<Aeronave> &aeronaves,
                 const std::vector<Piloto> &pilotos,
                  std::vector<Passageiro> &passageiros,
                 const std::vector<Voo> &voos);

void carregarDados(std::vector<Aeronave> &aeronaves,
                  std::vector<Piloto> &pilotos,
                  std::vector<Passageiro> &passageiros,
                  std::vector<Voo> &voos);

#endif
