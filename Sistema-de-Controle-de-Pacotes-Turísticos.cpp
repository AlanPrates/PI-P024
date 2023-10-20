#include <iostream>
#include <vector>
#include <string>

class Evento {
private:
    std::string nome;
    std::string data;

public:
    Evento(std::string nome, std::string data) : nome(nome), data(data) {}
    std::string getNome() const { return nome; }
    std::string getData() const { return data; }
};

class Pacote {
private:
    std::string nome;
    std::vector<Evento> eventos;

public:
    Pacote(std::string nome) : nome(nome) {}
    void adicionarEvento(Evento evento) { eventos.push_back(evento); }
    std::string getNome() const { return nome; }
    const std::vector<Evento>& getEventos() const { return eventos; }
};

class Dependente {
private:
    std::string nome;

public:
    Dependente(std::string nome) : nome(nome) {}
    std::string getNome() const { return nome; }
};

class Cliente {
private:
    std::string nome;
    std::vector<Dependente> dependentes;
    Pacote pacoteContratado;

public:
    Cliente(std::string nome) : nome(nome), pacoteContratado("") {}
    void adicionarDependente(Dependente dependente) { dependentes.push_back(dependente); }
    void contratarPacote(Pacote pacote) { pacoteContratado = pacote; }
    std::string getNome() const { return nome; }
    const std::vector<Dependente>& getDependentes() const { return dependentes; }
    const Pacote& getPacoteContratado() const { return pacoteContratado; }
};

void cadastrarEvento(std::vector<Evento>& eventos) {
    std::string nome, data;
    std::cout << "Nome do Evento: ";
    std::cin >> nome;
    std::cout << "Data do Evento (AAAA-MM-DD): ";
    std::cin >> data;
    eventos.push_back(Evento(nome, data));
}

void cadastrarPacote(std::vector<Pacote>& pacotes, const std::vector<Evento>& eventos) {
    std::string nomePacote;
    std::cout << "Nome do Pacote: ";
    std::cin >> nomePacote;

    Pacote pacote(nomePacote);

    int escolha;
    do {
        std::cout << "Escolha um evento para adicionar ao pacote:" << std::endl;
        for (size_t i = 0; i < eventos.size(); ++i) {
            std::cout << i+1 << ". " << eventos[i].getNome() << " (Data: " << eventos[i].getData() << ")" << std::endl;
        }
        std::cout << "0. Concluir cadastro do pacote" << std::endl;
        std::cin >> escolha;

        if (escolha > 0 && escolha <= static_cast<int>(eventos.size())) {
            pacote.adicionarEvento(eventos[escolha-1]);
        }
    } while (escolha != 0);

    pacotes.push_back(pacote);
}

void cadastrarCliente(std::vector<Cliente>& clientes, const std::vector<Pacote>& pacotes) {
    std::string nomeCliente;
    std::cout << "Nome do Cliente: ";
    std::cin >> nomeCliente;

    Cliente cliente(nomeCliente);

    int escolha;
    do {
        std::cout << "Escolha um pacote para o cliente (ou 0 para sair):" << std::endl;
        for (size_t i = 0; i < pacotes.size(); ++i) {
            std::cout << i+1 << ". " << pacotes[i].getNome() << std::endl;
        }
        std::cin >> escolha;

        if (escolha > 0 && escolha <= static_cast<int>(pacotes.size())) {
            cliente.contratarPacote(pacotes[escolha-1]);
        }
    } while (escolha != 0);

    clientes.push_back(cliente);
}

void exibirInformacoes(const std::vector<Evento>& eventos, const std::vector<Pacote>& pacotes, const std::vector<Cliente>& clientes) {
    std::cout << "\n--- Eventos ---" << std::endl;
    for (const Evento& evento : eventos) {
        std::cout << "Nome: " << evento.getNome() << ", Data: " << evento.getData() << std::endl;
    }

    std::cout << "\n--- Pacotes ---" << std::endl;
    for (const Pacote& pacote : pacotes) {
        std::cout << "Nome: " << pacote.getNome() << std::endl;
        const std::vector<Evento>& eventosDoPacote = pacote.getEventos();
        for (const Evento& evento : eventosDoPacote) {
            std::cout << "- " << evento.getNome() << " (Data: " << evento.getData() << ")" << std::endl;
        }
    }

    std::cout << "\n--- Clientes ---" << std::endl;
    for (const Cliente& cliente : clientes) {
        std::cout << "Nome do Cliente: " << cliente.getNome() << std::endl;
        const Pacote& pacoteContratado = cliente.getPacoteContratado();
        if (pacoteContratado.getNome() != "") {
            std::cout << "Pacote Contratado: " << pacoteContratado.getNome() << std::endl;
            const std::vector<Evento>& eventosDoPacote = pacoteContratado.getEventos();
            for (const Evento& evento : eventosDoPacote) {
                std::cout << "- " << evento.getNome() << " (Data: " << evento.getData() << ")" << std::endl;
            }
        }
        else {
            std::cout << "Cliente ainda não contratou nenhum pacote." << std::endl;
        }

        const std::vector<Dependente>& dependentes = cliente.getDependentes();
        if (!dependentes.empty()) {
            std::cout << "Dependentes:" << std::endl;
            for (const Dependente& dependente : dependentes) {
                std::cout << "- " << dependente.getNome() << std::endl;
            }
        }
        else {
            std::cout << "Cliente não possui dependentes." << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Evento> eventos;
    std::vector<Pacote> pacotes;
    std::vector<Cliente> clientes;

    int escolha;

    do {
        std::cout << "\nMenu Principal:" << std::endl;
        std::cout << "1. Cadastrar Evento" << std::endl;
        std::cout << "2. Cadastrar Pacote" << std::endl;
        std::cout << "3. Cadastrar Cliente" << std::endl;
        std::cout << "4. Exibir Informações" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cin >> escolha;

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
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (escolha != 5);

    return 0;
}
