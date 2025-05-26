#include "../include/Aeronave.h"

// Construtor
Aeronave::Aeronave(int codigo, int capacidade, string modelo, double velocidadeMedia, double autonomiaDeVoo) {
    this->codigo = codigo;
    this->capacidade = capacidade;
    this->modelo = modelo;
    this->velocidadeMedia = velocidadeMedia;
    this->autonomiaDeVoo = autonomiaDeVoo;
}

// Getters
int Aeronave::getCodigo() const {
    return codigo;
}

int Aeronave::getCapacidade() const {
    return capacidade;
}

string Aeronave::getModelo() const {
    return modelo;
}

double Aeronave::getVelocidadeMedia() const {
    return velocidadeMedia;
}

double Aeronave::getAutonomiaDeVoo() const {
    return autonomiaDeVoo;
}

// Setters
void Aeronave::setCodigo(int novoCodigo) {
    codigo = novoCodigo;
}

void Aeronave::setCapacidade(int novaCapacidade) {
    capacidade = novaCapacidade;
}

void Aeronave::setModelo(string novoModelo) {
    modelo = novoModelo;
}

void Aeronave::setVelocidadeMedia(double novaVelocidade) {
    velocidadeMedia = novaVelocidade;
}

void Aeronave::setAutonomiaDeVoo(double novaAutonomia) {
    autonomiaDeVoo = novaAutonomia;
}

std::istream& operator>>(std::istream& is, Aeronave& aeronave) {
    string codigo, modelo;
    int capacidade;
    float velocidadeMedia, autonomia;
    
    char delim;
    is >> codigo >> delim
       >> capacidade >> delim
       >> modelo >> delim
       >> velocidadeMedia >> delim
       >> autonomia >> delim;
    
    aeronave = Aeronave(codigo, capacidade, modelo, velocidadeMedia, autonomia);
    return is;
}
