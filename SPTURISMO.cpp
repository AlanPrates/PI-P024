


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Evento {
private:
    string nome;
    string data;

public:
    Evento(string nome, string data) : nome(nome), data(data) {}
    string getNome() const { return nome; }
    string getData() const { return data; }
};

class Pacote {
private:
    string nome;
    vector<Evento> eventos;

public:
    Pacote(string nome) : nome(nome) {}
    void adicionarEvento(Evento evento) { eventos.push_back(evento); }
    string getNome() const { return nome; }
    const vector<Evento>& getEventos() const { return eventos; }
};

class Dependente {
private:
    string nome;

public:
    Dependente(string nome) : nome(nome) {}
    string getNome() const { return nome; }
};

class Cliente {
private:
    string nome;
    vector<Dependente> dependentes;
    Pacote pacoteContratado;

public:
    Cliente(string nome) : nome(nome), pacoteContratado("") {}
    void adicionarDependente(Dependente dependente) { dependentes.push_back(dependente); }
    void contratarPacote(Pacote pacote) { pacoteContratado = pacote; }
    string getNome() const { return nome; }
    const vector<Dependente>& getDependentes() const { return dependentes; }
    const Pacote& getPacoteContratado() const { return pacoteContratado; }
};

void cadastrarEvento(vector<Evento>& eventos) {
    string nome, data;
    cout << "Nome do Evento: ";
    cin >> nome;
    cout << "Data do Evento (AAAA-MM-DD): ";
    cin >> data;
    eventos.push_back(Evento(nome, data));
}

void cadastrarPacote(vector<Pacote>& pacotes, const vector<Evento>& eventos) {
    string nomePacote;
    cout << "Nome do Pacote: ";
    cin >> nomePacote;

    Pacote pacote(nomePacote);

    int escolha;
    do {
        cout << "Escolha um evento para adicionar ao pacote:" << endl;
        for (size_t i = 0; i < eventos.size(); ++i) {
            cout << i+1 << ". " << eventos[i].getNome() << " (Data: " << eventos[i].getData() << ")" << endl;
        }
        cout << "0. Concluir cadastro do pacote" << endl;
        cin >> escolha;

        if (escolha > 0 && escolha <= static_cast<int>(eventos.size())) {
            pacote.adicionarEvento(eventos[escolha-1]);
        }
    } while (escolha != 0);

    pacotes.push_back(pacote);
}

void cadastrarCliente(vector<Cliente>& clientes, const vector<Pacote>& pacotes) {
    string nomeCliente;
    cout << "Nome do Cliente: ";
    cin >> nomeCliente;

    Cliente cliente(nomeCliente);

    int escolha;
    do {
        cout << "Escolha um pacote para o cliente (ou 0 para sair):" << endl;
        for (size_t i = 0; i < pacotes.size(); ++i) {
        cout << i+1 << ". " << pacotes[i].getNome() << endl;
        }
        cin >> escolha;

        if (escolha > 0 && escolha <= static_cast<int>(pacotes.size())) {
            cliente.contratarPacote(pacotes[escolha-1]);
        }
    } while (escolha != 0);

    clientes.push_back(cliente);
}

void exibirInformacoes(const vector<Evento>& eventos, const vector<Pacote>& pacotes, const vector<Cliente>& clientes) {
    cout << "\n--- Eventos ---" << std::endl;
    for (const Evento& evento : eventos) {
        cout << "Nome: " << evento.getNome() << ", Data: " << evento.getData() << endl;
    }

    cout << "\n--- Pacotes ---" << endl;
    for (const Pacote& pacote : pacotes) {
        cout << "Nome: " << pacote.getNome() << endl;
        const vector<Evento>& eventosDoPacote = pacote.getEventos();
        for (const Evento& evento : eventosDoPacote) {
            cout << "- " << evento.getNome() << " (Data: " << evento.getData() << ")" << endl;
        }
    }

    cout << "\n--- Clientes ---" << endl;
    for (const Cliente& cliente : clientes) {
        cout << "Nome do Cliente: " << cliente.getNome() << endl;
        const Pacote& pacoteContratado = cliente.getPacoteContratado();
        if (pacoteContratado.getNome() != "") {
            cout << "Pacote Contratado: " << pacoteContratado.getNome() << endl;
            const vector<Evento>& eventosDoPacote = pacoteContratado.getEventos();
            for (const Evento& evento : eventosDoPacote) {
                cout << "- " << evento.getNome() << " (Data: " << evento.getData() << ")" << endl;
            }
        }
        else {
            cout << "Cliente ainda não contratou nenhum pacote." << endl;
        }

        const vector<Dependente>& dependentes = cliente.getDependentes();
        if (!dependentes.empty()) {
            cout << "Dependentes:" << endl;
            for (const Dependente& dependente : dependentes) {
                cout << "- " << dependente.getNome() << endl;
            }
        }
        else {
            cout << "Cliente não possui dependentes." << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<Evento> eventos;
    vector<Pacote> pacotes;
    vector<Cliente> clientes;

    int escolha;

    do {
        cout << "\nMenu Principal:" <<endl;
        cout << "1. Cadastrar Evento" << endl;
        cout << "2. Cadastrar Pacote" << endl;
        cout << "3. Cadastrar Cliente" << endl;
        cout << "4. Exibir Informações" << endl;
        cout << "5. Sair" << endl;
        cin >> escolha;

        switch (escolha) {
            case 1:
                cadastrarEvento(eventos);
                break;
            case 2:
                cadastrarPacote(pacotes, eventos);
                break;
            case 3:
                cadastrarCliente(clientes, pacotes);
                break;
            case 4:
                exibirInformacoes(eventos, pacotes, clientes);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (escolha != 5);

    return 0;
}