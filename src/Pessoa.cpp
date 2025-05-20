#include "../include/Pessoa.h"

// Getter
string Pessoa::getNome() const
{
    return nome;
}

// Setter
void Pessoa::setNome(string novoNome)
{
    nome = novoNome;
}
