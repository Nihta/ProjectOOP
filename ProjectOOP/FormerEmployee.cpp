#include "FormerEmployee.h"

FormerEmployee::FormerEmployee()
{

}

FormerEmployee::FormerEmployee(string fN, string id, Date dB, string G, Date dL)
{
	this->fullName = fN;
	this->id = id;
	this->dateOfBirth = dB;
	this->gender = G;
	this->dateLeave = dL;
}
void FormerEmployee::display()
{
    std::cout << std::setw(10) << this->id
            << std::setw(22) << this->fullName
            << std::setw(12) << this->dateOfBirth
            << std::setw(8) << this->gender
            << std::setw(12) << this->dateLeave
            << std::endl;
}

std::string FormerEmployee::exportDataToString()
{
    std::stringstream res;
    res << this->id << std::endl
        << this->fullName << std::endl
        << this->dateOfBirth << std::endl
        << this->gender << std::endl
        << this->dateLeave << std::endl;
    return res.str();
}

FormerEmployee::~FormerEmployee()
{

}