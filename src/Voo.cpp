#include "../include/Voo.h"
#include "../include/pesquisa.h"
#include <iostream>
using namespace std;

// Construtor
Voo::Voo(int codigo, string origem, string destino, double distancia, string horaDeSaida,
         int numeroDeEscalas, double tempoEstimado,
         const Aeronave& aeronave, const Piloto& comandante, const Piloto& primeiroOficial)
    : aeronave(aeronave), comandante(comandante), primeiroOficial(primeiroOficial)
{
    this->codigo = codigo;
    this->origem = origem;
    this->destino = destino;
    this->distancia = distancia;
    this->horaDeSaida = horaDeSaida;
    this->numeroDeEscalas = numeroDeEscalas;
    this->tempoEstimado = tempoEstimado;
    this->aeronave = aeronave;
    this->comandante = comandante;
    this->primeiroOficial = primeiroOficial;
}

// esse segundo construtor sera usado na leitura dos arquivos, por isso existem dois construtores
Voo::Voo(int codigo, string origem, string destino, double distancia, string horaDeSaida, int numeroDeEscalas, double tempoEstimado){
    this->codigo = codigo;
    this->origem = origem;
    this->destino = destino;
    this->distancia = distancia;
    this->horaDeSaida = horaDeSaida;
    this->numeroDeEscalas = numeroDeEscalas;
    this->tempoEstimado = tempoEstimado;
}

// Getters
int Voo::getCodigo() const { return codigo; }
string Voo::getOrigem() const { return origem; }
string Voo::getDestino() const { return destino; }
double Voo::getDistancia() const { return distancia; }
string Voo::getHoraDeSaida() const { return horaDeSaida; }
int Voo::getNumeroDeEscalas() const { return numeroDeEscalas; }
double Voo::getTempoEstimado() const { return tempoEstimado; }
Aeronave Voo::getAeronave() const { return aeronave; }
Piloto Voo::getComandante() const { return comandante; }
Piloto Voo::getPrimeiroOficial() const { return primeiroOficial; }
vector<Passageiro> Voo::getPassageiros() const { return passageiros; }

// Setters
void Voo::setCodigo(int c) { codigo = c; }
void Voo::setOrigem(const string &o) { origem = o; }
void Voo::setDestino(const string &d) { destino = d; }
void Voo::setDistancia(double dist) { distancia = dist; }
void Voo::setHoraDeSaida(const string &hora) { horaDeSaida = hora; }
void Voo::setNumeroDeEscalas(int escalas) { numeroDeEscalas = escalas; }
void Voo::setTempoEstimado(double tempo) { tempoEstimado = tempo; }
void Voo::setAeronave(const Aeronave &a) { aeronave = a; }
void Voo::setComandante(const Piloto &p) { comandante = p; }
void Voo::setPrimeiroOficial(const Piloto &p) { primeiroOficial = p; }


// imprime todos os passageiros do voo
void Voo::listarPassageiros() {
    cout << "Aeronave: " << getAeronave().getModelo() << endl;
    cout << "Codigo da aeronave: " << getAeronave().getCodigo() << endl;
    cout << "Passageiros do voo " << codigo << ":\n";
    if (passageiros.empty()) {
        cout << "Nenhum passageiro embarcado.\n";
        return;
    }

    for (const auto& p : passageiros) {
        cout << "- " << p.getNome() << "\n";  
    }
}

//adciona um passageiro no vector
void Voo::adicionarPassageiro( Passageiro &p){
    passageiros.push_back(p);
    p.add_voo(codigo);
}

// retorna a quantidade de passageiros cadastrados no voo
int Voo::qtdPassageiros(){
    return passageiros.size();
}

// para saber se o passageiro portador desse cpf esta no voo
bool Voo::passageiro_listado (string cpf){
    return (encontrarIndicePassageiroPorCpf(passageiros, cpf) != -1);
}