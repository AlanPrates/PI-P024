/*
Etapa 1: Individual 
1. Defina, de acordo com o que vimos nas aulas de Herança, Composição 
e Agregação,  qual estratégia é mais adequada para a implementação 
de cada uma das classes acima. Explique o porquê de suas escolhas. 
2. Esboce a implementação das classes de acordo com a estratégia que 
você julgou adequada.

*/

/*
Este projeto visa criar um sistema de gerenciamento de pacotes turísticos para clientes, 
onde um cliente pode ter vários pacotes associados a ele. 
Cada pacote contém componentes essenciais, como eventos, roteiros, deslocamentos e pernoites. 
Além disso, é possível cadastrar dependentes para um cliente.

- Cliente: Representa um cliente que pode ter vários pacotes turísticos associados a ele. 
A relação entre Cliente e Pacote é uma Agregação.
- Pacote: Representa um pacote turístico que pode conter eventos, roteiros, deslocamentos e pernoites. 
A relação entre Pacote e esses componentes é uma Composição.
- Dependente: Representa um dependente diretamente relacionado a um cliente. A relação entre Cliente e Dependente é uma Agregação.
- Evento, Roteiro, Deslocamento, Pernoite: São classes que representam os componentes essenciais de um pacote turístico. 
A relação entre Pacote e essas classes é uma Composição.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente
{
private:
    string nome;
    vector<Pacote *> pacotes; 
public:
   
};

class Pacote
{
private:
    vector<Evento> eventos;             
    vector<Roteiro> roteiros;           
    vector<Deslocamento> deslocamentos; 
    vector<Pernoite> pernoites;         
public:
    
};

class Dependente
{
private:
    string nome;
    Cliente *cliente; 
public:
    
};

class Evento
{
private:
    string nome;
    
public:
    
};

class Roteiro
{
private:
    string descricao;
   
public:
    
};

class Deslocamento
{
private:
    string origem;
    string destino;
    
public:
    
};

class Pernoite
{
private:
    string local;
    
public:
    
};