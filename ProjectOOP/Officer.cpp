#include "Officer.h"

Officer::Officer() : Employee()
{
    cout << "Nhap phong lam viec: ";
    getline(cin, this->room);
}

Officer::Officer(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s, string r) : Employee(fN, id, dB, g, a, dJ, s)
{
    this->room = r;
}

string Officer::getType()
{
    return "Officer";
}

void Officer::display()
{
    Employee::display();
    cout << std::setw(9) << this->room;
}

string Officer::exportDataToString()
{
    stringstream res;
    res << Employee::exportDataToString();
    res << "Officer" << endl;
    res << this->room << endl;
    return res.str();
}

Officer::~Officer()
{
}