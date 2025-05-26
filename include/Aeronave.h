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
    Aeronave(int codigo, int capacidade, string modelo, double velocidadeMedia, double autonomiaDeVoo);

    // Getters
    int getCodigo() const;
    int getCapacidade() const;
    string getModelo() const;
    double getVelocidadeMedia() const;
    double getAutonomiaDeVoo() const;

    // Setters
    void setCodigo(int novoCodigo);
    void setCapacidade(int novaCapacidade);
    void setModelo(string novoModelo);
    void setVelocidadeMedia(double novaVelocidade);
    void setAutonomiaDeVoo(double novaAutonomia);

    //sobrecarga do operador >>
    friend std::istream& operator>>(std::istream& is, Aeronave& aeronave);
};

#endif // AERONAVE_H
