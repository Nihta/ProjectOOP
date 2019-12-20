#include "Company.h"

Company::Company()
{
    this->readDataEmpCur();
    this->readDataEmpLeave();
    Employee::idCur = 10000 + this->listEmpLeave.size() + this->listEmpOfficer.size() + this->listEmpWork.size();
}

// Đọc danh sách nhân viên hiện tại của công ty từ tệp
void Company::readDataEmpCur()
{
    fstream data("./dataEmpCur.txt", ios::in);
    if (data.fail())
    {
        // Nếu mở file thất bại thì tạo một file mới
        fstream data("./dataEmpCur.txt", ios::out);
    }
    else
    {
        while (!data.eof())
        {
            string id;
            getline(data, id);

            string N;
            getline(data, N);

            string dB;
            getline(data, dB);

            string G;
            getline(data, G);

            string A;
            getline(data, A);

            string dJ;
            getline(data, dJ);

            unsigned int S;
            data >> S;
            data.ignore();

            string type;
            getline(data, type);

            if (type == "Officer")
            {
                string R;
                getline(data, R);
                Employee* temp = new Officer(N, id, Date(dB), G, A, Date(dJ), S, R);
                listEmpOfficer.push_back(temp);
            }
            else if (type == "Worker")
            {
                int P;
                data >> P;
                data.ignore();
                string dO;
                getline(data, dO);
                Employee* temp = new Worker(N, id, Date(dB), G, A, Date(dJ), S, P, dO);
                listEmpWork.push_back(temp);
            }

            // Bỏ qua dòng trống
            string tmp;
            getline(data, tmp);
        }
    }
    data.close();
}

void Company::readDataEmpLeave()
{
    // Mở file để đọc dữ liệu
    fstream data("./dataEmpLeave.txt", ios::in);
    if (data.fail())
    {
        // Nếu mở file thất bại thì tạo một file mới
        fstream data("./dataEmpLeave.txt", ios::out);
    }
    else
    {
        while (!data.eof())
        {
            string id;
            getline(data, id);

            string N;
            getline(data, N);

            string dB;
            getline(data, dB);

            string G;
            getline(data, G);

            string dL;
            getline(data, dL);

            FormerEmployee* FEtmp = new FormerEmployee(N, id, Date(dB), G, Date(dL));
            this->listEmpLeave.push_back(FEtmp);

            // Bỏ qua dòng trống
            string tmp;
            getline(data, tmp);
        }
    }
    data.close();
}

// Hiện thị danh sách các nhân viên văn phòng
void Company::displayOfficer()
{
    std::cout << string(48, '=') + " Nhan vien van phong " + string(48, '=') << endl;
    std::cout << std::setw(4) << std::right << "STT"
        << std::setw(10) << "ID"
        << std::setw(22) << "Name"
        << std::setw(12) << "Birthday"
        << std::setw(8) << "Gender"
        << std::setw(28) << "Address"
        << std::setw(12) << "DateJoin"
        << std::setw(12) << "Salary"
        << std::setw(9) << "Room"
        << "\n"
        << string(117, '-') << endl;

    for (int i = 0; i < this->listEmpOfficer.size(); i++)
    {
        std::cout << std::setw(4) << i + 1;
        this->listEmpOfficer[i]->display();
        std::cout << endl;
    }
}

// Hiện thị danh sách các công nhân sản xuất
void Company::displayWorker()
{
    std::cout << string(54, '=') + " Cong nhan san xuat " + string(54, '=') << endl;
    std::cout << std::setw(4) << std::right << "STT"
        << std::setw(10) << "ID"
        << std::setw(22) << "Name"
        << std::setw(12) << "Birthday"
        << std::setw(8) << "Gender"
        << std::setw(28) << "Address"
        << std::setw(12) << "DateJoin"
        << std::setw(12) << "Salary"
        << std::setw(10) << "Produce"
        << std::setw(10) << "DayOff"
        << "\n"
        << string(128, '-') << endl;
    for (int i = 0; i < listEmpWork.size(); i++)
    {
        std::cout << std::setw(4) << i + 1;
        listEmpWork[i]->display();
        std::cout << endl;
    }
}


