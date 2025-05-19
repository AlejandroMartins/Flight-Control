#ifndef PILOTO_H
#define PILOTO_H

#include <string>
using namespace std;

class Piloto {
private:
    string nome;
    string matricula;
    string breve;
    double horasDeVoo;

public:
    // Construtor
    Piloto(string nome, string matricula, string breve, double horasDeVoo);

    // Getters
    string getNome() const;
    string getMatricula() const;
    string getBreve() const;
    double getHorasDeVoo() const;

    // Setters
    void setNome(string novoNome);
    void setMatricula(string novaMatricula);
    void setBreve(string novoBreve);
    void setHorasDeVoo(double novasHoras);
};

#endif // PILOTO_H
