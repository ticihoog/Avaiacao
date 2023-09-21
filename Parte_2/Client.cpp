#include "Client.h"
#include "Common.h"
#include <iostream>
#include <unistd.h>

Client registerClient(vector<Client> &customers)
{
    Client client;

    cout << "Nome do cliente: ";
    cin.ignore();
    getline(cin, client.name);

    do
    {
        bool cpfVerify, success;
        string cpf;

        cout << "CPF do cliente (XXX.XXX.XXX-XX): ";
        cin >> cpf;

        cpfVerify = cpfVerification(cpf);

        if (cpfVerify)
        {
            for (auto it = customers.begin(); it != customers.end(); ++it)
            {
                if (it->CPF == cpf)
                {
                    success == false;
                }
                else
                {
                    success = true;
                }
            }
        }
        else
        {
            cout << "CPF incorreto!! Digite novamente!!" << endl;
        }
        if (success){
            client.CPF = cpf;
            break;
        }else{
            cout << "CPF já cadastrado!!!" << endl;
        }

    } while (true);

    cout
        << "Data de Nascimento (DD MM YYYY): ";
    catchDateClient(client.birthDate);

    do
    {
        bool cnhVerify, success;
        string cnh;

        cout << "CNH do cliente (XXXXXXXXXXX): ";
        cin >> cnh;

        cnhVerify = (cnh.size() == 11) ? true : false;

        if (cnhVerify)
        {
            for (auto it = customers.begin(); it != customers.end(); ++it)
            {
                if (it->CNH == cnh)
                {
                    success = false;
                }
                else
                {
                    success = true;
                }
            }
        }
        else
        {
            cout << "CNH incorreta!! Digite novamente!!" << endl;
        }
        if (success){
            client.CNH = cnh;
            break;
        }else{

                    cout << "CNH já cadastrada!!!" << endl;
        }

    } while (true);

    cout << endl;

    return client;
}

void clientMenu(vector<Client> &customers)
{
    system("clear || cls");
    int option;
    do
    {
        cout << " ----- Menu Cliente ----- " << endl
             << endl
             << "1 - Incluir Cliente" << endl
             << "2 - Exlcuir Cliente" << endl
             << "3 - Alterar Dados Cliente" << endl
             << "4 - Listar Clientes" << endl
             << "5 - Localizar Cliente" << endl
             << "6 - Sair" << endl
             << endl;

        cout << "Selecione a opção: ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            Client client;
            client = registerClient(customers);
            customers.push_back(client);

            cout << "Usuário " << client.name << " incluído no sistema!!" << endl
                 << endl;
            sleep(2);
        }
        break;
        case 2:
        {
            if (customers.empty())
            {
                cout << "Não existe cliente cadastrado!!!" << endl;
                sleep(2);
            }
            else
            {
                deleteClient(customers);
                sleep(2);
                system("clear || cls");
            }
        }
        break;
        case 3:
        {
            if (customers.empty())
            {
                cout << "Não existe cliente cadastrado!!!" << endl;
                sleep(2);
            }
            else
                updateClient(customers);
        }
        break;
        case 4:
        {
            if (customers.empty())
            {
                cout << "Não existe cliente cadastrado!!!" << endl;
                sleep(2);
            }
            else
                showCustomers(customers);
        }
        break;
        case 5:
        {
            if (customers.empty())
            {
                cout << "Não existe cliente cadastrado!!!" << endl;
                sleep(2);
            }
            else
                showClient(customers);
        }
        break;
        case 6:
            break;
        default:
            cout << "Opção inválida!!!" << endl
                 << endl;
            sleep(3);
        }
    } while (option != 6);
}

void catchDateClient(Date &date)
{
    bool success = false;
    int day, month, year;
    do
    {
        cin >> day >> month >> year;

        if (month >= 1 && month <= 12)
        {

            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 10 || month == 12)
            {
                if (day >= 1 && day <= 31)
                {
                    date.day = day;
                    date.month = month;
                    date.year = year;
                    success = true;
                }
                else
                {
                    cout << "Dia inválido!!! Digite novamente: ";
                }
            }
            else if (month == 4 || month == 6 || month == 7 || month == 11)
            {
                if (day >= 1 && day <= 30)
                {
                    date.day = day;
                    date.month = month;
                    date.year = year;
                    success = true;
                }
                else
                {
                    cout << "Dia inválido!!! Digite novamente: ";
                }
            }
            else if (month == 2)
            {
                if (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)))
                {

                    if (day >= 1 && day <= 29)
                    {
                        date.day = day;
                        date.month = month;
                        date.year = year;
                        success = true;
                    }
                    else
                    {
                        cout << "Dia inválido!!! Digite novamente: ";
                    }
                }
                else
                {
                    if (day >= 1 && day <= 28)
                    {
                        date.day = day;
                        date.month = month;
                        date.year = year;
                        success = true;
                    }
                    else
                    {
                        cout << "Dia inválido!!! Digite novamente: ";
                    }
                }
            }
        }
        else
        {
            cout << "Mês Incorreto!!! Digite novamente: " << endl;
        }

    } while (success != true);
}

