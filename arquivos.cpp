#include "../include/arquivos.h"
#include <fstream>
#include <iostream>

using namespace std;

void salvarDados(const vector<Aeronave> &aeronaves,
                 const vector<Piloto> &pilotos,
                 const vector<Passageiro> &passageiros,
                 const vector<Voo> &voos)
{
    // Salvar Aeronaves
    ofstream fa("./files/aeronaves.csv");
    if (fa.is_open())
    {
        for (const auto &a : aeronaves)
        {
            fa << a.getCodigo() << ","
               << a.getCapacidade() << ","
               << a.getModelo() << ","
               << a.getVelocidadeMedia() << ","
               << a.getAutonomiaDeVoo() << endl;
        }
        fa.close();
    }

    // Salvar Pilotos
    ofstream fp("./files/pilotos.csv");
    if (fp.is_open())
    {
        for (const auto &p : pilotos)
        {
            fp << p.getNome() << ","
               << p.getMatricula() << ","
               << p.getBreve() << ","
               << p.getHorasDeVoo() << endl;
        }
        fp.close();
    }

    // Salvar Passageiros
    ofstream fpa("./files/passageiros.csv");
    if (fpa.is_open())
    {
        for (const auto &p : passageiros)
        {
            fpa << p.getNome() << ","
                << p.getCpf() << ","
                << p.getNumeroBilhete() << endl;
        }
        fpa.close();
    }

    // Salvar Voos
    ofstream fv("./files/voos.csv");
    if (fv.is_open())
    {
        for (const auto &v : voos)
        {
            fv << v.getCodigo() << ","
               << v.getOrigem() << ","
               << v.getDestino() << ","
               << v.getDistancia() << ","
               << v.getHoraDeSaida() << ","
               << v.getAeronave().getCodigo() << ","
               << v.getComandante().getMatricula() << ","
               << v.getPrimeiroOficial().getMatricula() << ","
               << v.getPassageiros().size() << ",";

            // Escrever os CPFs dos passageiros separados por '|'
            const auto &passageiros = v.getPassageiros();
            for (int i = 0; i < passageiros.size(); i++)
            {
                fv << passageiros[i].getCpf();
                if (i != passageiros.size() - 1)
                    fv << "|";
            }
            fv << endl;
        }
        fv.close();
    }
}
