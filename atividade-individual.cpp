#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Implementação da Estratégia
// Descrição do Projeto
// Este projeto visa criar um sistema de gerenciamento de pacotes turísticos para clientes, onde um cliente pode ter vários pacotes associados a ele. Além disso, cada pacote pode conter componentes essenciais, como eventos, roteiros, deslocamentos e pernoites. Também é possível cadastrar dependentes para um cliente.

// Classes e Relacionamentos
// Cliente
// Um cliente pode ter vários pacotes turísticos associados a ele, mas não faz sentido que um cliente seja composto por um pacote. Portanto, a relação entre Cliente e Pacote é uma Agregação.

class Cliente
{
private:
    string nome;
    vector<Pacote *> pacotes; // Agregação com Pacote
public:
    // Métodos e construtores
};
// Pacote
// Um pacote turístico pode conter vários componentes como eventos, roteiros, deslocamentos e pernoites. Esses componentes são essenciais para o pacote, então a relação entre Pacote e esses componentes é uma Composição.

class Pacote
{
private:
    vector<Evento> eventos;             // Composição com Evento
    vector<Roteiro> roteiros;           // Composição com Roteiro
    vector<Deslocamento> deslocamentos; // Composição com Deslocamento
    vector<Pernoite> pernoites;         // Composição com Pernoite
public:
    // Métodos e construtores
};
// Dependente
// Um dependente está diretamente relacionado a um cliente. A relação entre Cliente e Dependente é uma Agregação, pois um cliente pode ter vários dependentes, mas um dependente não existe independentemente de um cliente.

class Dependente
{
private:
    string nome;
    Cliente *cliente; // Agregação com Cliente
public:
    // Métodos e construtores
};
// Evento, Roteiro, Deslocamento, Pernoite
// Essas classes representam os componentes essenciais de um pacote turístico. Não faz sentido que um desses componentes exista independentemente de um pacote. Portanto, a relação entre Pacote e essas classes é uma Composição.

class Evento
{
private:
    string nome;
    // Outros atributos relevantes
public:
    // Métodos e construtores
};

class Roteiro
{
private:
    string descricao;
    // Outros atributos relevantes
public:
    // Métodos e construtores
};

class Deslocamento
{
private:
    string origem;
    string destino;
    // Outros atributos relevantes
public:
    // Métodos e construtores
};

class Pernoite
{
private:
    string local;
    // Outros atributos relevantes
public:
    // Métodos e construtores
};
