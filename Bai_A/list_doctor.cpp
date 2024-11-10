#ifndef list_doctor_CPP
#define list_doctor_CPP 1

#include <bits/stdc++.h>
#include "doctor.cpp"

using namespace std;

class doctorlist {
private:
	list<doctor> doc;
public:
	void checkDoctor(const doctor &d) {
        for (auto it = doc.begin(); it != doc.end(); ++it) {
            if (it->id == d.id && it->name == d.name && it->specialty == d.specialty && it->experience == d.experience) {
                cout << "Bac si " << d.name << " da co trong danh sach" << endl;
                return;
            }
        }
        doc.push_back(d); // Nếu không tồn tại, thêm bác sĩ vào danh sách
    }

	void addDoctor() {
		doctor newDoctor("", "", "", 0 , "");
		cin >> newDoctor;
		// doc.push_back(newDoctor);
		checkDoctor(newDoctor);
		cout << "them bac si thanh cong." << endl;
	}

	void removeDoctor(string id) {
		for (auto it = doc.begin(); it != doc.end(); ++it) {
			 if (it->id == id) { 
                doc.erase(it); 
                cout << "Xoa bac si thanh cong.\n";
                return;
			}
		}
		cout << "khong tim thay bac si voi ma: " << id << endl;
	}

	void updateDoctor(string id) {
		for (auto &it : doc) {
			if (it.id == id) {
				cout << "cap nhat thong tin bac si:\n";
				cin >> it;
				cout << "cap nhat thanh cong.\n";
				return;
			}
		}
		cout << "khong tim thay bac si voi ma: " << id << endl;
	}

	void findDoctor(string id) const {
		for (const auto &it : doc) {
			if (it.id == id){
				cout << "thong tin bac si:\n" << it;
				return;
			}
		}
		cout << "khong tim thay bac si voi ma: " << id << endl;
	}

	void sortDoctorsByExperience() {
		// sort(doc.begin(), doc.end());
		doc.sort();
		cout << "sap xep bac si theo so nam kinh nghiem thanh cong!\n";
	}

	void displayDoctors() const {
		if (doc.empty()) {
			cout << "danh sach bac si trong.\n";
		}
		else {
			cout << "+---------------+--------------------+--------------------+--------------------+--------------------+" << endl;
			cout << "| Ma bac si     | Ten bac si         | Chuyen khoa        | So nam kinh nghiem | So phong kham      |" << endl;
			cout << "+---------------+--------------------+--------------------+--------------------+--------------------+" << endl;
			for (const auto &it : doc) {
				cout << it << endl;
				cout << "+---------------+--------------------+--------------------+--------------------+--------------------+" << endl;
			}
		}
	}

	void saveFile(const string &filename) const {
		ofstream outFile(filename);
		if (!outFile) {
			cout << "khong the mo file :" << filename << endl;
			return;
		}
		for (const auto &it : doc) {
			it.writeFile(outFile);
		}
		outFile.close();
		cout << "luu danh sach bac si thanh cong vao file: " << filename << ".\n";
	} 

	void appendDoctorToFile(const string &filename) {
		ofstream outFile(filename, ios::app);
		if (!outFile) {
			cout << "khong the mo file :" << filename << endl;
			return;
		}
		for (const auto &it : doc) {
			it.writeFile(outFile);
		}
		outFile.close();
		cout << "them danh sach bac si thanh cong vao file: " << filename << ".\n";
	}
	
	void loadFile(const string &filename) {
		ifstream inFile(filename);
		if (!inFile) {
			cout << "khong the mo file :" << filename << endl;
			return;
		}
		doctor d("", "", "", 0, "");
		while (inFile.peek() != EOF) {
			d.readFile(inFile);
			checkDoctor(d);
			// doc.push_back(d);
		}
		inFile.close();
		cout << "doc danh sach bac si thanh cong tu file " << filename << ".\n";
	}
};

#endif