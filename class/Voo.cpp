#include <string>
#include "../include/Aeronave.h"
#include "../include/Piloto.h"
#include "../include/Passageiro.h"
#include <vector>
using namespace std;

class Voo {
private:
    string codigo;
    string origem;
    string destino;
    double distancia; 
    Aeronave aeronave;
    string horaSaidaPrevista;
    Piloto comandante;
    Piloto primeiroOficial;
    vector<Passageiro> passageiros;

public:

    // Getters
    string getCodigo() const {
        return codigo;
    }

    string getOrigem() const {
        return origem;
    }

    string getDestino() const {
        return destino;
    }

    double getDistancia() const {
        return distancia;
    }

    Aeronave getAeronave() const {
        return aeronave;
    }

    string getHoraSaidaPrevista() const {
        return horaSaidaPrevista;
    }

    Piloto getComandante() const {
        return comandante;
    }

    Piloto getPrimeiroOficial() const {
        return primeiroOficial;
    }

    // Setters
    void setCodigo(string novoCodigo) {
        codigo = novoCodigo;
    }

    void setOrigem(string novaOrigem) {
        origem = novaOrigem;
    }

    void setDestino(string novoDestino) {
        destino = novoDestino;
    }

    void setDistancia(double novaDistancia) {
        distancia = novaDistancia;
    }

    void setAeronave(Aeronave novaAeronave) {
        aeronave = novaAeronave;
    }

    void setHoraSaidaPrevista(string novaHora) {
        horaSaidaPrevista = novaHora;
    }

    void setComandante(Piloto novoComandante) {
        comandante = novoComandante;
    }

    void setPrimeiroOficial(Piloto novoPrimeiroOficial) {
        primeiroOficial = novoPrimeiroOficial;
    }
};
