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
    string dataHoraRetirada;
    string dataHoraEntrega;
    string lojaRetirada;
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
    getline(cin, novoVeiculo.dataHoraRetirada);
    cout << "Data e Hora de Entrega (prevista): ";
    getline(cin, novoVeiculo.dataHoraEntrega);
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
            cout << "Data e Hora de Retirada (prevista): " << veiculo.dataHoraRetirada << endl;
            cout << "Data e Hora de Entrega (prevista): " << veiculo.dataHoraEntrega << endl;
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
            cout << "Data e Hora de Retirada (prevista): " << veiculo.dataHoraRetirada << endl;
            cout << "Data e Hora de Entrega (prevista): " << veiculo.dataHoraEntrega << endl;
            cout << "Loja de Retirada: " << veiculo.lojaRetirada << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Veículo não encontrado." << endl;
    }
}

int main() {
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;

    int opcao;
    while (true) {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Gestão de Clientes" << endl;
        cout << "2. Gestão de Veículos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                while (true) {
                    cout << "\nMenu de Opções de Clientes:" << endl;
                    cout << "1. Incluir Cliente" << endl;
                    cout << "2. Excluir Cliente" << endl;
                    cout << "3. Alterar Cliente" << endl;
                    cout << "4. Listar Clientes" << endl;
                    cout << "5. Localizar Cliente" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            incluirCliente(clientes);
                            break;
                        case 2:
                            {
                                string cpf;
                                cout << "Digite o CPF do cliente a ser excluído: ";
                                cin >> cpf;
                                excluirCliente(clientes, cpf);
                            }
                            break;
                        case 3:
                            {
                                string cpf;
                                cout << "Digite o CPF do cliente a ser alterado: ";
                                cin >> cpf;
                                localizarCliente(clientes, cpf);
                                // Implemente a alteração dos dados aqui
                            }
                            break;
                        case 4:
                            listarClientes(clientes);
                            break;
                        case 5:
                            {
                                string cpf;
                                cout << "Digite o CPF do cliente a ser localizado: ";
                                cin >> cpf;
                                localizarCliente(clientes, cpf);
                            }
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
            case 2:
                while (true) {
                    cout << "\nMenu de Opções de Veículos:" << endl;
                    cout << "1. Incluir Veículo" << endl;
                    cout << "2. Excluir Veículo" << endl;
                    cout << "3. Alterar Veículo" << endl;
                    cout << "4. Listar Veículos" << endl;
                    cout << "5. Localizar Veículo" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcao;

                    switch (opcao) {
                        case 1:
                            incluirVeiculo(veiculos);
                            break;
                        case 2:
                            {
                                string placa;
                                cout << "Digite a Placa do veículo a ser excluído: ";
                                cin >> placa;
                                excluirVeiculo(veiculos, placa);
                            }
                            break;
                        case 3:
                            {
                                string placa;
                                cout << "Digite a Placa do veículo a ser alterado: ";
                                cin >> placa;
                                localizarVeiculo(veiculos, placa);
                                // Implemente a alteração dos dados aqui
                            }
                            break;
                        case 4:
                            listarVeiculos(veiculos);
                            break;
                        case 5:
                            {
                                string placa;
                                cout << "Digite a Placa do veículo a ser localizado: ";
                                cin >> placa;
                                localizarVeiculo(veiculos, placa);
                            }
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
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}