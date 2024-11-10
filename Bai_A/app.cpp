#ifndef app_CPP
#define app_CPP 1

#include <bits/stdc++.h>
#include "list_doctor.cpp"
using namespace std;

void menu() {
    // system("cls");
    cout << "+----------------------- MENU ------------------------+" << endl;
    cout << "| 1. Them bac si                                      |" << endl;
    cout << "| 2. Xoa bac si                                       |" << endl;
    cout << "| 3. Sua thong tin bac si                             |" << endl;
    cout << "| 4. Tim kiem bac si                                  |" << endl;
    cout << "| 5. Sap xep bac si theo so nam kinh nghiem           |" << endl;
    cout << "| 6. Hien thi danh sach bac si                        |" << endl;
    cout << "| 7. Luu danh sach bac si vao file                    |" << endl;
    cout << "| 8. Ghi them danh sach bac si vao file               |" << endl;
    cout << "| 9. Doc danh sach bac si tu file                     |" << endl;
    cout << "| 0. Thoat                                            |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "-> Nhap lua chon: ";
}

class App {
private:
    doctorlist doctorList; 
public:
    void run() {
        int choice;
        do {
            menu();
            cin >> choice;
            // system("pause");
            string id;
            switch (choice) {
                case 1:
                    doctorList.addDoctor(); // Thêm bác sĩ
                    break;
                case 2:
                    cout << "Nhap ma bac si can xoa: ";
                    cin >> id;
                    doctorList.removeDoctor(id); // Xóa bác sĩ
                    break;
                case 3:
                    cout << "Nhap ma bac si can sua: ";
                    cin >> id;
                    doctorList.updateDoctor(id); // Sửa thông tin bác sĩ
                    break;
                case 4:
                    cout << "Nhap ma bac si can tim: ";
                    cin >> id;
                    doctorList.findDoctor(id); // Tìm kiếm bác sĩ
                    break;
                case 5:
                    doctorList.sortDoctorsByExperience(); // Sắp xếp theo số năm kinh nghiệm
                    break;
                case 6:
                    doctorList.displayDoctors(); // Hiển thị danh sách bác sĩ
                    break;
                case 7: {
                    string filename;
                    cout << "Nhap ten file de luu danh sach bac si: ";
                    cin >> filename;
                    doctorList.saveFile(filename); // Lưu danh sách bác sĩ vào file
                    break;
                }
                case 8: {
                    string filename;
                    cout << "nhap ten file de luu danh sach bac si: ";
                    cin >> filename;
                    doctorList.appendDoctorToFile(filename); // Ghi thêm danh sách bác sĩ vào file
                    break;
                }
                case 9: {
                    string filename;
                    cout << "Nhap ten file de doc danh sach bac si: ";
                    cin >> filename;
                    doctorList.loadFile(filename); // Đọc danh sách bác sĩ từ file
                    break;
                }
                case 0:
                    cout << "Thoat chuong trinh.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai.\n";
                    break;
            }
        } while (choice != 0);
    }
};

#endif