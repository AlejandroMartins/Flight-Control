#include <string>
#include "./models/Aeronave.h"
#include "./models/Piloto.h"
#include "./models/Passageiro.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int exibirMenu()
{
    int opcao;
    printf("\n\n====== SISTEMA DE CONTROLE DE VOOS ======\n\n");

    printf("1. Cadastrar aeronave\n");
    printf("2. Cadastrar piloto\n");
    printf("3. Cadastrar passageiro\n");
    printf("4. Criar voo\n");
    printf("5. Embarcar passageiro em voo\n");
    printf("6. Listar voos\n");
    printf("7. Listar passageiros de um voo\n");
    printf("8. Gerar relatórios e estatísticas\n");
    printf("9. Salvar dados e sair\n");

    printf("\n=========================================\n");
    printf("Escolha uma opção: ");
    cin >> opcao;
    return opcao;
}

void limparBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
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

            cout << "Digite a capacidade da aeronave: ";
            cin >> capacidade;

            cout << "Digite o modelo da aeronave: ";
            getline(cin, modelo);
            limparBuffer();

            cout << "Digite a velocidade média da aeronave: ";
            cin >> velocidadeMedia;

            cout << "Digite a autonomia de voo da aeronave: ";
            cin >> autonomiaDeVoo;

            Aeronave a(codigo, capacidade, modelo, velocidadeMedia, autonomiaDeVoo);

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

            cout << "Digite o breve do piloto: ";
            getline(cin, breve);

            cout << "Digite as horas de voo do piloto: ";
            cin >> horasDeVoo;

            Piloto p(nome, matricula, breve, horasDeVoo);

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

            Passageiro p(nome, cpf, numeroBilhete);

            cout << "Passageiro cadastrado com sucesso!" << endl;
        }
        else if (opcao == 4)
        {
            // Criar Voo
        }
        else if (opcao == 5)
        {
            // Embarcar Passageiro em Voo
        }
        else if (opcao == 6)
        {
            // Listar Voos
        }
        else if (opcao == 7)
        {
            // Listar Passageiros de um Voo
        }
        else if (opcao == 8)
        {
            // Gerar Relatorios e Estatisticas
        }
        else if (opcao == 9)
        {
            break;
        }
    } while (true);

    return 0;
}
