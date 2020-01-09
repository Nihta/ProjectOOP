#include <iostream>
#include <iomanip>
#include <fstream>
#include "Date.h"
using namespace std;
#pragma once

class Employee
{
protected:
    string fullName;
    string id;
    Date dateOfBirth;
    string gender;
    string address;
    Date dateJoin;
    unsigned int salary;
    static int count;

public:
    static unsigned int idCur;
    Employee();
    Employee(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s);
    int getCountEmp();
    string getId();
    string getName();
    void setName(string newName);
    void setAddress(string newAddress);
    unsigned int getSalary();
    void setSalary(unsigned int newSalary);
    Date getBD();
    string getGender();
    virtual string getType() = 0;
    virtual void display();
    virtual string exportDataToString();
    ~Employee();
};