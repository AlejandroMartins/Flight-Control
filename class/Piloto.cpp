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
    Piloto(string nome, string matricula, string breve, double horasDeVoo) {
        this->nome = nome;
        this->matricula = matricula;
        this->breve = breve;
        this->horasDeVoo = horasDeVoo;
    }

    // Getters
    string getNome() const {
        return nome;
    }

    string getMatricula() const {
        return matricula;
    }

    string getBreve() const {
        return breve;
    }

    double getHorasDeVoo() const {
        return horasDeVoo;
    }

    // Setters
    void setNome(string novoNome) {
        nome = novoNome;
    }

    void setMatricula(string novaMatricula) {
        matricula = novaMatricula;
    }

    void setBreve(string novoBreve) {
        breve = novoBreve;
    }

    void setHorasDeVoo(double novasHoras) {
        horasDeVoo = novasHoras;
    }
};
