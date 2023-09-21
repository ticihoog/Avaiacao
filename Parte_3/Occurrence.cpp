#include "Occurrence.h"
#include <iostream>
#include <unistd.h>

void occurrenceMenu(vector<Occurrence> &occurrences, vector<Rental> &rentals)
{
    Occurrence occurrence;

    system("clear || cls");
    int option;
    do
    {
        cout << " ----- Gestão de Ocorrências ----- " << endl
             << endl
             << "1 - Incluir Ocorrência" << endl
             << "2 - Exlcuir Ocorrência" << endl
             << "3 - Alterar Dados Ocorrência" << endl
             << "4 - Mostrar Ocorrências por Cliente" << endl
             << "5 - Mostrar Ocorrências por Veículo" << endl
             << "6 - Sair" << endl
             << endl;

        cout << "Selecione a opção: ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            Occurrence occurrence;
            occurrence = occurrenceRegistration(occurrences, rentals);
            occurrences.push_back(occurrence);

            cout << "Ocorrência incluída no sistema!!" << endl
                 << endl;
            sleep(2);
        }
        break;
        case 2:
        {
            if (!occurrences.empty())
            {

                deleteOccurrence(occurrences);
            }
            else
            {
                cout << "Não há ocorrências cadastradas!!!";
            }
        }
        break;

        case 3:
        {
            if (!occurrences.empty())
            {

                updateOccurence(occurrences);
            }
            else
            {
                cout << "Não há ocorrências cadastradas!!!";
            }
        }
        break;

        case 4:
        {
            if (!occurrences.empty())
            {

                listOccurrencesPerClient(occurrences);
            }
            else
            {
                cout << "Não ocorrências cadastradas!!!" << endl;
                sleep(2);
            }
        }
        break;
        case 5:
        {
            if (!occurrences.empty())
            {

                listOccurrencesPerCar(occurrences);
            }
            else
            {
                cout << "Não ocorrências cadastradas!!!" << endl;
                sleep(2);
            }
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

bool isValidPolicy(string policyNumber)
{
    if (policyNumber[2] == '-' && policyNumber[5] == '-' && policyNumber[9] == '.')
        return true;
    else
        return false;
}

Occurrence occurrenceRegistration(vector<Occurrence> &occurrences, vector<Rental> &rentals)
{
    Occurrence occurrence;
    string CPF, carPlateCpy;
    bool successCPF = false, successPlate = false;

    do
    {
        cout << endl;
        cout << "CPF do Passageiro: ";
        cin.ignore();
        getline(cin, CPF);

        bool isValidCPF = (cpfVerification(CPF));

        if (isValidCPF)
        {
            successCPF = true;
            for (const Rental &rental : rentals)
            {
                if (rental.clientData.CPF == CPF)
                {
                    do
                    {
                        string carPlate;
                        bool carPlateVerify;

                        cout << "Placa do Carro: ";
                        getline(cin, carPlate);
                        carPlateVerify = plateVerification(carPlate);

                        if (carPlateVerify)
                        {
                            successPlate = true;
                            bool carFound = false;

                            if (rental.carData.carPlate == carPlate)
                            {
                                cout << "Digite a descrição da ocorrência: ";
                                cin.ignore();
                                getline(cin, occurrence.description);

                                cout
                                    << "Data e Hora da ocorrência (DD MM YYYY HH MM): ";
                                catchDateCar(occurrence.ocurrenceDate, occurrence.ocurrenceHour);

                                do
                                {
                                    string policyNumber;
                                    cout
                                        << "Número da apólice (XX-XX-XXX.XXX):  ";
                                    cin.ignore();
                                    getline(cin, policyNumber);

                                    if (isValidPolicy && policyNumber.size() == 13)
                                    {
                                        occurrence.policyNumber = policyNumber;
                                        break;
                                    }
                                    else
                                        cout << "Número da apólice inválida!!" << endl;

                                } while (true);

                                occurrence.rentalOccurrence = rental;
                                occurrence.rentalOccurrence = rental;
                            }

                            if (!carFound)
                                cout << "Ocorrência com placa não encontrada!!!" << endl;
                        }
                        else
                        {
                            cout << "Placa Inválida!!!" << endl;
                        }

                        if (successPlate)
                            break;
                    } while (true);
                }
                else
                {
                    cout << "Ocorrência com CPF não encontrada!!!";
                }
            }
        }
        else
        {
            cout << "CPF inválidO!!!" << endl;
        }
        if (successCPF)
            break;
    } while (true);

    cout
        << endl;

    return occurrence;
}

void listOccurrencesPerClient(const vector<Occurrence> &occurrences)
{

    do
    {
        string CPF;

        cout << endl;
        cout << "CPF do Passageiro (XXX.XXX.XXX-XX): ";
        cin.ignore();
        getline(cin, CPF);

        bool isValidCPF = cpfVerification(CPF);

        if (isValidCPF)
        {
            for (const Occurrence &occurrence : occurrences)
            {
                if (occurrence.rentalOccurrence.clientData.CPF == CPF)
                {
                    cout << "----- Todos as Ocorrências ----- " << endl;
                    for (const Occurrence &occurrence : occurrences)
                    {
                        cout << "Descrição da Ocorrência: " << occurrence.description << endl;
                        showDateCar(occurrence.ocurrenceDate, occurrence.ocurrenceHour);
                        cout
                            << "Número da Apólice: " << occurrence.policyNumber << endl
                            << "Nome do Cliente: " << occurrence.rentalOccurrence.clientData.name << endl
                            << "CPF do Cliente: " << occurrence.rentalOccurrence.clientData.CPF << endl
                            << "Placa do Carro: " << occurrence.rentalOccurrence.carData.carPlate << endl
                            << endl;
                    }
                    return;
                }
                else
                {
                    cout << "Ocorrência com CPF não encontrada!!!";
                    return;
                }
            }
        }
        else
        {
            cout << "CPF inválidO!!!" << endl;
            break;
        }
    } while (true);

    return;
}
