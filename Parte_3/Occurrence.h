#ifndef OCCURRENCE_H
#define OCCURRENCE_H

#include "Common.h"
#include "Rental.h"
#include "Car.h"
#include "Client.h"

#include <string>
#include <vector>

using namespace std;


struct Occurrence
{
    string description;
    string policyNumber;
    Date ocurrenceDate;
    Hour ocurrenceHour;
    Rental rentalOccurrence;
};


bool isValidPolicy(string);
Occurrence occurrenceRegistration(vector<Occurrence> &, vector<Rental> &);
void occurrenceMenu(vector<Occurrence> &, vector<Rental> &);
void listOccurrencesPerClient(const vector<Occurrence> &);
void listOccurrencesPerCar(const vector<Occurrence> &);
void deleteOccurrence(vector<Occurrence> &);
void updateOccurence(vector<Occurrence> &);

#endif 
