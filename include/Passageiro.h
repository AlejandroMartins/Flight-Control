#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"
#include <string>
using namespace std;

class Passageiro : public Pessoa {
private:
    string cpf;
    string numeroBilhete;

public:
    // Construtor
    Passageiro(string nome, string cpf, string numeroBilhete);

    // Getters
    string getCpf() const;
    string getNumeroBilhete() const;

    // Setters
    void setCpf(string novoCpf);
    void setNumeroBilhete(string novoBilhete);

    // sobrecarga do operador >>
    friend std::istream& operator>>(std::istream& is, Passageiro& passageiro);
};

#endif
