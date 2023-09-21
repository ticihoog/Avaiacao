#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Cliente {
    string cpf;
    string nome;
    string dataNascimento;
    string cnh;
};


struct Veiculo {
    string renavan;
    string placa;
    string dataHoraRetiradaPrevista;
    string dataHoraEntregaPrevista;
    string lojaRetirada;
};


struct Locacao {
    string cpfCliente;
    string placaVeiculo;
    string dataHoraRetiradaReal;
    bool retiradaRealizada;
    string dataHoraEntregaReal;
};


void incluirCliente(vector<Cliente> &clientes) {
    Cliente novoCliente;
    cout << "CPF: ";
    cin >> novoCliente.cpf;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, novoCliente.nome);
    cout << "Data de Nascimento: ";
    getline(cin, novoCliente.dataNascimento);
    cout << "Número da CNH: ";
    getline(cin, novoCliente.cnh);

    clientes.push_back(novoCliente);
    cout << "Cliente adicionado com sucesso!" << endl;
}


void excluirCliente(vector<Cliente> &clientes, const string &cpf) {
    auto it = remove_if(clientes.begin(), clientes.end(),
                        [&](const Cliente &c) { return c.cpf == cpf; });

    if (it != clientes.end()) {
        clientes.erase(it, clientes.end());
        cout << "Cliente excluído com sucesso!" << endl;
    } else {
        cout << "Cliente não encontrado." << endl;
    }
}


void listarClientes(const vector<Cliente> &clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado ainda." << endl;
    } else {
        cout << "\nLista de Clientes:" << endl;
        for (const Cliente &cliente : clientes) {
            cout << "CPF: " << cliente.cpf << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "Data de Nascimento: " << cliente.dataNascimento << endl;
            cout << "CNH: " << cliente.cnh << endl;
            cout << "------------------------" << endl;
        }
    }
}


void localizarCliente(const vector<Cliente> &clientes, const string &cpf) {
    bool encontrado = false;
    for (const Cliente &cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "CPF: " << cliente.cpf << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "Data de Nascimento: " << cliente.dataNascimento << endl;
            cout << "CNH: " << cliente.cnh << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente não encontrado." << endl;
    }
}


void incluirVeiculo(vector<Veiculo> &veiculos) {
    Veiculo novoVeiculo;
    cout << "Renavan: ";
    cin >> novoVeiculo.renavan;
    cin.ignore();
    cout << "Placa: ";
    getline(cin, novoVeiculo.placa);
    cout << "Data e Hora de Retirada (prevista): ";
    getline(cin, novoVeiculo.dataHoraRetiradaPrevista);
    cout << "Data e Hora de Entrega (prevista): ";
    getline(cin, novoVeiculo.dataHoraEntregaPrevista);
    cout << "Loja de Retirada: ";
    getline(cin, novoVeiculo.lojaRetirada);

    veiculos.push_back(novoVeiculo);
    cout << "Veículo adicionado com sucesso!" << endl;
}


void excluirVeiculo(vector<Veiculo> &veiculos, const string &placa) {
    auto it = remove_if(veiculos.begin(), veiculos.end(),
                        [&](const Veiculo &v) { return v.placa == placa; });

    if (it != veiculos.end()) {
        veiculos.erase(it, veiculos.end());
        cout << "Veículo excluído com sucesso!" << endl;
    } else {
        cout << "Veículo não encontrado." << endl;
    }
}


void listarVeiculos(const vector<Veiculo> &veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado ainda." << endl;
    } else {
        cout << "\nLista de Veículos:" << endl;
        for (const Veiculo &veiculo : veiculos) {
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data e Hora de Retirada (prevista): " << veiculo.dataHoraRetiradaPrevista << endl;
            cout << "Data e Hora de Entrega (prevista): " << veiculo.dataHoraEntregaPrevista << endl;
            cout << "Loja de Retirada: " << veiculo.lojaRetirada << endl;
            cout << "------------------------" << endl;
        }
    }
}


