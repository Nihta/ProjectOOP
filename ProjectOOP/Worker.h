#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Employee.h"


class Worker : public Employee
{
private:
    unsigned int product;
    string dayOff;

public:
    Worker();
    Worker(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s, int p, string dO);
    string getType();
    void display();
    string exportDataToString();
    string getGender();
    string getDayOff();
    ~Worker();
};