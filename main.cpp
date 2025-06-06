#include <string>
#include "./include/Aeronave.h"
#include "./include/Piloto.h"
#include "./include/Passageiro.h"
#include "./include/Voo.h"
#include "./include/arquivos.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;
// comando para compilar: g++ -Iinclude main.cpp salvar.cpp src/*.cpp -o sistemaDeVoos

int exibirMenu()
{
    int opcao;
    cout << "\n\n====== SISTEMA DE CONTROLE DE VOOS ======\n\n";

    cout << "1. Cadastrar aeronave\n";
    cout << "2. Cadastrar piloto\n";
    cout << "3. Cadastrar passageiro\n";
    cout << "4. Criar voo\n";
    cout << "5. Embarcar passageiro em voo\n";
    cout << "6. Listar voos\n";
    cout << "7. Listar passageiros de um voo\n";
    cout << "8. Gerar relatórios e estatísticas\n";
    cout << "9. Salvar dados e sair\n";

    cout << "\n=========================================\n";
    cout << "Escolha uma opção: ";
    cin >> opcao;
    return opcao;
}

void limparBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int encontrarIndiceAeronavePorCodigo(const vector<Aeronave> &aeronaves, int codigo)
{
    for (int i = 0; i < (int)aeronaves.size(); i++)
    {
        if (aeronaves[i].getCodigo() == codigo)
        {
            return i;
        }
    }
    return -1; // Não encontrado
}

int encontrarIndicePilotoPorMatricula(const vector<Piloto> &pilotos, string matricula)
{
    for (int i = 0; i < pilotos.size(); i++)
    {
        if (pilotos[i].getMatricula() == matricula)
        {
            return i;
        }
    }
    return -1; // Não encontrado
}

int encontrarIndicePassageiroPorCpf(const vector<Passageiro> &passageiros, const string &cpf)
{
    for (int i = 0; i < (int)passageiros.size(); i++)
    {
        if (passageiros[i].getCpf() == cpf)
        {
            return i;
        }
    }
    return -1;
}

