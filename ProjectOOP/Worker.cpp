#include "Worker.h"

Worker::Worker() : Employee::Employee()
{
    cout << "Nhap dinh muc so huong san pham: ";
    cin >> this->product;
    cin.ignore();

    if (this->gender == "Nu")
    {
        int option;
        // Nhập khác 2 -> 7 thì sẽ thành chủ nhật
        cout << "Nhap ngay nghi trong tuan (2 -> 7): ";
        cin >> option;
        switch (option)
        {
        case 2:
            this->dayOff = "Thu 2";
            break;
        case 3:
            this->dayOff = "Thu 3";
            break;
        case 4:
            this->dayOff = "Thu 4";
            break;
        case 5:
            this->dayOff = "Thu 5";
            break;
        case 6:
            this->dayOff = "Thu 6";
            break;
        case 7:
            this->dayOff = "Thu 7";
            break;
        default:
            this->dayOff = "Chu nhat";
            break;
        }
    }
    else
    {
        this->dayOff = "Chu nhat";
    }
}

Worker::Worker(string fN, string id, Date dB, string g, string a, Date dJ, unsigned int s, int p, string dO = "Chu nhat") : Employee(fN, id, dB, g, a, dJ, s)
{
    this->product = p;
    this->dayOff = dO;
}

string Worker::getType()
{
    return "Worker";
}

void Worker::display()
{
    Employee::display();
    cout << std::setw(10) << this->product
        << std::setw(10) << this->dayOff;
}

string Worker::exportDataToString()
{
    stringstream res;
    res << Employee::exportDataToString();
    res << "Worker" << endl;
    res << this->product << endl;
    res << this->dayOff << endl;
    return res.str();
}

Worker::~Worker()
{
}