#include <string>
using namespace std;

class Passageiro {
private:
    string nome;
    string cpf;
    string numeroBilhete;
    string noaew;

public:
    // Construtor
    Passageiro(string nome, string cpf, string numeroBilhete) {
        this->nome = nome;
        this->cpf = cpf;
        this->numeroBilhete = numeroBilhete;
    }

    // Getters
    string getNome() const {
        return nome;
    }

    string getCpf() const {
        return cpf;
    }

    string getNumeroBilhete() const {
        return numeroBilhete;
    }

    // Setters
    void setNome(string novoNome) {
        nome = novoNome;
    }

    void setCpf(string novoCpf) {
        cpf = novoCpf;
    }

    void setNumeroBilhete(string novoBilhete) {
        numeroBilhete = novoBilhete;
    }
};
