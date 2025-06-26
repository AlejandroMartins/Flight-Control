#include "Aeronave.h"

// Construtor
Aeronave::Aeronave(int codigo, int capacidade, string modelo, double velocidadeMedia, double autonomiaDeVoo) {
    this->codigo = codigo;
    this->capacidade = capacidade;
    this->modelo = modelo;
    this->velocidadeMedia = velocidadeMedia;
    this->autonomiaDeVoo = autonomiaDeVoo;
}

Aeronave::Aeronave(){
    codigo = 0;
    capacidade = 0;
    modelo = "";
    velocidadeMedia = 0;
    autonomiaDeVoo = 0;
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

int Aeronave::getCodVoo(int i){
    return voos_aeronave[i];
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

int Aeronave::qtd_voo(){
    return voos_aeronave.size();
}

void Aeronave::add_voo(int i){
    voos_aeronave.push_back(i);
}

