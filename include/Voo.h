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
         const Aeronave& aeronave, const Piloto& comandante, const Piloto& primeiroOficial);
    Voo(int codigo, string origem, string destino, double distancia, string horaDeSaida, int numeroDeEscalas, double tempoEstimado);

    // Getters
    int getCodigo() const;
    string getOrigem() const;
    string getDestino() const;
    double getDistancia() const;
    string getHoraDeSaida() const;
    int getNumeroDeEscalas() const;
    double getTempoEstimado() const;
    Aeronave getAeronave() const;
    Piloto getComandante() const;
    Piloto getPrimeiroOficial() const;
    vector<Passageiro> getPassageiros() const;


    // Setters
    void setCodigo(int c);
    void setOrigem(const string &o);
    void setDestino(const string &d);
    void setDistancia(double dist);
    void setHoraDeSaida(const string &hora);
    void setNumeroDeEscalas(int escalas);
    void setTempoEstimado(double tempo);
    void setAeronave(const Aeronave &a);
    void setComandante(const Piloto &p);
    void setPrimeiroOficial(const Piloto &p);
    
    // Outros métodos para gerenciar passageiros podem ser adicionados aqui
    void listarPassageiros();
    void adicionarPassageiro( Passageiro &p);

    // funçao para saber a quantidade de passageiros em um voo
    int qtdPassageiros();
};

#endif // VOO_H
