#ifndef PESSOA_H
#define PESSOA_H

#include <string>
class Pessoa
{
protected:
    string nome;

public:
    // Getters
    string getNome() const
    {
        return nome;
    }

    // Setters
    void setNome(string novoNome)
    {
        nome = novoNome;
    }
};


#endif // PASSAGEIRO_H
