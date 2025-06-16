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

int Passageiro::getCodVoo(int i){
    return voos_que_participa[i];
}

// Setters
void Passageiro::setCpf(string novoCpf) {
    cpf = novoCpf;
}

void Passageiro::setNumeroBilhete(string novoBilhete) {
    numeroBilhete = novoBilhete;
}

void Passageiro::add_voo(int cod){
    voos_que_participa.push_back(cod);
}

int Passageiro::qtd_voos(){
    return voos_que_participa.size();
}




