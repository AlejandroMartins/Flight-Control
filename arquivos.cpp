#include "./include/arquivos.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


 //Função para salvar todos os dados do sistema em arquivos CSV

void salvarDados(vector<Aeronave> &aeronaves,
                const vector<Piloto> &pilotos,
                vector<Passageiro> &passageiros,
                const vector<Voo> &voos)
{
    // Seção 1: Salvar dados das aeronaves
    ofstream fa("./files/aeronaves.csv");
    if (fa.is_open())
    {
        for (auto &a : aeronaves)
        {
            // Escreve os dados básicos da aeronave
            fa << a.getCodigo() << ","
               << a.getCapacidade() << ","
               << a.getModelo() << ","
               << a.getVelocidadeMedia() << ","
               << a.getAutonomiaDeVoo() << ","
               << a.qtd_voo() << ":"; // Quantidade de voos associados

            // Escreve os códigos dos voos associados, separados por |
            for(int i = 0; i < a.qtd_voo(); i++)
            {
                fa << a.getCodVoo(i);
                if(i != a.qtd_voo() - 1)
                    fa << "|"; // Separador, exceto para o último
            }
            fa << endl;
        }
        fa.close();
    }

    // Seção 2: Salvar dados dos pilotos (formato mais simples)
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

    // Seção 3: Salvar dados dos passageiros
    ofstream fpa("./files/passageiros.csv");
    if (fpa.is_open())
    {
        for (auto &p : passageiros)
        {
            // Dados básicos do passageiro
            fpa << p.getNome() << ","
                << p.getCpf() << ","
                << p.getNumeroBilhete() << ","
                << p.qtd_voos() << ":"; // Quantidade de voos que participou

            // Lista de códigos de voos do passageiro
            for(int i = 0; i < p.qtd_voos(); i++)
            {
                fpa << p.getCodVoo(i);
                if(i != p.qtd_voos() - 1)
                    fpa << "|"; // Separador
            }
            fpa << endl;
        }
        fpa.close();
    }

    // Seção 4: Salvar dados dos voos (mais complexo)
    ofstream fv("./files/voos.csv");
    if (fv.is_open())
    {
        for (const auto &v : voos)
        {
            // Dados básicos do voo
            fv << v.getCodigo() << ","
               << v.getOrigem() << ","
               << v.getDestino() << ","
               << v.getDistancia() << ","
               << v.getHoraDeSaida() << ","
               << v.getNumeroDeEscalas() << ","
               << v.getTempoEstimado() << ","
               << v.getAeronave().getCodigo() << "," // Referência à aeronave
               << v.getComandante().getMatricula() << "," // Referência ao comandante
               << v.getPrimeiroOficial().getMatricula() << "," // Referência ao oficial
               << v.getPassageiros().size() << ","; // Quantidade de passageiros

            // Escreve os CPFs dos passageiros separados por |
            const auto &passageiros = v.getPassageiros();
            for (int i = 0; i < passageiros.size(); i++)
            {
                fv << passageiros[i].getCpf();
                if (i != passageiros.size() - 1)
                    fv << "|"; // Separador
            }
            fv << endl;
        }
        fv.close();
    }
}


 //Função para carregar todos os dados do sistema a partir de arquivos CSV
 
