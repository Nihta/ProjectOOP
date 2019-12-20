#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date()
{
    time_t rawtime;
    time(&rawtime);
    struct tm* timeinfo;
    timeinfo = localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon;
    year = timeinfo->tm_year + 1900;
}

Date::Date(string d)
{
    stringstream ss(d);
    char tmp;
    ss >> this->day >> tmp >> this->month >> tmp >> this->year;
}

Date::~Date()
{
}

istream& operator>>(istream& is, Date& D)
{
    char tmp;
    is >> D.day >> tmp >> D.month >> tmp >> D.year;
    return is;
}

ostream& operator<<(ostream& os, const Date& D)
{
    // Sử dụng stringstream res để tránh làm hỏng std::setw()
    stringstream res;
    res << D.day << "/" << D.month << "/" << D.year;
    os << res.str();
    return os;
}