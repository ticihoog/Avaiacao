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
             << "2 - Exlcuir Locação" << endl
             << "3 - Alterar Dados Locação" << endl
             << "4 - Listar Locações" << endl
             << "5 - Sair" << endl
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
            if (!rentals.empty())
            {

                deleteRental(rentals);
            }
            else
            {
                cout << "Não há alocações cadastrados!!!";
            }
        }
        break;

        case 3:
        {
            if (!rentals.empty())
            {

                updateRental(rentals, cars);
            }
            else
            {
                cout << "Não há alocações cadastrados!!!";
            }
        }
        break;

        case 4:
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
        case 5:
            break;
        default:
            cout << "Opção inválida!!!" << endl
                 << endl;
            sleep(3);
        }
    } while (option != 5);
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

void deleteRental(vector<Rental> &rentals)
{
    string carPlate;
    bool carPlateVerify;

    cout << endl;
    cout << "Digite a placa do carro: (XXX-XXX): ";
    cin.ignore();
    getline(cin, carPlate);
    carPlateVerify = plateVerification(carPlate);

    if (carPlateVerify)
    {

        for (const Rental &rental : rentals)
        {
            if (rental.carData.carPlate == carPlate)
            {
                cout << "Nome do Carro: " << rental.carData.name << endl
                     << "Renavam: " << rental.carData.renavam << endl
                     << "Placa do Carro: " << rental.carData.carPlate << endl;
                showDateCar(rental.carData.withdrawalDate, rental.carData.hourWithdrawDate);
                showDateCar(rental.carData.returnDate, rental.carData.hourReturnDate);
                cout << "Loja de Retirada: " << rental.carData.concessionaire << endl
                     << endl;
            }
            else
            {
                cout << "Carro não encontrado!!!" << endl;
            }
        }

        string CPF;
        bool cpfVerify = false;

        do
        {
            cout << endl;
            cout << "CPF do Passageiro: ";
            getline(cin, CPF);

            cpfVerify = cpfVerification(CPF);

            if (cpfVerify)
            {
                for (auto it = rentals.begin(); it != rentals.end(); ++it)
                {
                    if (it->clientData.CPF == CPF)
                    {
                        rentals.erase(it);
                        cout << "Alocação Excluída!!" << endl;
                        sleep(2);
                        return;
                    }
                }
            }
            else
            {
                cout << "CPF inválido!!!" << endl;
            }
        } while (true);
    }
    else
    {
        cout << "Placa inválido!!!" << endl;
    }
}

void updateRental(vector<Rental> &rentals, vector<Car> &cars)
{
    string carPlate;
    bool carPlateVerify;

    cout << endl;
    cout << "Digite a placa do carro: (XXX-XXX): ";
    cin.ignore();
    getline(cin, carPlate);
    carPlateVerify = plateVerification(carPlate);

    if (carPlateVerify)
    {

        for (const Rental &rental : rentals)
        {
            if (rental.carData.carPlate == carPlate)
            {
                cout << "Nome do Carro: " << rental.carData.name << endl
                     << "Renavam: " << rental.carData.renavam << endl
                     << "Placa do Carro: " << rental.carData.carPlate << endl;
                showDateCar(rental.carData.withdrawalDate, rental.carData.hourWithdrawDate);
                showDateCar(rental.carData.returnDate, rental.carData.hourReturnDate);
                cout << "Loja de Retirada: " << rental.carData.concessionaire << endl
                     << endl;
            }
            else
            {
                cout << "Carro não encontrado!!!" << endl;
            }
        }

        string CPF;
        bool cpfVerify = false;

        do
        {
            cout << endl;
            cout << "CPF do Passageiro: ";
            getline(cin, CPF);

            cpfVerify = cpfVerification(CPF);

            if (cpfVerify)
            {
                for (auto it = rentals.begin(); it != rentals.end(); ++it)
                {
                    if (it->clientData.CPF == CPF)
                    {
                        cout
                            << "Nova Data de Entrega (DD MM YYYY HH MM): ";
                        catchDateCar(it->returnRentalDate, it->hourReturnRentalDate);
                        it->carData.returnDate = it->returnRentalDate;
                        it->carData.hourReturnDate = it->hourReturnRentalDate;

                        for (auto it2 = cars.begin(); it2 != cars.end(); ++it2)
                        {
                            if (it2->carPlate == carPlate)
                            {
                                it2->returnDate = it->carData.returnDate;
                                it2->hourReturnDate = it->hourReturnRentalDate;
                            }
                        }

                        cout << "Data alterada!!!" << endl
                             << endl;
                        return;
                    }
                }
            }
            else
            {
                cout << "CPF inválido!!!" << endl;
            }
        } while (true);
    }
    else
    {
        cout << "Placa inválido!!!" << endl;
    }
}
