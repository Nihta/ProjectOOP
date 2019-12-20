#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Officer.h"
#include "Worker.h"
#include "FormerEmployee.h"
using namespace std;


class Company {
private:
    vector<Employee *> listEmpOfficer;
    vector<Employee *> listEmpWork;
    vector<FormerEmployee *> listEmpLeave;

public:
    Company();
    void readDataEmpCur();
    void readDataEmpLeave();
    void displayOfficer();
    void displayWorker();
    void displayFormerEmployee();
    void display();
    void add();
    void menu();
    void countEmp();
    void updateFileEmpCur();
    void updateFileEmpLeave();
    ~Company();
};