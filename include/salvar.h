#ifndef SALVAR_H
#define SALVAR_H

#include <vector>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"

void salvarDados(const std::vector<Aeronave> &aeronaves,
                 const std::vector<Piloto> &pilotos,
                 const std::vector<Passageiro> &passageiros,
                 const std::vector<Voo> &voos);

#endif
