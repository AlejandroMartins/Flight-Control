#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
using namespace std;

class Passageiro {
private:
    string nome;
    string cpf;
    string numeroBilhete;

public:
    // Construtor
    Passageiro(string nome, string cpf, string numeroBilhete);

    // Getters
    string getNome() const;
    string getCpf() const;
    string getNumeroBilhete() const;

    // Setters
    void setNome(string novoNome);
    void setCpf(string novoCpf);
    void setNumeroBilhete(string novoBilhete);
};

#endif // PASSAGEIRO_H
