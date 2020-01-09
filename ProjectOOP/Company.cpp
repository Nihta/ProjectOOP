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
                Employee *temp = new Officer(N, id, Date(dB), G, A, Date(dJ), S, R);
                listEmpOfficer.push_back(temp);
            }
            else if (type == "Worker")
            {
                int P;
                data >> P;
                data.ignore();
                string dO;
                getline(data, dO);
                Employee *temp = new Worker(N, id, Date(dB), G, A, Date(dJ), S, P, dO);
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
            if (id == "")
                break;

            string N;
            getline(data, N);

            string dB;
            getline(data, dB);

            string G;
            getline(data, G);

            string dL;
            getline(data, dL);

            FormerEmployee *FEtmp = new FormerEmployee(N, id, Date(dB), G, Date(dL));
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

// Hiện thị danh sách công nhân chuyển đi
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
              << "\n\t\t5. Hien thi cong nhan nu theo ngay nghi trong tuan"
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
    } while (5 < option || option < 1);
    system("cls || clear");
    if (option == 1)
    {

        this->displayOfficer();
        std::cout << endl;
        this->displayWorker();
        this->employeeManager();
    }
    else if (option == 2)
    {
        this->displayOfficer();
        this->employeeManager();
    }
    else if (option == 3)
    {
        this->displayWorker();
        this->employeeManager();
    }
    else if (option == 4)
    {
        this->displayFormerEmployee();
    }
    else if (option == 5)
    {
        this->staticFemaleDayOff();
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

    system("cls || clear");

    if (option == 1)
    {
        Employee *temp = new Officer;
        listEmpOfficer.push_back(temp);
    }
    else if (option == 2)
    {
        Employee *temp = new Worker;
        listEmpWork.push_back(temp);
    }
    this->updateFileEmpCur();
}

