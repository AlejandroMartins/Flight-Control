#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa
{
protected:
    string nome;

public:
    // Getters
    string getNome() const;

    // Setters
    void setNome(string novoNome);
};

#endif // PESSOA_H
