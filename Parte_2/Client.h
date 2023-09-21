#ifndef CLIENT_H
#define CLIENT_H

#include "Common.h"

#include <string>
#include <vector>

using namespace std;

struct Client
{
    string name;
    string CPF;
    Date birthDate;
    string CNH;
};

Client registerClient(vector<Client> &customers);
void clientMenu(vector<Client> &);
bool cpfVerification(string);
void catchDateClient(Date &);
void showDateClient(Date);
void showCustomers(const vector<Client> &);
void showClient(const vector<Client> &);
void deleteClient(vector<Client> &);
void updateClient(vector<Client> &);

#endif
