#ifndef BSTset_CPP
#define BSTset_CPP 1

#include <bits/stdc++.h>
#include "iterator.cpp"
using namespace std;

template<class T>

class BSTSet {
private:
    node<T>* root;
    
    void add(node<T>*& t, T data) {
        if (t == NULL) {
            t = new node<T>(data);
        } else {
            if (data < t->data) {
                add(t->pLeft, data);
            } else if (data > t->data) {
                add(t->pRight, data);
            }
        }
    }

    node<T>* remove(node<T>* t, T data) {
        if (t == NULL) return NULL;
        if (data < t->data) {
            t->pLeft = remove(t->pLeft, data);
        } else if (data > t->data) {
            t->pRight = remove(t->pRight, data);
        } else {
            // Node chỉ có cây con phải
            if (t->pLeft == NULL) { 
                node<T>* temp = t->pRight;
                delete t;
                return temp;
            // Node chỉ có cây con trái
            } else if (t->pRight == NULL) { 
                node<T>* temp = t->pLeft;
                delete t;
                return temp;
            }
            // Node có cả 2 cây con
            node<T>* temp = findMin(t->pRight); 
            t->data = temp->data;
            t->pRight = remove(t->pRight, temp->data);
        }
        return t;
    }

    node<T>* findMin(node<T>* t) const {
        while (t && t->pLeft != NULL) {
            t = t->pLeft;
        }
        return t;
    }
    
public:
    BSTSet() : root(NULL) {}

    // Thêm phần tử vào tập hợp
    void add(T data) { 
        add(root, data);
    }

    // Kiểm tra phần tử có trong tập hợp không
    bool contains(T data) const { 
        for (auto it = begin(); it != end(); ++it) {
            if (*it == data) {
                return true;
            }
        }
        return false;
    }

    // Xóa phần tử khỏi tập hợp
    void remove(T data) { 
        root = remove(root, data);
    }

    // Hiển thị tập hợp
    void display() const { 
        for (auto it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    // Cộng tập này vào tập khác
    void unionWith(const BSTSet<T>& other) { 
        for (auto it = other.begin(); it != other.end(); ++it) {
            add(*it);
        }
    }

    // Trừ tập này ra
    void subtractWith(const BSTSet<T>& other) { 
        for (auto it = other.begin(); it != other.end(); ++it) {
            remove(*it);
        }
    }

    // Trả về iterator đầu tiên
    Iterator<T> begin() const { 
        return Iterator<T>(root);
    }

    // Trả về iterator cuối cùng
    Iterator<T> end() const { 
        return Iterator<T>(NULL); // NULL để biết đã hết
    }
};

#endif