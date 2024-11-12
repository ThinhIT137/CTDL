#include <bits/stdc++.h>
#include "BSTSet.cpp" 
using namespace std;

template<class T>
void readSetFromFile(const string& filename, BSTSet<T> &set) {
    ifstream file(filename);
    if (!file) {
        cout << "Không thể mở file " << filename << endl;
        return;
    }
    T data;
    while (file >> data) {
        set.add(data);
    }
    file.close();
}

int main() {
    BSTSet<int> A, B, C;

    // Đọc dữ liệu từ file cho các tập hợp A, B và C
    readSetFromFile("A.txt", A);
    readSetFromFile("B.txt", B);
    readSetFromFile("C.txt", C);

    cout << "Tap A (NLR): ";
    A.display();


    cout << "Tap B (NLR): ";
    B.display();

    cout << "Tap C (NLR): ";
    C.display();

    // Thực hiện hợp A ∪ B
    A.unionWith(B);
    cout << "A U B: ";
    A.display();

    // Thực hiện phép hiệu A - C
    A.subtractWith(C);
    cout << "A - C: ";
    A.display();

    return 0;
}
