# Sistema de Controle de Pacotes Turísticos em C++

## Equipe
- Alan Prates
- Daniel Monteiro
- Danilo Silveira
- Paulo Pereira

## Descrição
Este é um projeto de um sistema de controle de pacotes turísticos implementado em C++. O sistema envolve várias entidades, incluindo Cliente, Pacote, Dependente, Evento, Roteiro, Deslocamento e Pernoite.

## Funcionalidades
1. Definir a estratégia de implementação para cada classe, considerando conceitos como Herança, Composição e Agregação.
2. Esboçar a implementação das classes de acordo com a estratégia escolhida.
3. Implementar o sistema corretamente em equipe.
4. Criar um programa que permita o cadastramento de eventos.
5. Adicionar a funcionalidade de criar pacotes, adicionando eventos pré-definidos a eles.
6. Adicionar a funcionalidade de criar clientes com seus respectivos dependentes.
7. Adicionar a funcionalidade de vender pacotes a clientes.
8. Permitir a consulta da lista de clientes (com dependentes).
9. Permitir a consulta da lista de pacotes (com eventos).
10. Permitir a consulta dos pacotes contratados por um cliente específico.
11. Permitir a consulta dos clientes que contrataram um pacote específico.

## Como Compilar e Executar
Para compilar o projeto, utilize um compilador C++ compatível com C++11 ou superior.

```bash
g++ -std=c++11 main.cpp Cliente.cpp Pacote.cpp Dependente.cpp Evento.cpp Roteiro.cpp Deslocamento.cpp Pernoite.cpp -o sistema_turistico
```

Para executar o programa, use o seguinte comando:

```bash
./sistema_turistico
```