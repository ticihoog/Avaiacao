#include "Client.h"
#include "Car.h"
#include "Common.h"
#include "Rental.h"
#include <iostream>
#include <unistd.h>

void rentalMenu(vector<Rental> &rentals, vector<Car> &cars, vector<Client> &customers)
{

    system("clear || cls");
    int option;
    do
    {
        cout << " ----- Menu Carros ----- " << endl
             << endl
             << "1 - Incluir Locação" << endl
             << "2 - Listar Locações" << endl
             << "3 - Sair" << endl
             << endl;

        cout << "Selecione a opção: ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            if (!cars.empty())
            {
                if (!customers.empty())
                {

                    Rental rental;
                    rental = registerRental(customers, cars);
                    rentals.push_back(rental);

                    cout << "Alocação incluído no sistema!!" << endl
                         << endl;
                    sleep(2);
                }
                else
                {
                    cout << "Não há clientes cadastrados!!!";
                }
            }
            else
            {
                cout << "Não há carros cadastrados!!!";
            }
        }
        break;
        case 2:
        {
            if (rentals.empty())
            {
                cout << "Não alocações cadastradas!!!" << endl;
                sleep(2);
            }
            else
                showRentals(rentals);
        }
        break;
        case 3:
            break;
        default:
            cout << "Opção inválida!!!" << endl
                 << endl;
            sleep(3);
        }
    } while (option != 3);
}

Rental registerRental(vector<Client> &customers, vector<Car> &cars)
{
    Rental rental;
    string CNH, carPlateCpy;
    bool success = false;

    do
    {
        cout << endl;
        cout << "CNH do Passageiro: ";
        cin.ignore();
        getline(cin, CNH);

        if (CNH.size() == 11)
        {
            for (const Client &client : customers)
            {
                if (client.CNH == CNH)
                {
                    rental.clientData = client;
                    success = true;
                }
                else
                {
                    cout << "Cliente não encontrado!!!";
                }
            }
        }
        else
        {
            cout << "CNH inválida!!!" << endl;
        }
        if (success)
            break;
    } while (true);

    success = false;

    do
    {
        string carPlate;
        bool carPlateVerify;

        cout << "Placa do Carro: ";
        getline(cin, carPlate);
        carPlateVerify = plateVerification(carPlate);

        if (carPlateVerify)
        {
            bool carFound = false;
            for (const Car &car : cars)
            {
                if (car.carPlate == carPlate)
                {
                    rental.carData = car;
                    carPlateCpy = carPlate;
                    success = true;
                    carFound = true;
                    break;
                }
            }

            if (!carFound)
                cout << "Carro não encontrado!!!" << endl;
        }
        else
        {
            cout << "Placa Inválida!!!" << endl;
        }

        if (success)
            break;
    } while (true);

    cout << "A retirada já foi realizada? (s/n): ";
    cin >> rental.realized;

    if (rental.realized == 's')
    {
        cout
            << "Data de Entrega (DD MM YYYY HH MM): ";
        catchDateCar(rental.returnRentalDate, rental.hourReturnRentalDate);

        rental.carData.returnDate = rental.returnRentalDate;
        rental.carData.hourReturnDate = rental.hourReturnRentalDate;
        }
    else
    {
        cout
            << "Data e Hora de Retirada (DD MM YYYY HH MM): ";
        catchDateCar(rental.withdrawalRentalDate, rental.hourWithdrawRentalDate);

        cout
            << "Data de Entrega (DD MM YYYY HH MM): ";
        catchDateCar(rental.returnRentalDate, rental.hourReturnRentalDate);

        rental.carData.hourReturnDate = rental.hourReturnRentalDate;
        rental.carData.hourWithdrawDate = rental.hourWithdrawRentalDate;

        rental.carData.returnDate = rental.returnRentalDate;
        rental.carData.withdrawalDate = rental.withdrawalRentalDate;
    }

    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        if (it->carPlate == carPlateCpy)
        {
            it->hourReturnDate = rental.hourReturnRentalDate;
            it->hourWithdrawDate = rental.hourWithdrawRentalDate;

            it->returnDate = rental.returnRentalDate;
            it->withdrawalDate = rental.withdrawalRentalDate;
        }
    }

    cout
        << endl;

    return rental;
}

void showRentals(const vector<Rental> &rentals)
{
    cout << "----- Todos os Carros----- " << endl;
    for (const Rental &rental : rentals)
    {
        cout << "Nome do Cliente: " << rental.clientData.name << endl
             << "CNH do Cliente: " << rental.clientData.CNH << endl
             << "Nome do Carro: " << rental.carData.name << endl
             << "Placa do Carro: " << rental.carData.carPlate << endl
             << "Renavam do Carro: " << rental.carData.renavam << endl
             << "Loja de Retirada: " << rental.carData.concessionaire << endl
             << "Realizado: " << rental.realized << endl;
        cout << "Retirada: ";
        showDateCar(rental.withdrawalRentalDate, rental.hourWithdrawRentalDate);
        cout << "Entrega: ";
        showDateCar(rental.returnRentalDate, rental.hourReturnRentalDate);
    }
}
