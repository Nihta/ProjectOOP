#pragma once
#include <sstream>
#include <iomanip>
#include "Date.h"
using namespace std;
class FormerEmployee
{
private:
    string fullName;
    string id;
    Date dateOfBirth;
    string gender;
    Date dateLeave;
public:
	FormerEmployee();
    FormerEmployee(std::string fN, std::string id, Date dB, std::string G, Date dL);
    void display();
    std::string exportDataToString();
	~FormerEmployee();
};