void Company::displayFormerEmployee()
{
    std::cout << string(22, '=') + " Nhan vien da chuyen di " + string(22, '=') << endl;
    std::cout << std::setw(4) << std::right << "STT"
        << std::setw(10) << "ID"
        << std::setw(22) << "Name" 
        << std::setw(12) << "Birthday"
        << std::setw(8) << "Gender"
        << std::setw(12) << "DateLeave"
        << "\n"
        << std::string(68, '-') << endl;
    for (int i = 0; i < this->listEmpLeave.size(); i++)
    {
        cout << std::setw(4) << i + 1;
        this->listEmpLeave[i]->display();
    }
}

// Hiện thị thông tin nhân viên
void Company::display()
{
    std::cout << "\t[ Chon kieu ban muon hien thi ]"
        << "\n\t\t1. Hien thi tat ca nhan vien hien tai"
        << "\n\t\t2. Hien thi nhan vien van phong"
        << "\n\t\t3. Hien thi cong nhan san xuat"
        << "\n\t\t4. Hien thi nhan vien da chuyen di"
        << "\n\t\t0. Back"
        << endl;
    int option;
    do
    {
        std::cout << "\t>> ";
        std::cin >> option;
        std::cin.ignore();
        if (option == 0)
        {
            system("cls || clear");
            return;
        }
    } while (4 < option || option < 1);
    system("cls || clear");
    if (option == 1)
    {

        this->displayOfficer();
        std::cout << endl;
        this->displayWorker();
    }
    else if (option == 2)
    {
        this->displayOfficer();
    }
    else if (option == 3)
    {
        this->displayWorker();
    }
    else if (option == 4)
    {
        this->displayFormerEmployee();
    }
}
// Thêm nhân viên vào công ty
void Company::add()
{
    std::cout << "\t[ Chon nhan vien muon them vao cong ty ]"
        << "\n\t\t1. Officer"
        << "\n\t\t2. Worker"
        << "\n\t\t0. Back" << endl;

    int option;
    do
    {
        cout << "\t>> ";
        cin >> option;
        cin.ignore();
        if (option == 0)
            return;
    } while (option != 1 && option != 2);

    if (option == 1)
    {
        Employee* temp = new Officer;
        listEmpOfficer.push_back(temp);
    }
    else if (option == 2)
    {
        Employee* temp = new Worker;
        listEmpWork.push_back(temp);
    }
    this->updateFileEmpCur();
}

// Menu
void Company::menu()
{
    std::cout << "\n==================== MENU ===================="
        << "\n\t1. Them nhan vien"
        << "\n\t2. Hien thi thong tin nhan vien"
        << "\n\t9. Xoa man hinh"
        << "\n\t0. Exit"
        << std::endl;

    cout << ">> ";
    int option;
    cin >> option;
    switch (option)
    {
    case 0:
        break;
    case 1:
        this->add();
        system("cls || clear");
        this->menu();
        break;

    case 2:
        this->display();
        this->menu();
        break;

    case 9:
        system("cls || clear");
        this->menu();
        break;

    default:
        system("cls || clear");
        std::cout << "Lua chon khong hop le!" << endl;
        this->menu();
        break;
    }
}

// Hiện thị tổng số nhân viên
void Company::countEmp()
{
    std::cout << this->listEmpOfficer[0]->getCountEmp();
}

void Company::updateFileEmpCur()
{
    fstream file("./dataEmpCur.txt", ios::out);
    for (int i = 0; i < listEmpOfficer.size(); i++)
    {
        file << listEmpOfficer[i]->exportDataToString();
        file << endl;
    }
    for (int i = 0; i < listEmpWork.size(); i++)
    {
        file << listEmpWork[i]->exportDataToString();
        file << endl;
    }
    file.close();
}

void Company::updateFileEmpLeave()
{
    fstream file("./dataEmpLeave.txt", ios::out);
    for (int i = 0; i < this->listEmpLeave.size(); i++)
    {
        file << this->listEmpLeave[i]->exportDataToString();
        file << endl;
    }
    file.close();
}

Company::~Company()
{
    this->updateFileEmpLeave();
}
