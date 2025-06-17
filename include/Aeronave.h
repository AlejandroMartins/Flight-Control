#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
#include <vector>
using namespace std;

class Aeronave {
private:
    int codigo;
    int capacidade;
    string modelo;
    double velocidadeMedia;
    double autonomiaDeVoo;
    vector<int> voos_aeronave;

public:
    // Construtor
    Aeronave(int codigo, int capacidade, string modelo, double velocidadeMedia, double autonomiaDeVoo);
    Aeronave();

    // Getters
    int getCodigo() const;
    int getCapacidade() const;
    string getModelo() const;
    double getVelocidadeMedia() const;
    double getAutonomiaDeVoo() const;
    int getCodVoo(int i);

    // Setters
    void setCodigo(int novoCodigo);
    void setCapacidade(int novaCapacidade);
    void setModelo(string novoModelo);
    void setVelocidadeMedia(double novaVelocidade);
    void setAutonomiaDeVoo(double novaAutonomia);

    // retorna a quantidade de voo que a aeronave participa
    int qtd_voo();

    //adiciona voo no vetor de voos
    void add_voo(int i);

};

#endif // AERONAVE_H