// Menu
void Company::menu()
{
    std::cout << "\n==================== MENU ===================="
              << "\n\t1. Them nhan vien"
              << "\n\t2. Hien thi"
              << "\n\t3. Thong ke cong ty"
              << "\n\t4. Xoa man hinh"
              << "\n\t9. Other"
              << "\n\t0. Exit"
              << std::endl;

    cout << ">> ";
    int option;
    cin >> option;
    cin.ignore();
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

    case 3:
        system("cls || clear");
        this->statistical();
        this->menu();
        break;

    case 4:
        system("cls || clear");
        this->menu();
        break;

    case 9:
        system("cls || clear");
        this->other();
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

// Ghi danh sách nhân viên hiện tại trong công ty vào tệp
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

// Ghi danh sách các công nhân đã chuyển đi vào tệp
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

// Thống kê công ty 
void Company::statistical()
{
    cout << "Cong ty co " << this->listEmpOfficer.size() + this->listEmpWork.size() << " nhan vien (hien tai) bao gom:"
        << "\n\t+ " << this->listEmpOfficer.size() << " nhan vien van phong:"
        << "\n\t\t+ " << this->countEmp("Officer", "Nam") << " nhan vien nam"
        << "\n\t\t+ " << this->countEmp("Officer", "Nu") << " nhan vien nu"
        << "\n\t+ " << this->listEmpWork.size() << " cong nhan san xuat:"
        << "\n\t\t+ " << this->countEmp("Worker", "Nam") << " nhan vien nam"
        << "\n\t\t+ " << this->countEmp("Worker", "Nu") << " nhan vien nu"
        << "\n\t+ Tong luong phai tra moi thang: " << this->countSalary()<< " VND"
        << "\n\t+ " << this->listEmpLeave.size() << " cuu nhan vien (da roi khoi cong ty)"
        << endl;
}

// Thống kê ngày nghỉ của công nhân nữ theo ngày nghỉ trong tuần
void Company::staticFemaleDayOff()
{
    vector<string> day = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu nhat"};
    std::cout << string(50, '=') + " Ngay nghi cua cong nhan nu " + string(50, '=') << endl;
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
    int stt = 1;
    for (int j = 0; j < day.size(); j++)
    {
        for (int i = 0; i < this->listEmpWork.size(); i++)
        {
            if (((Worker *)this->listEmpWork[i])->getGender() == "Nu")
            {
                if (((Worker *)this->listEmpWork[i])->getDayOff() == day[j])
                {
                    std::cout << std::setw(4) << stt++;
                    this->listEmpWork[i]->display();
                    std::cout << endl;
                }
            }
        }
    }
}

// Tính tổng lương phải trả
unsigned long long int Company::countSalary()
{
    unsigned long long int res = 0;

    for (auto& emp : this->listEmpOfficer)
    {
        res += emp->getSalary();
    }

    for (auto& emp : this->listEmpWork)
    {
        res += emp->getSalary();
    }

    return res;
}

// Đếm sô lượng công nhân theo loại và giới tính
unsigned int Company::countEmp(string type, string gender) {
    int res = 0;
    if (type == "Officer")
    {
        for (auto& emp : this->listEmpOfficer)
            if (emp->getGender() == gender)
                res++;
    }
    if (type == "Worker")
    {
        for (auto& emp : this->listEmpWork)
            if (emp->getGender() == gender)
                res++;
    }
    return res;
}

// Các thao tác với nhân viên
void Company::employeeManager()
{
    std::cout << "\n[ Chon mot chuc nang ]"
              << "\n\t1. Xoa nhan vien theo id"
              << "\n\t2. Sua thong tin nhan vien theo id"
              << "\n\t0. Menu" << endl;

    int option;
    do
    {
        cout << "\t>> ";
        cin >> option;
        cin.ignore();
        if (option == 0)
        {
            system("cls || clear");
            return;
        }
    } while (option != 1 && option != 2);

    // Xóa nhân viên
    if (option == 1)
    {
        cout << "\t\tNhap id nhan vien can xoa: ";
        std::string idEmpDel;
        std::getline(cin, idEmpDel);
        bool isDel = false;

        for (int i = 0; i < this->listEmpOfficer.size(); i++)
        {
            if (this->listEmpOfficer[i]->getId() == idEmpDel)
            {
                FormerEmployee *tmpFE = new FormerEmployee(
                    this->listEmpOfficer[i]->getName(),
                    this->listEmpOfficer[i]->getId(),
                    this->listEmpOfficer[i]->getBD(),
                    this->listEmpOfficer[i]->getGender(),
                    Date());
                this->listEmpLeave.push_back(tmpFE);
                this->listEmpOfficer.erase(this->listEmpOfficer.begin() + i);
                this->updateFileEmpCur();
                this->updateFileEmpLeave();
                isDel = true;
            }
        }

        if (!isDel)
        {
            for (int i = 0; i < this->listEmpWork.size(); i++)
            {
                if (this->listEmpWork[i]->getId() == idEmpDel)
                {
                    FormerEmployee *tmpFE = new FormerEmployee(
                        this->listEmpWork[i]->getName(),
                        this->listEmpWork[i]->getId(),
                        this->listEmpWork[i]->getBD(),
                        this->listEmpWork[i]->getGender(),
                        Date());
                    this->listEmpLeave.push_back(tmpFE);
                    this->listEmpWork.erase(this->listEmpWork.begin() + i);
                    this->updateFileEmpCur();
                    this->updateFileEmpLeave();
                    isDel = true;
                }
            }
        }

        if (isDel)
        {
            system("cls || clear");
            cout << "Xoa thanh cong nhan vien!" << endl;
        }
        else
        {
            cout << "Khong co nhan vien nao co id la " << idEmpDel << "!" << endl;
        }
    }
    else if (option == 2)
    {
        cout << "\t\tNhap id nhan vien can sua: ";
        std::string idEmpDel;
        std::getline(cin, idEmpDel);
        bool isExist = false;

        for (int i = 0; i < this->listEmpOfficer.size(); i++)
        {
            if (this->listEmpOfficer[i]->getId() == idEmpDel)
            {
                this->editInfoEmp(this->listEmpOfficer[i]);
                isExist = true;
            }
        }

        if (!isExist)
        {
            for (int i = 0; i < this->listEmpWork.size(); i++)
            {
                if (this->listEmpWork[i]->getId() == idEmpDel)
                {
                    this->editInfoEmp(this->listEmpWork[i]);
                    isExist = true;
                }
            }
        }

        if (!isExist)
        {
            cout << "Khong co nhan vien nao co id la " << idEmpDel << "!" << endl;
        }
    }
}

// Sửa thông tin nhân viên
void Company::editInfoEmp(Employee* emp) {
    while (true)
    {
        system("cls");
        // Hiện thị thông tin nhân viên đang chọn để sửa
        if (emp->getType() == "Officer")
        {
            std::cout << std::right
                << std::setw(10) << "ID"
                << std::setw(22) << "Name"
                << std::setw(12) << "Birthday"
                << std::setw(8) << "Gender"
                << std::setw(28) << "Address"
                << std::setw(12) << "DateJoin"
                << std::setw(12) << "Salary"
                << std::setw(9) << "Room"
                << "\n"
                << string(113, '-') << endl;
        }
        else if (emp->getType() == "Worker")
        {
            std::cout << std::right
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
                << string(124, '-') << endl;
        }
        emp->display();

        std::cout << "\n[ Chon muc can su doi ]"
            << "\n\t1. Sua ten"
            << "\n\t2. Sua dia chi"
            << "\n\t3. Sua luong";

        if (emp->getType() == "Officer")
        {
            cout << "\n\t4. Sua phong lam viec";
        }
        else if (emp->getType() == "Worker")
        {
            cout << "\n\t4. Sua dinh muc san pham";
            if (emp->getGender() == "Nu")
            {
                cout << "\n\t5. Sua ngay nghi";
            }
        }
       std::cout << "\n\t0. Thoat" << endl;

        int option;
        cout << "\t>> ";
        cin >> option;
        cin.ignore();

        if (option == 0)
        {
            system("cls");
            return;
        }
        else if (option == 1)
        {
            cout << "\t\tNhap ten moi: ";
            string newData;
            getline(cin, newData);
            emp->setName(newData);
        }
        else if (option == 2)
        {
            cout << "\t\tNhap dia chi moi: ";
            string newData;
            getline(cin, newData);
            emp->setAddress(newData);
        }
        else if (option == 3)
        {
            cout << "\t\tNhap muc luong moi: ";
            unsigned int newData;
            cin >> newData;
            cin.ignore();
            emp->setSalary(newData);
        }

        if (emp->getType() == "Officer" && option == 4)
        {
            cout << "\t\tNhap phong lam viec moi: ";
            string newData;
            getline(cin, newData);
            ((Officer*) emp)->setRoom(newData);
        }

        if (emp->getType() == "Worker")
        {
            if (option == 4)
            {
                cout << "\t\tNhap dinh muc san pham moi: ";
                unsigned int newData;
                cin >> newData;
                cin.ignore();
                ((Worker*)emp)->setProduct(newData);
            }
            else if (option == 5 && emp->getGender() == "Nu")
            {
                string newDayOff;
                int doff;
                // Nhập khác 2 -> 7 thì sẽ thành chủ nhật
                cout << "\t\tChon ngay nghi trong tuan (2 -> 8): ";
                cin >> doff;
                cin.ignore();
                switch (doff)
                {
                case 2:
                    newDayOff = "Thu 2";
                    break;
                case 3:
                    newDayOff = "Thu 3";
                    break;
                case 4:
                    newDayOff = "Thu 4";
                    break;
                case 5:
                    newDayOff = "Thu 5";
                    break;
                case 6:
                    newDayOff = "Thu 6";
                    break;
                case 7:
                    newDayOff = "Thu 7";
                    break;
                default:
                    newDayOff = "Chu nhat";
                    break;
                }
                ((Worker*)emp)->setDayoff(newDayOff);
            }
        }
        this->updateFileEmpCur();
    }
}

void Company::other()
{
    std::cout << "cat ec: Xem file luu nhan vien"
        << "\ncat el: Xem file luu nhan vien chuyen di"
        << "\ndelete all: Xoa toan bo du lieu cong ty\n>> ";
    std::string cmd;
    std::getline(cin, cmd);

    if (cmd == "cat ec")
    {
        system("cls");
        system("powershell cat ./dataEmpCur.txt");
    }
    else if (cmd == "cat el")
    {
        system("cls");
        system("powershell cat ./dataEmpLeave.txt");
    }
    else if (cmd == "delete all")
    {
        this->listEmpOfficer.clear();
        this->listEmpWork.clear();
        this->listEmpLeave.clear();
        cout << "Ban co the huy xoa bang cac nhan [X] tat chuong trinh" << endl;
    }
}

Company::~Company()
{
    this->updateFileEmpCur();
    this->updateFileEmpLeave();
}
