#include <iostream>
#include <vector>
#include <unistd.h>
#include "Client.h"
#include "Car.h"
#include "Rental.h"

using namespace std;

int main()
{
    vector<Client> customers;
    vector<Car> cars;
    vector<Rental> rentals;

    int option;
    do
    {
        cout << " ----- Menu Principal ----- " << endl
             << endl
             << "1 - Gestor de Clientes" << endl
             << "2 - Gestor de Carros" << endl
             << "3 - Gestor de Locações" << endl
             << "4 - Sair" << endl
             << endl;

        cout << "Selecione a opção: ";

        cin >> option;

        switch (option)
        {
        case 1:
            clientMenu(customers);
            break;
        case 2:
            carMenu(cars);
            break;
        case 3:
            rentalMenu(rentals, cars, customers);
            break;
        case 4:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opção inválida!!!" << endl
                 << endl;
            sleep(3);
        }
    } while (option != 4);

    return 0;
}