void carregarDados(vector<Aeronave> &aeronaves,
                 vector<Piloto> &pilotos,
                 vector<Passageiro> &passageiros,
                 vector<Voo> &voos) {
    // Limpa os vetores antes de carregar novos dados
    aeronaves.clear();
    pilotos.clear();
    passageiros.clear();
    voos.clear();

    // Seção 1: Carregar aeronaves
    ifstream fa("./files/aeronaves.csv");
    if (fa.is_open()) {
        string linha;
        while (getline(fa, linha)) {
            stringstream ss(linha);
            string codigo_str, capacidade_str, modelo, velocidade_str, autonomia_str, qtd_voos_str, voos_str;

            // Lê os dados básicos separados por vírgula
            getline(ss, codigo_str, ',');
            getline(ss, capacidade_str, ',');
            getline(ss, modelo, ',');
            getline(ss, velocidade_str, ',');
            getline(ss, autonomia_str, ',');
            getline(ss, qtd_voos_str, ':'); // Separador antes da lista de voos

            // Converte strings para os tipos apropriados
            int codigo = stoi(codigo_str);
            int capacidade = stoi(capacidade_str);
            double velocidade = stod(velocidade_str);
            double autonomia = stod(autonomia_str);
            int qtd_voos = stoi(qtd_voos_str);

            // Cria a aeronave com os dados básicos
            Aeronave a(codigo, capacidade, modelo, velocidade, autonomia);

            // Se houver voos associados, lê a lista separada por |
            if (qtd_voos > 0) {
                getline(ss, voos_str);
                stringstream voos_ss(voos_str);
                string codigo_voo_str;
                
                for (int i = 0; i < qtd_voos; i++) {
                    if (i > 0) getline(voos_ss, codigo_voo_str, '|'); // Ignora o separador
                    getline(voos_ss, codigo_voo_str, '|');
                    int codigo_voo = stoi(codigo_voo_str);
                    a.add_voo(codigo_voo); // Associa o voo à aeronave
                }
            }

            aeronaves.push_back(a);
        }
        fa.close();
    }

    // Seção 2: Carregar pilotos 
    ifstream fp("./files/pilotos.csv");
    if (fp.is_open()) {
        string linha;
        while (getline(fp, linha)) {
            stringstream ss(linha);
            string nome, matricula, breve;
            int horasDeVoo;

            // Lê os dados separados por vírgula
            getline(ss, nome, ',');
            getline(ss, matricula, ',');
            getline(ss, breve, ',');
            ss >> horasDeVoo;

            // Cria e adiciona o piloto
            Piloto p(nome, matricula, breve, horasDeVoo);
            pilotos.push_back(p);
        }
        fp.close();
    }

    // Seção 3: Carregar passageiros
    ifstream fpa("./files/passageiros.csv");
    if (fpa.is_open()) {
        string linha;
        while (getline(fpa, linha)) {
            stringstream ss(linha);
            string nome, cpf, numeroBilhete, voosStr, qtdVoosStr;

            // Lê dados básicos
            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, numeroBilhete, ',');
            getline(ss, qtdVoosStr, ':'); // Separador antes da lista de voos

            // Cria o passageiro
            Passageiro pa(nome, cpf, numeroBilhete);

            // Lê a lista de voos associados
            getline(ss, voosStr);
            int qtdVoos = stoi(qtdVoosStr);
            
            if (qtdVoos > 0) {
                stringstream voosStream(voosStr);
                string codigoVooStr;
                
                // Lê cada código de voo separado por |
                for (int i = 0; i < qtdVoos; i++) {
                    if (i > 0) {
                        getline(voosStream, codigoVooStr, '|'); // Ignora o separador  
                    }
                    getline(voosStream, codigoVooStr, '|');
                    int codigoVoo = stoi(codigoVooStr);
                    pa.add_voo(codigoVoo); // Associa o voo ao passageiro
                }
            }
            
            passageiros.push_back(pa);
        }
        fpa.close();
    }

    // Seção 4: Carregar voos (mais complexo devido às referências)
    ifstream fv("./files/voos.csv");
    if (fv.is_open()) {
        string linha;
        while (getline(fv, linha)) {
            stringstream ss(linha);
            string origem, destino, matComandante, matOficial, horaSaida;
            double distancia, tempEstimado;
            int numPassageiros, codigo, escalas, codAeronave;
            vector<Passageiro> passageirosVoo;

            // Lê os dados básicos do voo
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

            // Lê a lista de CPFs dos passageiros separados por |
            string passageirosStr;
            getline(ss, passageirosStr);
            if (numPassageiros > 0) {
                stringstream ssPass(passageirosStr);
                string cpf;
                while (getline(ssPass, cpf, '|')) {
                    // Encontra o passageiro pelo CPF e adiciona à lista
                    passageirosVoo.push_back(passageiros[encontrarIndicePassageiroPorCpf(passageiros, cpf)]);
                }
            }

            // Cria o voo com os dados básicos
            Voo v(codigo, origem, destino, distancia, horaSaida, escalas, tempEstimado);
            
            // Associa a aeronave (encontra pelo código)
            v.setAeronave(aeronaves[encontrarIndiceAeronavePorCodigo(aeronaves, codAeronave)]);
            // Associa o comandante (encontra pela matrícula)
            v.setComandante(pilotos[encontrarIndicePilotoPorMatricula(pilotos, matComandante)]);            
            // Associa o primeiro oficial (encontra pela matrícula)
            v.setPrimeiroOficial(pilotos[encontrarIndicePilotoPorMatricula(pilotos, matOficial)]);
           
            // Adiciona os passageiros ao voo
            for (auto &p : passageirosVoo) {
                v.adicionarPassageiro(p);
            }

            voos.push_back(v);
        }
        fv.close();
    }
}