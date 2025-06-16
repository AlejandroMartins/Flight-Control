#include <string>
#include "./include/Aeronave.h" 
#include "./include/Piloto.h"
#include "./include/Passageiro.h"
#include "./include/Voo.h"
#include "./include/arquivos.h"
#include "./include/pesquisa.h"
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
    cout << "8. Gerar relatorios e estatisticas\n";
    cout << "9. Salvar dados e sair\n";

    cout << "\n=========================================\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

void limparBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main()
{
    vector<Aeronave> aeronaves;
    vector<Piloto> pilotos;
    vector<Passageiro> passageiros;
    vector<Voo> voos;

    carregarDados(aeronaves, pilotos, passageiros, voos);

    
    do
    {
        int opcao = exibirMenu();
        limparBuffer();

        if (opcao == 1)
        {
            int codigo, capacidade;
            string modelo;
            double velocidadeMedia, autonomiaDeVoo;

            cout << "Digite o codigo da aeronave: ";
            cin >> codigo;
            limparBuffer();

            // verificando se ja nao existe nenhuma aeronave com esse codigo
            while(encontrarIndiceAeronavePorCodigo(aeronaves, codigo) != -1)
            {
                cout << "Codigo de aeronave ja existente, digite outro: ";
                cin >> codigo;
                limparBuffer();
            }

            cout << "Digite a capacidade da aeronave: ";
            cin >> capacidade;
            limparBuffer();

            cout << "Digite o modelo da aeronave: ";
            getline(cin, modelo);

            cout << "Digite a velocidade media da aeronave: ";
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

            cout << "Digite a matricula do piloto: ";
            getline(cin, matricula);

            while (encontrarIndicePilotoPorMatricula(pilotos, matricula) != -1)
            {
                cout << "Matricula ja existente, digite outra: ";
                getline(cin, matricula);
            }
            

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

            while (encontrarIndicePassageiroPorCpf(passageiros, cpf) != -1)
            {
                cout << "Cpf ja existente, digite outro: ";
                getline(cin, cpf);
            }
            

            cout << "Digite o numero do bilhete do passageiro: ";
            getline(cin, numeroBilhete);

            passageiros.push_back(Passageiro(nome, cpf, numeroBilhete));

            cout << "Passageiro cadastrado com sucesso!" << endl;
        }
        else if (opcao == 4)
        {
            int codigoVoo, codigoAeronave;
            string origem, destino, horaDeSaida;
            float distancia;

            cout << "Digite o codigo do voo: ";
            cin >> codigoVoo;
            limparBuffer();

            while (encontrarIndiceVooPorCodigo(voos, codigoVoo) != -1)
            {
                cout << "Codigo ja existente, digite outro: ";
                cin >> codigoVoo;
                limparBuffer();
            }
            

            cout << "Digite a origem do voo: ";
            getline(cin, origem);

            cout << "Digite o destino do voo: ";
            getline(cin, destino);

            cout << "Digite a distancia da viagem: ";
            cin >> distancia;
            limparBuffer();

            cout << "Digite a hora de saida da viagem: ";
            getline(cin, horaDeSaida);

            cout << "Digite o codigo da aeronave: ";
            cin >> codigoAeronave;
            limparBuffer();

            // Verificando que sera passado um codigo de aeronave valido
            int iAeronave = encontrarIndiceAeronavePorCodigo(aeronaves, codigoAeronave);
            while (iAeronave == -1)
            {
                cout << "Essa aeronave nao existe, digite outro codigo:" << endl;
                cin >> codigoAeronave;
                limparBuffer();
                iAeronave = encontrarIndiceAeronavePorCodigo(aeronaves, codigoAeronave);
            }

            // Aqui assumimos que você cadastrou pilotos antes e quer pedir matricula como string
            string matriculaComandante, matriculaPrimeiroOficial;

            cout << "Digite a matricula do Comandante: ";
            getline(cin, matriculaComandante);

            // Verificando que será passado uma matricula valida
            int iComandante = encontrarIndicePilotoPorMatricula(pilotos, matriculaComandante);
            while (iComandante == -1)
            {
                cout << "Essa matricula nao existe, digite outra:" << endl;
                getline(cin, matriculaComandante);
                iComandante = encontrarIndicePilotoPorMatricula(pilotos, matriculaComandante);
            }
            
            
            cout << "Digite a matricula do Primeiro Oficial: ";
            getline(cin, matriculaPrimeiroOficial);

            // Verificando que será passada uma matricula valida
            int iPrimeiroOficial = encontrarIndicePilotoPorMatricula(pilotos, matriculaPrimeiroOficial);
            while (iPrimeiroOficial == - 1)
            {
                cout << "Essa matricula nao existe, digite outra:" << endl;
                getline(cin, matriculaPrimeiroOficial);
                iPrimeiroOficial = encontrarIndicePilotoPorMatricula(pilotos, matriculaPrimeiroOficial);
            }
            

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

            cout << "Digite o codigo do voo: ";
            cin >> codigoVoo;
            limparBuffer();

            // Garantindo que será passado um codigo válido
            int iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            while (iVoo == -1)
            {
                cout << "Esse voo nao existe, digite novamente:" << endl;
                cin >> codigoVoo;
                limparBuffer();
                iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            }

            cout << "Digite o CPF do passageiro: ";
            getline(cin, cpf);

            // Garantindo que será passado um passageiro válido
            int iPassageiro = encontrarIndicePassageiroPorCpf(passageiros, cpf);
            while (iPassageiro == -1)
            {
                cout << "Esse passageiro nao existe, digite novamente:" << endl;
                getline(cin, cpf);
                iPassageiro = encontrarIndicePassageiroPorCpf(passageiros, cpf);
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
            cout << "Digite o codigo do voo: ";
            cin >> codigoVoo;

            // Garantindo que será passado um codigo válido
            int iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            while (iVoo == -1)
            {
                cout << "Esse voo nao existe, digite novamente:" << endl;
                cin >> codigoVoo;
                iVoo = encontrarIndiceVooPorCodigo(voos, codigoVoo);
            }
            voos[iVoo].listarPassageiros();
        }
        else if (opcao == 8)
        {
            // Gerar relatórios e estatísticas
            cout << "Função de relatórios ainda nao implementada." << endl;
        }
        else if (opcao == 9)
        {
            cout << "Salvando dados e saindo..." << endl;
            salvarDados(aeronaves, pilotos, passageiros, voos);
            break;
        }
        else
        {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (true);

    return 0;
}