void showDateClient(Date date)
{
    cout << "Data de Nascimento: " << date.day << "/" << date.month << "/" << date.year << endl;
}

bool cpfVerification(string CPF)
{
    if (CPF.size() == 14)
    {
        if (CPF[3] == '.' && CPF[7] == '.' && CPF[11] == '-')
            return true;
        else
            return false;
    }
    else
        return false;
}

void showCustomers(const vector<Client> &customers)
{
    cout << "----- Todos os Clientes----- " << endl;
    for (const Client &client : customers)
    {
        cout << "Nome do Cliente: " << client.name << endl
             << "CPF: " << client.CPF << endl;
        showDateClient(client.birthDate);
        cout << "CNH: " << client.CNH << endl
             << endl;
    }
}

void showClient(const vector<Client> &customers)
{
    string CPF;
    bool cpfVerify;

    cout << endl;
    cout << "Digite o CPF do cliente (XXX.XXX.XXX-XX): ";
    cin.ignore();
    getline(cin, CPF);
    cpfVerify = cpfVerification(CPF);

    if (cpfVerify)
    {
        for (const Client &client : customers)
        {
            if (client.CPF == CPF)
            {
                cout << "Nome do Cliente: " << client.name << endl;
                cout << "CPF: " << client.CPF << endl;
                showDateClient(client.birthDate);
                cout << "CNH: " << client.CNH << endl
                     << endl;
            }
            else
            {
                cout << "Cliente não encontrado!!!";
            }
        }
    }
    else
    {
        cout << "CPF inválido!!!" << endl;
    }
    sleep(2);
}

void deleteClient(vector<Client> &customers)
{
    string CPF;
    bool cpfVerify;

    cout << endl;
    cout << "Digite o CPF do cliente (XXX.XXX.XXX-XX): ";
    cin.ignore();
    getline(cin, CPF);
    cpfVerify = cpfVerification(CPF);

    if (cpfVerify)
    {

        for (auto it = customers.begin(); it != customers.end(); ++it)
        {
            if (it->CPF == CPF)
            {
                customers.erase(it);
                cout << "Cliente " << CPF << " excluído com sucesso!" << endl;
                return;
            }
        }
        cout << "Cliente " << CPF << " não encontrado." << endl;
    }
    else
    {
        cout << "CPF inválido!!!" << endl;
    }
    sleep(2);
}

void updateClient(vector<Client> &customers)
{
    string CPF;
    bool cpfVerify;

    cout << endl;
    cout << "Digite o CPF do cliente (XXX.XXX.XXX-XX): ";
    cin.ignore();
    getline(cin, CPF);
    cpfVerify = cpfVerification(CPF);

    if (cpfVerify)
    {
        int option;

        for (auto it = customers.begin(); it != customers.end(); ++it)
        {
            if (it->CPF == CPF)
            {
                cout << "Nome do Cliente: " << it->name << endl;
                cout << "CPF: " << it->CPF << endl;
                showDateClient(it->birthDate);
                cout << "CNH: " << it->CNH
                     << endl
                     << endl;

                cout << "1 - Alterar Nome" << endl
                     << "2 - Alterar CPF" << endl
                     << "3 - Alterar Data de Nascimento" << endl
                     << "4 - Alterar CNH" << endl
                     << "5 - Sair" << endl
                     << endl;
                cout << "Selecione a opção: ";
                cin >> option;

                switch (option)
                {
                case 1:
                {
                    string name;
                    cout << "Digite o novo nome para o cliente: ";

                    cin.ignore();
                    getline(cin, name);

                    it->name = name;

                    cout << "Nome do cliente alterado com sucesso!!!" << endl
                         << "Novo nome: " << name << endl;
                }
                break;
                case 2:
                {

                    string CPF;
                    cout << "Digite o novo CPF para o cliente: ";
                    cin.ignore();
                    getline(cin, CPF);

                    it->CPF = CPF;

                    cout << "CPF do cliente alterado com sucesso!!!" << endl
                         << "Novo CPF: " << CPF;
                    cout << endl;
                }
                break;
                case 3:
                {

                    cout << "Digite a nova data para o cliente: ";
                    catchDateClient(it->birthDate);

                    cout << "Data de Nascimento do cliente alterada com sucesso!!!" << endl
                         << "Nova data: ";
                    showDateClient(it->birthDate);
                    cout << endl;
                }
                break;
                case 4:
                {
                    string CNH;
                    cout << "Digite o novo CNH para o cliente: ";
                    cin.ignore();
                    getline(cin, CNH);

                    it->CNH = CNH;

                    cout << "CNH do cliente alterado com sucesso!!!" << endl
                         << "Novo CNH: " << CNH << endl
                         << endl;
                }
                break;

                default:
                    cout << "Nenhum dado alterado!!";
                    break;
                }
            }
            else
            {
                cout << "Cliente não encontrado!!!";
            }
        }
    }
    else
    {
        cout << "CPF Inválido!!!" << endl;
    }
    sleep(2);
}