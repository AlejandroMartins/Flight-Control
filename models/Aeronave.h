#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
using namespace std;

class Aeronave {
private:
    int codigo;
    int capacidade;
    string modelo;
    double velocidadeMedia;
    double autonomiaDeVoo;

public:
     // Construtor
     Aeronave(int codigo, int capacidade, string modelo, double velocidadeMedia, double autonomiaDeVoo) {
        this->codigo = codigo;
        this->capacidade = capacidade;
        this->modelo = modelo;
        this->velocidadeMedia = velocidadeMedia;
        this->autonomiaDeVoo = autonomiaDeVoo;
    }

    // Getters
    int getCodigo() const {
        return codigo;
    }

    int getCapacidade() const {
        return capacidade;
    }

    string getModelo() const {
        return modelo;
    }

    double getVelocidadeMedia() const {
        return velocidadeMedia;
    }

    double getAutonomiaDeVoo() const {
        return autonomiaDeVoo;
    }

    // Setters
    void setCodigo(int novoCodigo) {
        codigo = novoCodigo;
    }

    void setCapacidade(int novaCapacidade) {
        capacidade = novaCapacidade;
    }

    void setModelo(string novoModelo) {
        modelo = novoModelo;
    }

    void setVelocidadeMedia(double novaVelocidade) {
        velocidadeMedia = novaVelocidade;
    }

    void setAutonomiaDeVoo(double novaAutonomia) {
        autonomiaDeVoo = novaAutonomia;
    }
};

#endif // AERONAVE_H
