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