#include "./include/arquivos.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;




void salvarDados( vector<Aeronave> &aeronaves,
                 const vector<Piloto> &pilotos,
                  vector<Passageiro> &passageiros,
                 const vector<Voo> &voos)
{
    // Salvar Aeronaves
    ofstream fa("./files/aeronaves.csv");
    if (fa.is_open())
    {
        for (auto &a : aeronaves)
        {
            fa << a.getCodigo() << ","
               << a.getCapacidade() << ","
               << a.getModelo() << ","
               << a.getVelocidadeMedia() << ","
               << a.getAutonomiaDeVoo() << ","
               << a.qtd_voo() << ":";

               for(int i = 0; i < a.qtd_voo(); i++)
               {
                    fa << a.getCodVoo(i);
                    if(i != a.qtd_voo() - 1)
                        fa << "|";
               }

            fa << endl;
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
        for (auto &p : passageiros)
        {
            fpa << p.getNome() << ","
                << p.getCpf() << ","
                << p.getNumeroBilhete() << ","
                << p.qtd_voos() << ":";

                for(int i = 0; i< p.qtd_voos(); i++)
                {
                    fpa << p.getCodVoo(i);
                    if(i != p.qtd_voos() - 1)
                        fpa << "|";
                }
            fpa << endl;
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
               << v.getNumeroDeEscalas() << ","
               << v.getTempoEstimado() << ","
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


void carregarDados(vector<Aeronave> &aeronaves,
                  vector<Piloto> &pilotos,
                  vector<Passageiro> &passageiros,
                  vector<Voo> &voos) {
    // Limpar os vetores existentes
    aeronaves.clear();
    pilotos.clear();
    passageiros.clear();
    voos.clear();

    ifstream fa("./files/aeronaves.csv");
if (fa.is_open()) {
    string linha;
    while (getline(fa, linha)) {
        stringstream ss(linha);
        string codigo_str, capacidade_str, modelo, velocidade_str, autonomia_str, qtd_voos_str, voos_str;

        // Lê dados básicos
        getline(ss, codigo_str, ',');
        getline(ss, capacidade_str, ',');
        getline(ss, modelo, ',');
        getline(ss, velocidade_str, ',');
        getline(ss, autonomia_str, ',');
        getline(ss, qtd_voos_str, ':');

        // Converte dados básicos
        int codigo = stoi(codigo_str);
        int capacidade = stoi(capacidade_str);
        double velocidade = stod(velocidade_str);
        double autonomia = stod(autonomia_str);
        int qtd_voos = stoi(qtd_voos_str);

        // Cria aeronave
        Aeronave a(codigo, capacidade, modelo, velocidade, autonomia);

        // Lê voos se houver
        if (qtd_voos > 0) {
            getline(ss, voos_str);
            stringstream voos_ss(voos_str);
            string codigo_voo_str;
            
            for (int i = 0; i < qtd_voos; i++) {
                if (i > 0) getline(voos_ss, codigo_voo_str, '|');
                getline(voos_ss, codigo_voo_str, '|');
                int codigo_voo = stoi(codigo_voo_str);
                a.add_voo(codigo_voo);
            }
        }

        aeronaves.push_back(a);
    }
    fa.close();
}

    // Carregar Pilotos
    ifstream fp("./files/pilotos.csv");
    if (fp.is_open()) {
        string linha;
        while (getline(fp, linha)) {
            stringstream ss(linha);
            string nome, matricula, breve;
            int horasDeVoo;

            getline(ss, nome, ',');
            getline(ss, matricula, ',');
            getline(ss, breve, ',');
            ss >> horasDeVoo;

            Piloto p(nome, matricula, breve, horasDeVoo);
            pilotos.push_back(p);
        }
        fp.close();
    }

    // Carregar Passageiros
    ifstream fpa("./files/passageiros.csv");
    if (fpa.is_open()) {
        string linha;
        while (getline(fpa, linha)) {
            stringstream ss(linha);
            string nome, cpf, numeroBilhete, voosStr, qtdVoosStr;

            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, numeroBilhete, ',');
            getline(ss, qtdVoosStr, ':');

            Passageiro pa(nome, cpf, numeroBilhete);

            
            // Lê a string com todos os códigos de voo
            getline(ss, voosStr);
            int qtdVoos = stoi(qtdVoosStr);
            
            if (qtdVoos > 0) 
            {
                stringstream voosStream(voosStr);
                string codigoVooStr;
                
                // Lê cada código de voo separado por |
                for (int i = 0; i < qtdVoos; i++) {
                    if (i > 0) {
                        getline(voosStream, codigoVooStr, '|');  
                    }
                    getline(voosStream, codigoVooStr, '|');
                    int codigoVoo = stoi(codigoVooStr);
                    pa.add_voo(codigoVoo);  
                }
            }
            
            passageiros.push_back(pa);
        }
        fpa.close();
    }

    // Carregar Voos
    ifstream fv("./files/voos.csv");
    if (fv.is_open()) {
        string linha;
        while (getline(fv, linha)) {
            stringstream ss(linha);
            string origem, destino, matComandante, matOficial, horaSaida;
            double distancia, tempEstimado;
            int numPassageiros, codigo, escalas, codAeronave;
            vector<Passageiro> passageirosVoo;

            ss >> codigo;
            ss.ignore();
            getline(ss, origem, ',');
            getline(ss, destino, ',');
            ss >> distancia;
            ss.ignore();
            getline(ss, horaSaida, ',');
            ss >> escalas;
            ss.ignore();
            ss >> tempEstimado;
            ss.ignore();
            ss >> codAeronave;
            ss.ignore();
            getline(ss, matComandante, ',');
            getline(ss, matOficial, ',');
            ss >> numPassageiros;
            ss.ignore();

            // Ler passageiros do voo
            string passageirosStr;
            getline(ss, passageirosStr);
            if (numPassageiros > 0) {
                stringstream ssPass(passageirosStr);
                string cpf;
                while (getline(ssPass, cpf, '|')) {
                        passageirosVoo.push_back(passageiros[encontrarIndicePassageiroPorCpf(passageiros, cpf)]);
                }
            }

            // Criar o voo
            Voo v(codigo, origem, destino, distancia, horaSaida, escalas, tempEstimado);
            
            // Configurar aeronave e pilotos se existirem
            v.setAeronave(aeronaves[encontrarIndiceAeronavePorCodigo(aeronaves, codAeronave)]);
            v.setComandante(pilotos[encontrarIndicePilotoPorMatricula(pilotos, matComandante)]);            
            v.setPrimeiroOficial(pilotos[encontrarIndicePilotoPorMatricula(pilotos, matOficial)]);
           
            // Adicionar passageiros
            for (auto &p : passageirosVoo) {
                v.adicionarPassageiro(p);
            }

            voos.push_back(v);
        }
        fv.close();
    }
}
