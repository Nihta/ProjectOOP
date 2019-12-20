#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
#pragma once

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Lấy mốc thời gian hiện tại
    Date();
    // Khởi tạo từ string
    Date(string d);
    // Nhập dạng dd/mm/yyyy
    friend istream& operator>>(istream& is, Date& D);
    // In định dạng dạng dd/mm/yyyy
    friend ostream& operator<<(ostream& os, const Date& D);
    ~Date();
};