int encontrarIndiceVooPorCodigo(const vector<Voo> &voos, int codigo)
{
    for (int i = 0; i < (int)voos.size(); i++)
    {
        if (voos[i].getCodigo() == codigo)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<Aeronave> aeronaves;
    vector<Piloto> pilotos;
    vector<Passageiro> passageiros;
    vector<Voo> voos;

    // Criando um objeto de cada classe para iniciar o sistema com dados
    aeronaves.push_back(Aeronave(1, 180, "Boeing 737", 850.0, 5000.0));
    pilotos.push_back(Piloto("Carlos Silva", "MAT123", "Breve123", 1500.0));
    passageiros.push_back(Passageiro("Ana Souza", "123.456.789-00", "BIL123"));

    // Criar um voo usando os objetos acima
    Voo vooInicial(1001, "São Paulo", "Rio de Janeiro", 430.0, "08:00",
                   0, 1.0,
                   aeronaves[0], pilotos[0], pilotos[0]); // só para exemplo, mesmo piloto como comandante e 1º oficial

    voos.push_back(vooInicial);

    do
    {
        int opcao = exibirMenu();
        limparBuffer();

        if (opcao == 1)
        {
            int codigo, capacidade;
            string modelo;
            double velocidadeMedia, autonomiaDeVoo;

            cout << "Digite o código da aeronave: ";
            cin >> codigo;
            limparBuffer();

            cout << "Digite a capacidade da aeronave: ";
            cin >> capacidade;
            limparBuffer();

            cout << "Digite o modelo da aeronave: ";
            getline(cin, modelo);

            cout << "Digite a velocidade média da aeronave: ";
            cin >> velocidadeMedia;
            limparBuffer();

            cout << "Digite a autonomia de voo da aeronave: ";
            cin >> autonomiaDeVoo;
            limparBuffer();

            aeronaves.push_back(Aeronave(codigo, capacidade, modelo, velocidadeMedia, autonomiaDeVoo));

            cout << "Aeronave cadastrada com sucesso!" << endl;
        }
        else if (opcao == 2)
        {
            string nome, matricula, breve;
            double horasDeVoo;

            cout << "Digite o nome do piloto: ";
            getline(cin, nome);

            cout << "Digite a matrícula do piloto: ";
            getline(cin, matricula);

            cout << "Digite o breve do piloto: ";
            getline(cin, breve);

            cout << "Digite as horas de voo do piloto: ";
            cin >> horasDeVoo;
            limparBuffer();

            pilotos.push_back(Piloto(nome, matricula, breve, horasDeVoo));

            cout << "Piloto cadastrado com sucesso!" << endl;
        }
        else if (opcao == 3)
        {
            string nome, cpf, numeroBilhete;

            cout << "Digite o nome do passageiro: ";
            getline(cin, nome);

            cout << "Digite o CPF do passageiro: ";
            getline(cin, cpf);

            cout << "Digite o número do bilhete do passageiro: ";
            getline(cin, numeroBilhete);

            passageiros.push_back(Passageiro(nome, cpf, numeroBilhete));

            cout << "Passageiro cadastrado com sucesso!" << endl;
        }
        else if (opcao == 4)
        {
            int codigoVoo, codigoAeronave;
            string origem, destino, horaDeSaida;
            float distancia;

            cout << "Digite o código do voo: ";
            cin >> codigoVoo;
            limparBuffer();

            cout << "Digite a origem do voo: ";
            getline(cin, origem);

            cout << "Digite o destino do voo: ";
            getline(cin, destino);

            cout << "Digite a distância da viagem: ";
            cin >> distancia;
            limparBuffer();

            cout << "Digite a hora de saída da viagem: ";
            getline(cin, horaDeSaida);

            cout << "Digite o código da aeronave: ";
            cin >> codigoAeronave;
            limparBuffer();

            int iAeronave = encontrarIndiceAeronavePorCodigo(aeronaves, codigoAeronave);
            if (iAeronave == -1)
            {
                cout << "Essa aeronave não existe" << endl;
                continue;
            }

            // Aqui assumimos que você cadastrou pilotos antes e quer pedir matrícula como string
            string matriculaComandante, matriculaPrimeiroOficial;

            cout << "Digite a matrícula do Comandante: ";
            getline(cin, matriculaComandante);

            int iComandante = encontrarIndicePilotoPorMatricula(pilotos, matriculaComandante);

            cout << "Digite a matrícula do Primeiro Oficial: ";
            getline(cin, matriculaPrimeiroOficial);

            int iPrimeiroOficial = encontrarIndicePilotoPorMatricula(pilotos, matriculaPrimeiroOficial);

            Aeronave &aeronaveSelecionada = aeronaves[iAeronave];
            Piloto &comandanteSelecionado = pilotos[iComandante];
            Piloto &primeiroOficialSelecionado = pilotos[iPrimeiroOficial];

            Voo novoVoo(codigoVoo, origem, destino, distancia, horaDeSaida, 0, 0,
                        aeronaveSelecionada, comandanteSelecionado, primeiroOficialSelecionado);
            voos.push_back(novoVoo);

            cout << "Voo criado com sucesso!" << endl;
        }
        else if (opcao == 5)
        {
            int codigoVoo;
            string cpf;

            cout << "Digite o código do voo: ";
            cin >> codigoVoo;
            limparBuffer();

            int iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            if (iVoo == -1)
            {
                cout << "Esse voo não existe" << endl;
                continue;
            }

            cout << "Digite o CPF do passageiro: ";
            getline(cin, cpf);

            int iPassageiro = encontrarIndicePassageiroPorCpf(passageiros, cpf);
            if (iPassageiro == -1)
            {
                cout << "Esse passageiro não existe" << endl;
                continue;
            }

            voos[iVoo].adicionarPassageiro(passageiros[iPassageiro]);
            cout << "Passageiro adicionado com sucesso!" << endl;
        }
        else if (opcao == 6)
        {
            for (int i = 0; i < voos.size(); i++)
            {
                cout << voos[i].getCodigo() << ","
                     << voos[i].getOrigem() << ","
                     << voos[i].getDestino() << ","
                     << voos[i].getDistancia() << ","
                     << voos[i].getHoraDeSaida() << ","
                     << voos[i].getPassageiros().size() << ","
                     << voos[i].getAeronave().getCodigo() << ","
                     << voos[i].getComandante().getMatricula() << ","
                     << voos[i].getPrimeiroOficial().getMatricula()
                     << "\n";
            }
        }
        else if (opcao == 7)
        {
            int codigoVoo;
            cout << "Digite o código do voo: ";
            cin >> codigoVoo;

            int iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            if (iVoo == -1)
            {
                cout << "Esse voo não existe" << endl;
                continue;
            }
            voos[iVoo].listarPassageiros();
        }
        else if (opcao == 8)
        {
            // Gerar relatórios e estatísticas
            cout << "Função de relatórios ainda não implementada." << endl;
        }
        else if (opcao == 9)
        {
            cout << "Salvando dados e saindo..." << endl;
            salvarDados(aeronaves, pilotos, passageiros, voos);
            break;
        }
        else
        {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (true);

    return 0;
}
