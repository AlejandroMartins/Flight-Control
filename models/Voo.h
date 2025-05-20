#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"

using namespace std;

class Voo
{
private:
    int codigo;
    string origem;
    string destino;
    double distancia;
    string horaDeSaida;
    int numeroDeEscalas;
    double tempoEstimado;
    Aeronave aeronave;
    Piloto comandante;
    Piloto primeiroOficial;
    vector<Passageiro> passageiros;

public:
    // Construtor
    Voo(int codigo, string origem, string destino, double distancia, string horaDeSaida,
        int numeroDeEscalas, double tempoEstimado,
        Aeronave aeronave, Piloto comandante, Piloto primeiroOficial)
    {
        this->codigo = codigo;
        this->origem = origem;
        this->destino = destino;
        this->distancia = distancia;
        this->horaDeSaida = horaDeSaida;
        this->numeroDeEscalas = numeroDeEscalas;
        this->tempoEstimado = tempoEstimado;
        this->aeronave = aeronave;
        this->comandante = comandante;
        this->primeiroOficial = primeiroOficial;
    }

    // Getters
    int getCodigo() const { return codigo; }
    string getOrigem() const { return origem; }
    string getDestino() const { return destino; }
    double getDistancia() const { return distancia; }
    string getHoraDeSaida() const { return horaDeSaida; }
    int getNumeroDeEscalas() const { return numeroDeEscalas; }
    double getTempoEstimado() const { return tempoEstimado; }
    Aeronave getAeronave() const { return aeronave; }
    Piloto getComandante() const { return comandante; }
    Piloto getPrimeiroOficial() const { return primeiroOficial; }
    vector<Passageiro> getPassageiros() const { return passageiros; }

    // Setters
    void setCodigo(int c) { codigo = c; }
    void setOrigem(const string &o) { origem = o; }
    void setDestino(const string &d) { destino = d; }
    void setDistancia(double dist) { distancia = dist; }
    void setHoraDeSaida(const string &hora) { horaDeSaida = hora; }
    void setNumeroDeEscalas(int escalas) { numeroDeEscalas = escalas; }
    void setTempoEstimado(double tempo) { tempoEstimado = tempo; }
    void setAeronave(const Aeronave &a) { aeronave = a; }
    void setComandante(const Piloto &p) { comandante = p; }
    void setPrimeiroOficial(const Piloto &p) { primeiroOficial = p; }

};

#endif
