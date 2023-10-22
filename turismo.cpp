#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Evento {
public:
    string nome;
    double preco;

    Evento(const string& nome, double preco) : nome(nome), preco(preco) {}
};

class Pacote {
public:
    string nome;
    vector<Evento> eventos;

    Pacote(const string& nome) : nome(nome) {}

    void adicionarEvento(const Evento& evento) {
        eventos.push_back(evento);
    }
};

class Dependente {
public:
    string nome;

    Dependente(const string& nome) : nome(nome) {}
};

class Cliente {
public:
    string nome;
    vector<Dependente> dependentes;
    vector<Pacote> pacotesContratados;

    Cliente(const string& nome) : nome(nome) {}

    void adicionarDependente(const Dependente& dependente) {
        dependentes.push_back(dependente);
    }

    void comprarPacote(const Pacote& pacote) {
        pacotesContratados.push_back(pacote);
    }
};

int main() {
    vector<Evento> eventos;
    vector<Pacote> pacotes;
    vector<Cliente> clientes;

    // Função para adicionar um evento à lista de eventos
    auto cadastrarEvento = [&eventos]() {
        string nome;
        double preco;
        cout << "Nome do evento: ";
        cin >> nome;
        cout << "Preço do evento: ";
        cin >> preco;
        eventos.push_back(Evento(nome, preco));
        cout << "Evento cadastrado com sucesso!" << endl;
    };

    // Função para criar um pacote com eventos
    auto criarPacote = [&eventos, &pacotes]() {
        string nomePacote;
        cout << "Nome do pacote: ";
        cin >> nomePacote;
        Pacote pacote(nomePacote);
        cout << "Eventos disponíveis: " << endl;
        for (int i = 0; i < eventos.size(); i++) {
            cout << i + 1 << ". " << eventos[i].nome << " - R$ " << eventos[i].preco << endl;
        }
        int escolha;
        do {
            cout << "Escolha um evento para adicionar ao pacote (0 para encerrar): ";
            cin >> escolha;
            if (escolha > 0 && escolha <= eventos.size()) {
                pacote.adicionarEvento(eventos[escolha - 1]);
            }
        } while (escolha != 0);
        pacotes.push_back(pacote);
        cout << "Pacote criado com sucesso!" << endl;
    };

    // Função para criar um cliente com dependentes
    auto criarCliente = [&clientes]() {
        string nomeCliente;
        cout << "Nome do cliente: ";
        cin >> nomeCliente;
        Cliente cliente(nomeCliente);
        cout << "Digite os nomes dos dependentes (digite '0' para encerrar):" << endl;
        while (true) {
            string nomeDependente;
            cin >> nomeDependente;
            if (nomeDependente == "0") {
                break;
            }
            cliente.adicionarDependente(Dependente(nomeDependente));
        }
        clientes.push_back(cliente);
        cout << "Cliente cadastrado com sucesso!" << endl;
    };

    // Função para vender um pacote a um cliente
    auto venderPacote = [&clientes, &pacotes]() {
        cout << "Clientes disponíveis:" << endl;
        for (int i = 0; i < clientes.size(); i++) {
            cout << i + 1 << ". " << clientes[i].nome << endl;
        }
        int escolhaCliente;
        cout << "Escolha um cliente: ";
        cin >> escolhaCliente;
        if (escolhaCliente <= 0 || escolhaCliente > clientes.size()) {
            cout << "Cliente inválido." << endl;
            return;
        }
        cout << "Pacotes disponíveis:" << endl;
        for (int i = 0; i < pacotes.size(); i++) {
            cout << i + 1 << ". " << pacotes[i].nome << endl;
        }
        int escolhaPacote;
        cout << "Escolha um pacote: ";
        cin >> escolhaPacote;
        if (escolhaPacote <= 0 || escolhaPacote > pacotes.size()) {
            cout << "Pacote inválido." << endl;
            return;
        }
        clientes[escolhaCliente - 1].comprarPacote(pacotes[escolhaPacote - 1]);
        cout << "Pacote vendido com sucesso!" << endl;
    };

    // Função para consultar a lista de clientes
    auto consultarClientes = [&clientes]() {
        cout << "Lista de clientes:" << endl;
        for (const auto& cliente : clientes) {
            cout << "Nome: " << cliente.nome << endl;
            cout << "Dependentes: ";
            for (const auto& dependente : cliente.dependentes) {
                cout << dependente.nome << ", ";
            }
            cout << endl;
            cout << "Pacotes contratados: ";
            for (const auto& pacote : cliente.pacotesContratados) {
                cout << pacote.nome << ", ";
            }
            cout << endl;
            cout << "-------------------" << endl;
        }
    };

    // Função para consultar a lista de pacotes
    auto consultarPacotes = [&pacotes]() {
        cout << "Lista de pacotes:" << endl;
        for (const auto& pacote : pacotes) {
            cout << "Nome do pacote: " << pacote.nome << endl;
            cout << "Eventos no pacote: ";
            for (const auto& evento : pacote.eventos) {
                cout << evento.nome << ", ";
            }
            cout << endl;
            cout << "-------------------" << endl;
        }
    };

    while (true) {
        cout << "Escolha uma opção: " << endl;
        cout << "1. Cadastrar evento" << endl;
        cout << "2. Criar pacote" << endl;
        cout << "3. Criar cliente" << endl;
        cout << "4. Vender pacote" << endl;
        cout << "5. Consultar lista de clientes" << endl;
        cout << "6. Consultar lista de pacotes" << endl;
        cout << "0. Sair" << endl;

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarEvento();
                break;
            case 2:
                criarPacote();
                break;
            case 3:
                criarCliente();
                break;
            case 4:
                venderPacote();
                break;
            case 5:
                consultarClientes();
                break;
            case 6:
                consultarPacotes();
                break;
            case 0:
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
