#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"
#include <string>
#include <vector>
using namespace std;

class Passageiro : public Pessoa {
private:
    string cpf;
    string numeroBilhete;
    vector<int> voos_que_participa;

public:
    // Construtor
    Passageiro(string nome, string cpf, string numeroBilhete);

    // Getters
    string getCpf() const;
    string getNumeroBilhete() const;
    int getCodVoo(int i);

    // Setters
    void setCpf(string novoCpf);
    void setNumeroBilhete(string novoBilhete);

    // funçao que adciona um voo para o passageiro
    void add_voo(int cod);

    int qtd_voos();

};

#endif
