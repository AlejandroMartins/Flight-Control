#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "./Pessoa.h"
using namespace std;

class Passageiro : public Pessoa {
private:
    string cpf;
    string numeroBilhete;

public:
    // Construtor
    Passageiro(string nome, string cpf, string numeroBilhete) {
        this->nome = nome;
        this->cpf = cpf;
        this->numeroBilhete = numeroBilhete;
    }

    // Getters
  
    string getCpf() const {
        return cpf;
    }

    string getNumeroBilhete() const {
        return numeroBilhete;
    }

    // Setters

    void setCpf(string novoCpf) {
        cpf = novoCpf;
    }

    void setNumeroBilhete(string novoBilhete) {
        numeroBilhete = novoBilhete;
    }
};

#endif 