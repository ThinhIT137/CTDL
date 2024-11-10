#include<bits/stdc++.h>
#include "BSTset.cpp"
using namespace std;

template<class T>
void readSetFromFile(const string& filename, BSTSet<T> &set) {
    ifstream file(filename);
    if (!file) {
        cout << "Khong the mo file " << filename << endl;
        return;
    }
    T data;
    while (file >> data) {
        set.add(data);
    }
    file.close();
}

int main(){
    BSTSet<int> A, B, C;

    readSetFromFile("A.txt", A);
    readSetFromFile("B.txt", B);
    readSetFromFile("C.txt", C);

    cout << "A: ";
    A.display();

    cout << "B: ";
    B.display();
    
    cout << "C: ";
    C.display();

    A.unionWith(B);
    cout << "A U B: ";
    A.display();

    A.subtractWith(C);
    cout << "A - C: ";
    A.display();

    return 0;
}