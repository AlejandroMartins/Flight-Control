#ifndef PILOTO_H
#define PILOTO_H

#include "Pessoa.h"
#include <string>
using namespace std;

class Piloto : public Pessoa
{
private:
    string matricula;
    string breve;
    double horasDeVoo;

public:
    // Construtor
    Piloto(string nome, string matricula, string breve, double horasDeVoo);
    Piloto();

    // Getters
    string getMatricula() const;
    string getBreve() const;
    double getHorasDeVoo() const;

    // Setters
    void setMatricula(string novaMatricula);
    void setBreve(string novoBreve);
    void setHorasDeVoo(double novasHoras);

};

#endif // PILOTO_H
