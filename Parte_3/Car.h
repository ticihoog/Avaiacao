#ifndef CAR_H
#define CAR_H

#include "Common.h"

#include <string>
#include <vector>

using namespace std;

struct Car {
    string name;
    string renavam;
    string carPlate;
    Date withdrawalDate, returnDate;
    Hour hourWithdrawDate, hourReturnDate;
    string concessionaire;
};

Car registerCar(vector<Car> &);
bool isValidDay(int , int , int );
bool isValidHour(int) ;
bool isValidMinute(int);
bool plateVerification(string);
void carMenu(vector<Car> &);
void catchDateCar(Date &, Hour &);
void showDateCar(Date, Hour);
void showCars(const vector<Car> &);
void showCar(const vector<Car> &);
void deleteCar(vector<Car> &);
void updateCar(vector<Car> &);

#endif // CAR_H
