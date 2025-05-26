#include "../include/Piloto.h"

// Construtor
Piloto::Piloto(string nome, string matricula, string breve, double horasDeVoo)
{
    this->nome = nome;
    this->matricula = matricula;
    this->breve = breve;
    this->horasDeVoo = horasDeVoo;
}

// Getters
string Piloto::getMatricula() const
{
    return matricula;
}

string Piloto::getBreve() const
{
    return breve;
}

double Piloto::getHorasDeVoo() const
{
    return horasDeVoo;
}

// Setters
void Piloto::setMatricula(string novaMatricula)
{
    matricula = novaMatricula;
}

void Piloto::setBreve(string novoBreve)
{
    breve = novoBreve;
}

void Piloto::setHorasDeVoo(double novasHoras)
{
    horasDeVoo = novasHoras;
}

std::istream& operator>>(std::istream& is, Piloto& piloto) {
    string nome, matricula, breve;
    int horasDeVoo;
    char delim;

    is >> nome >> delim
       >> matricula >> delim
       >> breve >> delim
       >> horasDeVoo >> delim;
    
    piloto = Piloto(nome, matricula, breve, horasDeVoo);
    return is;
}
