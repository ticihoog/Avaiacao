#ifndef RENTALS_H
#define RENTALS_H

#include "Common.h"
#include "Client.h"
#include "Car.h"

#include <string>
#include <vector>

using namespace std;


struct Rental
{
    char realized;
    Date withdrawalRentalDate, returnRentalDate;
    Hour hourWithdrawRentalDate, hourReturnRentalDate;
    Client clientData;
    Car carData;
};

Rental registerRental(vector<Client> &, vector<Car> &);
void rentalMenu(vector<Rental> &, vector<Car> &, vector<Client> &);
void showRentals(const vector<Rental> &);
void deleteRental(vector<Rental> &);
void updateRental(vector<Rental> &, vector<Car> &);

#endif 
