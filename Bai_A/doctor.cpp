#ifndef doctor_H 
#define doctor_H 1

#include <bits/stdc++.h>
using namespace std;

class doctor {		
public:
	string id;				// Mã bác sĩ
	string name;			// Họ tên
	string specialty;		// Chuyên khoa
	int experience;			// Số năm kinh nghiệm
	string room;			// Phòng khám

	doctor(string id, string name, string specialty, int experience, string room) : id(id), name(name), specialty(specialty), experience(experience), room(room) {}

	string getID() {
		return id;
	}

	friend istream& operator>>(istream &is, doctor &doc) {
		cout << "nhap ma bac si: ";
		is >> doc.id;
		cout << "nhap ten bac si: ";
		is.ignore();
		getline(is, doc.name);
		cout << "nhap chuyen khoa: ";
		getline(is, doc.specialty);
		cout << "nhap so nam kinh nghiem: ";
		is >> doc.experience;
		cout << "nhap phong kham: ";
		is.ignore();
		getline(is, doc.room);
		return is;	
	}

	friend ostream& operator<<(ostream &os, const doctor &doc) {
		// os << "ma bac si: " << doc.id << endl;
		// os << "ten bac si: " << doc.name << endl;
		// os << "chuyen khoa: " << doc.specialty << endl;
		// os << "so nam kinh nghiem: " << doc.experience << endl;
		// os << "so phong kham: " << doc.room << endl;
		os << "| " << setw(14) << left << doc.id 
			<< "| " << setw(19) << left << doc.name 
			<< "| " << setw(19) << left << doc.specialty 
			<< "| " << setw(19) << left << doc.experience 
			<< "| " << setw(18) << left << doc.room << " |";
		return os;
	}

	bool operator<(const doctor &doc) const {
		return experience < doc.experience;
	}

	void writeFile(ofstream &out) const {
		out << id << endl;
		out << name << endl;
		out << specialty << endl;
		out << experience << endl;
		out << room << endl;
	}

	void readFile(ifstream &in) {
		getline(in, id);
		getline(in, name);
		getline(in, specialty);
		in >> experience;
		in.ignore();
		getline(in, room);
	}
};

#endif