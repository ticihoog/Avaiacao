#include "Car.h"
#include "Common.h"
#include <iostream>
#include <unistd.h>

void carMenu(vector<Car> &cars)
{
    system("clear || cls");
    int option;
    do
    {
        cout << " ----- Menu Carros ----- " << endl
             << endl
             << "1 - Incluir Carro" << endl
             << "2 - Exlcuir Carro" << endl
             << "3 - Alterar Dados Carro" << endl
             << "4 - Listar Carros" << endl
             << "5 - Localizar Carro" << endl
             << "6 - Sair" << endl
             << endl;

        cout << "Selecione a opção: ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            Car car;
            car = registerCar(cars);
            cars.push_back(car);

            cout << "Carro " << car.name << " incluído no sistema!!" << endl
                 << endl;
            sleep(2);
        }
        break;
        case 2:
        {
            if (cars.empty())
            {
                cout << "Não existe carro cadastrado!!!" << endl;
                sleep(2);
            }
            else
            {
                deleteCar(cars);
                sleep(2);
                system("clear || cls");
            }
        }
        break;
        case 3:
        {
            if (cars.empty())
            {
                cout << "Não existe carro cadastrado!!!" << endl;
                sleep(2);
            }
            else
                updateCar(cars);
        }
        break;
        case 4:
        {
            if (cars.empty())
            {
                cout << "Não existe carro cadastrado!!!" << endl;
                sleep(2);
            }
            else
                showCars(cars);
        }
        break;
        case 5:
        {
            if (cars.empty())
            {
                cout << "Não existe carro cadastrado!!!" << endl;
                sleep(2);
            }
            else
                showCar(cars);
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

bool isValidDay(int day, int month, int year)
{
    if (month == 2)
    {
        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        {
            return day >= 1 && day <= 29;
        }
        else
        {
            return day >= 1 && day <= 28;
        }
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11))
    {
        return day >= 1 && day <= 30;
    }
    else
    {
        return day >= 1 && day <= 31;
    }
}

bool isValidHour(int hour)
{
    return hour >= 0 && hour <= 23;
}

bool isValidMinute(int minute)
{
    return minute >= 0 && minute <= 59;
}

void catchDateCar(Date &date, Hour &hourDate)
{
    bool success = false;

    do
    {
        int day, month, year, hour, minute;
        cin >> day >> month >> year >> hour >> minute;

        if (month >= 1 && month <= 12)
        {
            if (isValidDay(day, month, year) && isValidHour(hour) && isValidMinute(minute))
            {
                date.day = day;
                date.month = month;
                date.year = year;
                hourDate.hour = hour;
                hourDate.minute = minute;
                success = true;
            }
            else
            {
                cout << "Valores inválidos!!! Digite novamente: ";
            }
        }
        else
        {
            cout << "Mês incorreto!!! Digite novamente: ";
        }
    } while (!success);
}

void showDateCar(Date date, Hour hourDate)
{
    cout << date.day << "/" << date.month << "/" << date.year << " às " << hourDate.hour << ":" << hourDate.minute << endl;
}

bool plateVerification(string carPlate)
{
    if (carPlate.size() == 7)
    {
        if (carPlate[3] == '-')
            return true;
        else
            return false;
    }
    else
        return false;
}

Car registerCar(vector<Car> &cars)
{
    Car car;

    cout << "Nome do carro: ";
    cin.ignore();
    getline(cin, car.name);

    do
    {
        bool success = false;
        string renavam;

        cout << "Renavam do Carro (XXXXXXXXXXX): ";
        cin >> renavam;

        if (renavam.size() == 11)
        {
            for (auto it = cars.begin(); it != cars.end(); ++it)
            {
                if (it->renavam == renavam)
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
            cout << "Renavam incorreto!! Digite novamente!!" << endl;
        }

        if (success){
            car.renavam = renavam;
            break;
        }

    } while (true);

    do
    {
        bool carPlateVerify, success = false;
        string carPlate;

        cout << "Placa do Carro (XXX-XXX): ";
        cin >> carPlate;

        carPlateVerify = plateVerification(carPlate);

        if (carPlateVerify)
        {
            for (auto it = cars.begin(); it != cars.end(); ++it)
            {
                if (it->carPlate == carPlate)
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
            cout << "Placa do carro incorreta!! Digite novamente!!" << endl;
        }
        if (success){
            car.carPlate = carPlate;
            break;
        }

    } while (true);

    car.withdrawalDate.day = 0;
    car.withdrawalDate.month = 0;
    car.withdrawalDate.year = 0;
    car.hourWithdrawDate.hour = 0;
    car.hourWithdrawDate.minute = 0;

    car.returnDate.day = 0;
    car.returnDate.month = 0;
    car.returnDate.year = 0;
    car.hourReturnDate.hour = 0;
    car.hourReturnDate.minute = 0;

    cout << "Loja de Retirada: ";
    cin >> car.concessionaire;

    cout << endl;

    return car;
}

void showCars(const vector<Car> &cars)
{
    cout << "----- Todos os Carros----- " << endl
         << endl;
    for (const Car &car : cars)
    {
        cout << "Nome do Carro: " << car.name << endl
             << "Renavam: " << car.renavam << endl
             << "Placa do Carro: " << car.carPlate << endl;
        cout << "Retirada: ";
        showDateCar(car.withdrawalDate, car.hourWithdrawDate);
        cout << "Entrega: ";
        showDateCar(car.returnDate, car.hourReturnDate);
        cout << "Loja de Retirada: " << car.concessionaire << endl
             << endl;
    }
}

void showCar(const vector<Car> &cars)
{
    string carPlate;

    cout << endl;
    cout << "Digite a placa do carro: (XXX-XXX): ";
    cin.ignore();
    getline(cin, carPlate);
    cout << endl;

    for (const Car &car : cars)
    {
        if (car.carPlate == carPlate)
        {
            cout << "Nome do Carro: " << car.name << endl
                 << "Renavam: " << car.renavam << endl
                 << "Placa do Carro: " << car.carPlate << endl;
            showDateCar(car.withdrawalDate, car.hourWithdrawDate);
            showDateCar(car.returnDate, car.hourReturnDate);
            cout << "Loja de Retirada: " << car.concessionaire << endl
                 << endl;
        }
        else
        {
            cout << "Carro não encontrado!!!" << endl;
        }
    }
}

void deleteCar(vector<Car> &cars)
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

        for (auto it = cars.begin(); it != cars.end(); ++it)
        {
            if (it->carPlate == carPlate)
            {
                cars.erase(it);
                cout << "Carro com placa " << carPlate << " excluído com sucesso!" << endl;
                return;
            }
        }
        cout << "Carro com placa " << carPlate << " não encontrado." << endl;
    }
    else
    {
        cout << "Placa inválido!!!" << endl;
    }
    sleep(2);
}

void updateCar(vector<Car> &cars)
{
    string carPlate;
    bool carPlateVerify;

    cout << endl;
    cout << "Digite a placa do carro (XXX-XXX): ";
    cin.ignore();
    getline(cin, carPlate);
    carPlateVerify = plateVerification(carPlate);

    if (carPlateVerify)
    {
        int option;

        for (auto it = cars.begin(); it != cars.end(); ++it)
        {
            if (it->carPlate == carPlate)
            {
                cout << "Nome do Carro: " << it->name << endl
                     << "Renavam: " << it->renavam << endl
                     << "Placa do Carro: " << it->carPlate << endl;
                showDateCar(it->withdrawalDate, it->hourWithdrawDate);
                showDateCar(it->returnDate, it->hourReturnDate);
                cout << "Loja de Retirada: " << it->concessionaire << endl
                     << endl;

                cout << "1 - Alterar Nome do Carro" << endl
                     << "2 - Alterar Renavam" << endl
                     << "3 - Alterar Placa do Carro" << endl
                     << "4 - Alterar Data de Retirada" << endl
                     << "5 - Alterar Data de Entrega" << endl
                     << "6 - Alterar Loja de Retirada" << endl
                     << "7 - Sair" << endl
                     << endl;
                cout << "Selecione a opção: ";
                cin >> option;

                switch (option)
                {
                case 1:
                {
                    string name;
                    cout << "Digite o novo nome para o carro: ";

                    cin.ignore();
                    getline(cin, name);

                    it->name = name;

                    cout << "Nome do carro alterado com sucesso!!!" << endl
                         << "Novo nome: " << name << endl;
                }
                break;
                case 2:
                {
                    string renavam;
                    do
                    {
                        cout << "Digite o novo renavam (XXXXXXXXXXX): ";
                        cin.ignore();
                        getline(cin, renavam);

                        if (renavam.size() == 11)
                        {
                            it->renavam = renavam;

                            cout << "Renavam do carro alterado com sucesso!!!" << endl
                                 << "Novo renavam do carro: " << renavam << endl;
                        }
                        else
                        {
                            cout << "Renavam incorreto!! Digite novamente!!" << endl;
                        }
                    } while (renavam.size() != 11);
                }
                break;
                case 3:
                {
                    bool carPlateVerify;
                    string carPlate;

                    do
                    {
                        cout << "Digite a nova placa do carro: (XXX-XXX): ";
                        cin >> carPlate;

                        carPlateVerify = plateVerification(carPlate);

                        if (carPlateVerify)
                        {

                            it->carPlate = carPlate;

                            cout << "Placa do carro alterada com sucesso!!!" << endl
                                 << "Nova placa do carro: " << carPlate << endl;
                        }
                        else
                            cout << "Placa Inválida!!!";
                    } while (carPlateVerify != true);
                }
                break;
                case 4:
                {

                    cout << "Digite a nova data de retirada (DD MM YYYY HH MM): ";
                    catchDateCar(it->withdrawalDate, it->hourWithdrawDate);

                    cout << "Data de retirada alterada com sucesso!!!" << endl
                         << "Nova data: ";
                    showDateCar(it->withdrawalDate, it->hourWithdrawDate);
                    cout << endl;
                }
                break;
                case 5:
                {

                    cout << "Digite a nova data de entrega (DD MM YYYY HH MM): ";
                    catchDateCar(it->returnDate, it->hourReturnDate);

                    cout << "Data de entrega alterada com sucesso!!!" << endl
                         << "Nova data: ";
                    showDateCar(it->returnDate, it->hourReturnDate);
                    cout << endl;
                }
                break;
                case 6:
                {
                    string concessionaire;
                    cout << "Digite a nova loja de retirada: ";
                    cin.ignore();
                    getline(cin, concessionaire);

                    it->concessionaire = concessionaire;

                    cout << "Loja de retirada alterada com sucesso!!!" << endl
                         << "Novo loja: " << concessionaire;
                    cout << endl;
                }
                break;

                default:
                    cout << "Nenhum dado alterado!!" << endl;
                    break;
                }
            }
            else
            {
                cout << "Carro não encontrado!!!" << endl;
            }
        }
    }
    else
    {
        cout << "Placa do carro inválida!!!" << endl;
    }
    sleep(2);
}