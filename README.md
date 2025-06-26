# Sistema de Controle de Voo em Aeroporto

## Descrição do Projeto
Este projeto consiste no desenvolvimento de um sistema em C++ que simula o controle básico de voos em um aeroporto. O sistema é projetado para gerenciar informações detalhadas sobre voos, aeronaves, passageiros e pilotos, permitindo o registro de embarques e garantindo a persistência dos dados. Desenvolvido com uma interface por linha de comando, o trabalho visa aplicar conceitos de Programação Orientada a Objetos (POO), incluindo classes, objetos, encapsulamento, associação, herança, manipulação de arquivos e a utilização da Standard Template Library (STL).

## Funcionalidades
O sistema oferece as seguintes funcionalidades principais através de um menu interativo:

1.  *Cadastro de Aeronaves*: Registro de aeronaves com código, modelo, capacidade, velocidade média e autonomia de voo.
2.  *Cadastro de Pessoas*: Permite cadastrar Pilotos (nome, matrícula, brevê, horas de voo) e Passageiros (nome, CPF, número do bilhete).
3.  *Criação de Voos*: Define voos com código, origem, destino, distância, aeronave associada, hora de saída, número de escalas estimado e tempo estimado de voo. Um voo é associado a um Comandante e um Primeiro Oficial (ambos pilotos).
4.  *Associação de Passageiros a Voos*: Permite embarcar passageiros em voos, respeitando a capacidade máxima da aeronave.
5.  *Listagem de Voos*: Exibe detalhes de cada voo, incluindo código, aeronave (código e modelo), matrícula do comandante, origem, destino, número de passageiros, e horários previstos de saída e chegada.
6.  *Listagem de Passageiros em Voo*: Ao informar o código de um voo, exibe o código e modelo da aeronave, e o nome de cada passageiro no voo.
7.  *Geração de Relatórios e Estatísticas*: Funcionalidade extra que permite gerar relatórios como número total de voos, média de passageiros por voo, aeronaves mais utilizadas, passageiros que participaram de múltiplos voos, voos com alta ocupação (>= 90% da capacidade) e distância total percorrida por cada aeronave.
8.  *Salvar Dados e Sair*: Permite salvar todos os dados cadastrados (aeronaves, pilotos, passageiros e voos) em arquivos CSV e encerrar o programa.

## Estrutura do Projeto
O projeto está modularizado em arquivos de cabeçalho (.h) e arquivos de implementação (.cpp) para organização e clareza.

* main.cpp: Ponto de entrada do programa, gerencia o menu principal e o fluxo de execução.
* Aeronave.h / Aeronave.cpp: Define e implementa a classe Aeronave.
* Piloto.h / Piloto.cpp: Define e implementa a classe Piloto (herda de Pessoa).
* Passageiro.h / Passageiro.cpp: Define e implementa a classe Passageiro (herda de Pessoa).
* Pessoa.h / Pessoa.cpp: Define e implementa a classe base Pessoa.
* Voo.h / Voo.cpp: Define e implementa a classe Voo, incluindo associações com outras entidades.
* arquivos.h / arquivos.cpp: Contém funções para salvar e carregar dados em/de arquivos CSV.
* pesquisa.h / pesquisa.cpp: Funções auxiliares para encontrar objetos em coleções.
* extra.h / extra.cpp: Funções para a geração de relatórios e estatísticas.

## Como Compilar e Executar

Este projeto pode ser compilado utilizando um compilador C++ (como g++).

### Pré-requisitos
* Um compilador C++ (g++, Clang, MSVC)
* Make (opcional, para usar o Makefile)

### Compilação
1.  *Navegue até o diretório do projeto* no seu terminal ou linha de comando.
2.  *Compile usando g++:*
    
    g++ -Iinclude main.cpp arquivos.cpp src/*.cpp -o exe
    
### Execução
Após a compilação bem-sucedida, execute o programa:


./exe