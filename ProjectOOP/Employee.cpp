#include "Employee.h"

Employee::Employee()
{
    cout << "Nhap ho va ten: ";
    getline(cin, this->fullName);

    // Tự động tạo id
    this->id = to_string(++this->idCur);

    cout << "Nhap ngay sinh: ";
    cin >> this->dateOfBirth;
    cin.ignore();

    string option;
    cout << "Chon gioi tinh (1: Nam, 2: Nu): ";
    do
    {
        getline(cin, option);
    } while (option != "1" && option != "2");
    this->gender = (option == "1") ? "Nam" : "Nu";

    cout << "Nhap dia chi: ";
    getline(cin, this->address);

    string dJ;
    cout << "Nhap ngay vao cong ty (nhap 0 de chon ngay hien tai): ";
    getline(cin, dJ);
    if (dJ == "0")
    {
        this->dateJoin = Date();
    }
    else {
        this->dateJoin = Date(dJ);
    }

    cout << "Nhap luong: ";
    cin >> this->salary;
    cin.ignore();

    this->count++;
}

Employee::Employee(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s)
{
    this->fullName = fN;
    this->id = id;
    this->dateOfBirth = dB;
    this->gender = g;
    this->address = a;
    this->dateJoin = dJ;
    this->salary = s;
    this->count++;
}

int Employee::getCountEmp()
{
    return this->count;
}

std::string Employee::getId()
{
    return this->id;
}

string Employee::getName()
{
    return this->fullName;
}

void Employee::setName(string newName)
{
    this->fullName = newName;
}

void Employee::setAddress(string newAddress)
{
    this->address = newAddress;
}
unsigned int Employee::getSalary()
{
    return this->salary;
}
void Employee::setSalary(unsigned int newSalary) {
    this->salary = newSalary;
}

Date Employee::getBD()
{
    return this->dateOfBirth;
}

string Employee::getGender()
{
    return this->gender;
}

void Employee::display()
{
    cout << std::setw(10) << this->id
         << std::setw(22) << this->fullName
         << std::setw(12) << this->dateOfBirth
         << std::setw(8) << this->gender
         << std::setw(28) << (this->address.length() < 28 ? this->address : (this->address.substr(0, 24) + "..."))
         << std::setw(12) << this->dateJoin
         << std::setw(12) << std::setprecision(12) << this->salary;
}

string Employee::exportDataToString()
{
    stringstream data;
    data << id << endl;
    data << fullName << endl;
    data << dateOfBirth << endl;
    data << gender << endl;
    data << address << endl;
    data << dateJoin << endl;
    data << salary << endl;
    return data.str();
}

Employee::~Employee() {}

// Static data member
int Employee::count = 0;

unsigned int Employee::idCur = 10000;