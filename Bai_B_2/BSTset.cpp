#ifndef BSTset_CPP
#define BSTset_CPP 1

#include <bits/stdc++.h>
#include "iterator.cpp"
using namespace std;

template<class T>

class BSTSet {
private:
    node<T>* root; // Node gốc
    
    // Thêm phần tử vào cây mà không dùng đệ quy
    void add(node<T>*& root, T data) {
        node<T>* current = root; // Con trỏ hiện tại
        node<T>* parent = NULL; // Con trỏ cha
        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->pLeft;
            } else if (data > current->data) {
                current = current->pRight;
            } else {
                return;  // Phần tử đã có, không thêm
            }
        }
        // Thêm node mới
        if (parent == NULL) {
            root = new node<T>(data);  // Thêm vào cây nếu cây rỗng
        } else if (data < parent->data) {
            parent->pLeft = new node<T>(data);
        } else {
            parent->pRight = new node<T>(data);
        }
    }

    // Xóa phần tử khỏi cây mà không dùng đệ quy
    void remove(node<T>*& root, T data) {
        node<T>* current = root; // Con trỏ hiện tại
        node<T>* parent = NULL; // Con trỏ cha
        // Tìm node cần xóa
        while (current != NULL && current->data != data) {
            parent = current;
            if (data < current->data) {
                current = current->pLeft;
            } else {
                current = current->pRight;
            }
        }
        if (current == NULL) return; // Không tìm thấy phần tử
        // Trường hợp node có 2 con
        if (current->pLeft != NULL && current->pRight != NULL) {
            node<T>* successor = current->pRight; // Node kế tiếp
            node<T>* successorParent = current; // Cha của node kế tiếp
            while (successor->pLeft != NULL) {
                successorParent = successor;
                successor = successor->pLeft;
            }
            current->data = successor->data; // Sao chép giá trị của successor vào current
            current = successor;
            parent = successorParent;
        }
        // Trường hợp node có 1 hoặc không có con
        node<T>* child = (current->pLeft != NULL) ? current->pLeft : current->pRight;
        if (parent == NULL) {
            root = child; // Nếu node cần xóa là root
        } else if (current == parent->pLeft) {
            parent->pLeft = child;
        } else {
            parent->pRight = child;
        }
        delete current;
    }

    bool contains(T data) { // Kiểm tra phần tử có trong tập hợp không
        node<T>* current = root;
        while (current != NULL) {
            if (data < current->data) {
                current = current->pLeft;
            } else if (data > current->data) {
                current = current->pRight;
            } else {
                return true; // Tìm thấy phần tử
            }
        }
        return false; // Không tìm thấy phần tử
    }
    
public:
    BSTSet() : root(NULL) {}

    // Thêm phần tử vào tập hợp
    void add(T data) {
        if (!contains(data)) {
            add(root, data); // Thêm vào cây nếu không tồn tại
        }
    }

    // Kiểm tra phần tử có trong tập hợp không
    bool contains(node<T>* t, T data) {
        if (t == NULL) return false;
        if (data < t->data) return contains(t->pLeft, data);
        if (data > t->data) return contains(t->pRight, data);
        return true; // Nếu tìm thấy
    }

    // Xóa phần tử khỏi tập hợp
    void remove(T data) { 
        root = remove(root, data);
    }

    // Trả về iterator đầu tiên
    Iterator<T> begin() { 
        return Iterator<T>(root);
    }

    // Trả về iterator cuối cùng
    Iterator<T> end() { 
        return Iterator<T>(NULL); // NULL để biết đã hết
    }

    // Hiển thị tập hợp
    void display() { 
        for (auto it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // Cộng tập này vào tập khác
    void unionWith(BSTSet<T>& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            add(*it); // Thêm phần tử từ B vào A nếu chưa có
        }
    }

    // Trừ tập này ra
    void subtractWith(BSTSet<T>& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            remove(root, *it); // Xóa phần tử từ A nếu có trong C
        }
    }
};

#endif