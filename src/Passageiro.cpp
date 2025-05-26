#include "../include/Passageiro.h"

// Construtor
Passageiro::Passageiro(string nome, string cpf, string numeroBilhete) {
    this->nome = nome;
    this->cpf = cpf;
    this->numeroBilhete = numeroBilhete;
}

// Getters
string Passageiro::getCpf() const {
    return cpf;
}

string Passageiro::getNumeroBilhete() const {
    return numeroBilhete;
}

// Setters
void Passageiro::setCpf(string novoCpf) {
    cpf = novoCpf;
}

void Passageiro::setNumeroBilhete(string novoBilhete) {
    numeroBilhete = novoBilhete;
}

// sobrecarga do operador >>
std::istream& operator>>(std::istream& is, Passageiro& passageiro) {
    string nome, cpf, numeroBilhete;
    char delim;

    is >> nome >> delim
       >> cpf >> delim
       numeroBilhete >> delim;
    
    passageiro = Passageiro(nome, cpf, numeroBilhete);
    return is;
}
