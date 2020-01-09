#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"
using namespace std;


class Officer : public Employee
{
private:
    string room;

public:
    Officer();
    Officer(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s, string r);
    string getType();
    void display();
    void setRoom(string newRoom);
    string exportDataToString();
    ~Officer();
};