void localizarVeiculo(const vector<Veiculo> &veiculos, const string &placa) {
    bool encontrado = false;
    for (const Veiculo &veiculo : veiculos) {
        if (veiculo.placa == placa) {
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data e Hora de Retirada (prevista): " << veiculo.dataHoraRetiradaPrevista << endl;
            cout << "Data e Hora de Entrega (prevista): " << veiculo.dataHoraEntregaPrevista << endl;
            cout << "Loja de Retirada: " << veiculo.lojaRetirada << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Veículo não encontrado." << endl;
    }
}


void incluirLocacao(vector<Locacao> &locacoes, const vector<Cliente> &clientes, const vector<Veiculo> &veiculos) {
    Locacao novaLocacao;
    cout << "CPF do Cliente: ";
    cin >> novaLocacao.cpfCliente;
    cout << "Placa do Veículo: ";
    cin >> novaLocacao.placaVeiculo;


    bool clienteExiste = false;
    bool veiculoExiste = false;

    for (const Cliente &cliente : clientes) {
        if (cliente.cpf == novaLocacao.cpfCliente) {
            clienteExiste = true;
            break;
        }
    }

    for (const Veiculo &veiculo : veiculos) {
        if (veiculo.placa == novaLocacao.placaVeiculo) {
            veiculoExiste = true;
            break;
        }
    }

    if (!clienteExiste) {
        cout << "Cliente com CPF " << novaLocacao.cpfCliente << " não encontrado." << endl;
        return;
    }

    if (!veiculoExiste) {
        cout << "Veículo com Placa " << novaLocacao.placaVeiculo << " não encontrado." << endl;
        return;
    }

    cout << "Data e Hora de Retirada (real): ";
    cin.ignore();
    getline(cin, novaLocacao.dataHoraRetiradaReal);

    cout << "A Retirada já aconteceu? (SIM ou NAO): ";
    string retiradaRealizadaStr;
    getline(cin, retiradaRealizadaStr);
    novaLocacao.retiradaRealizada = (retiradaRealizadaStr == "SIM");

    cout << "Data e Hora de Entrega (real): ";
    getline(cin, novaLocacao.dataHoraEntregaReal);

    locacoes.push_back(novaLocacao);
    cout << "Locação registrada com sucesso!" << endl;
}


void excluirLocacao(vector<Locacao> &locacoes, const string &placa) {
    vector<int> locacoesParaExcluir;

    
    for (int i = 0; i < locacoes.size(); ++i) {
        if (locacoes[i].placaVeiculo == placa) {
            locacoesParaExcluir.push_back(i);
        }
    }

    if (locacoesParaExcluir.empty()) {
        cout << "Nenhuma locação encontrada para o veículo com placa " << placa << endl;
        return;
    }


    if (locacoesParaExcluir.size() > 1) {
        cout << "Mais de uma locação encontrada para o veículo com placa " << placa << ". Escolha uma:" << endl;
        for (int i = 0; i < locacoesParaExcluir.size(); ++i) {
            int locacaoIndex = locacoesParaExcluir[i];
            cout << i + 1 << ". Cliente CPF: " << locacoes[locacaoIndex].cpfCliente;
            cout << ", Data de Retirada: " << locacoes[locacaoIndex].dataHoraRetiradaReal << endl;
        }

        int escolha;
        cin >> escolha;
        if (escolha <= 0 || escolha > locacoesParaExcluir.size()) {
            cout << "Escolha inválida." << endl;
            return;
        }

        int locacaoIndex = locacoesParaExcluir[escolha - 1];
        locacoes.erase(locacoes.begin() + locacaoIndex);
    } else {
     
        int locacaoIndex = locacoesParaExcluir[0];
        locacoes.erase(locacoes.begin() + locacaoIndex);
    }

    cout << "Locação(s) excluída(s) com sucesso!" << endl;
}


void alterarLocacao(vector<Locacao> &locacoes, const string &placa) {
    vector<int> locacoesParaAlterar;

    for (int i = 0; i < locacoes.size(); ++i) {
        if (locacoes[i].placaVeiculo == placa) {
            locacoesParaAlterar.push_back(i);
        }
    }

    if (locacoesParaAlterar.empty()) {
        cout << "Nenhuma locação encontrada para o veículo com placa " << placa << endl;
        return;
    }


    if (locacoesParaAlterar.size() > 1) {
        cout << "Mais de uma locação encontrada para o veículo com placa " << placa << ". Escolha uma:" << endl;
        for (int i = 0; i < locacoesParaAlterar.size(); ++i) {
            int locacaoIndex = locacoesParaAlterar[i];
            cout << i + 1 << ". Cliente CPF: " << locacoes[locacaoIndex].cpfCliente;
            cout << ", Data de Retirada: " << locacoes[locacaoIndex].dataHoraRetiradaReal << endl;
        }

        int escolha;
        cin >> escolha;
        if (escolha <= 0 || escolha > locacoesParaAlterar.size()) {
            cout << "Escolha inválida." << endl;
            return;
        }

        int locacaoIndex = locacoesParaAlterar[escolha - 1];
        cout << "Data e Hora de Entrega (real): ";
        cin.ignore();
        getline(cin, locacoes[locacaoIndex].dataHoraEntregaReal);
    } else {
    
        int locacaoIndex = locacoesParaAlterar[0];
        cout << "Data e Hora de Entrega (real): ";
        cin.ignore();
        getline(cin, locacoes[locacaoIndex].dataHoraEntregaReal);
    }

    cout << "Locação(s) alterada(s) com sucesso!" << endl;
}


void listarLocacoes(const vector<Locacao> &locacoes) {
    if (locacoes.empty()) {
        cout << "Nenhuma locação registrada ainda." << endl;
    } else {
        cout << "\nLista de Locações:" << endl;
        for (const Locacao &locacao : locacoes) {
            cout << "CPF do Cliente: " << locacao.cpfCliente << endl;
            cout << "Placa do Veículo: " << locacao.placaVeiculo << endl;
            cout << "Data e Hora de Retirada (real): " << locacao.dataHoraRetiradaReal << endl;
            cout << "Retirada Realizada: " << (locacao.retiradaRealizada ? "SIM" : "NAO") << endl;
            cout << "Data e Hora de Entrega (real): " << locacao.dataHoraEntregaReal << endl;
            cout << "------------------------" << endl;
        }
    }
}

int main() {
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;
    vector<Locacao> locacoes;

    int opcao;

    while (true) {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Gestão de Clientes" << endl;
        cout << "2. Gestão de Veículos" << endl;
        cout << "3. Gestão de Locações" << endl;
        cout << "0. Sair do Programa" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                while (true) {
                    cout << "\nMenu de Gestão de Clientes:" << endl;
                    cout << "1. Incluir Cliente" << endl;
                    cout << "2. Excluir Cliente" << endl;
                    cout << "3. Listar Clientes" << endl;
                    cout << "4. Localizar Cliente" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            incluirCliente(clientes);
                            break;
                        case 2: {
                            string cpf;
                            cout << "Digite o CPF do cliente a ser excluído: ";
                            cin >> cpf;
                            excluirCliente(clientes, cpf);
                            break;
                        }
                        case 3:
                            listarClientes(clientes);
                            break;
                        case 4: {
                            string cpf;
                            cout << "Digite o CPF do cliente a ser localizado: ";
                            cin >> cpf;
                            localizarCliente(clientes, cpf);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                            break;
                    }

                    if (opcao == 0) {
                        break;
                    }
                }
                break;

            case 2:
                while (true) {
                    cout << "\nMenu de Gestão de Veículos:" << endl;
                    cout << "1. Incluir Veículo" << endl;
                    cout << "2. Excluir Veículo" << endl;
                    cout << "3. Listar Veículos" << endl;
                    cout << "4. Localizar Veículo" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            incluirVeiculo(veiculos);
                            break;
                        case 2: {
                            string placa;
                            cout << "Digite a Placa do veículo a ser excluído: ";
                            cin >> placa;
                            excluirVeiculo(veiculos, placa);
                            break;
                        }
                        case 3:
                            listarVeiculos(veiculos);
                            break;
                        case 4: {
                            string placa;
                            cout << "Digite a Placa do veículo a ser localizado: ";
                            cin >> placa;
                            localizarVeiculo(veiculos, placa);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                            break;
                    }

                    if (opcao == 0) {
                        break;
                    }
                }
                break;

            case 3:
                while (true) {
                    cout << "\nMenu de Gestão de Locações:" << endl;
                    cout << "1. Incluir Locação" << endl;
                    cout << "2. Excluir Locação" << endl;
                    cout << "3. Alterar Locação" << endl;
                    cout << "4. Listar Locações" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            incluirLocacao(locacoes, clientes, veiculos);
                            break;
                        case 2: {
                            string placa;
                            cout << "Digite a Placa do veículo para excluir a locação: ";
                            cin >> placa;
                            excluirLocacao(locacoes, placa);
                            break;
                        }
                        case 3: {
                            string placa;
                            cout << "Digite a Placa do veículo para alterar a locação: ";
                            cin >> placa;
                            alterarLocacao(locacoes, placa);
                            break;
                        }
                        case 4:
                            listarLocacoes(locacoes);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                            break;
                    }

                    if (opcao == 0) {
                        break;
                    }
                }
                break;

            case 0:
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
