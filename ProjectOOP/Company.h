#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Officer.h"
#include "Worker.h"
using namespace std;


class Company {
private:
    vector<Employee*> listEmpOfficer;
    vector<Employee*> listEmpWork;
    vector<Employee*> listEmpLeave;

public:
    Company();
    void readDataEmpCur();
    void displayOfficer();
    void displayWorker();
    void display();
    void add();
    void menu();
    void countEmp();
    void updateFileEmpCur();
    void updateFileEmpLeave();
    ~Company();
};