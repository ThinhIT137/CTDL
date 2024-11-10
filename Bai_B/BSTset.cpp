#ifndef tree_cpp
#define tree_cpp 1
#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;
template<class T>

class BSTSet {
private:
    node<T> *root;

    // Thêm node
    void add(node<T>* &t, T data) {
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

    // Tìm kiếm node
    bool search(node<T>* t, T data) const {
        if (t == NULL) return false;
        if (data < t->data) return search(t->pLeft, data);
        else if (data > t->data) return search(t->pRight, data);
        else return true;
    }

    // Tìm node có giá trị nhỏ nhất
    node<T>* findMin(node<T>* t) {
        while (t->pLeft != NULL) {
            t = t->pLeft;
        }
        return t;
    }

    // Xóa node
    node<T>* remove(node<T>* t, T data) {
        if (t == NULL) return NULL;
        if (data < t->data) t->pLeft = remove (t->pLeft, data);
        else if (data > t->data) t->pRight = remove (t->pRight, data);
        else {
            // trường hợp 1: Node có cây con trái hoặc không có cây con
            if (t->pLeft == NULL) {
                node<T>* temp = t->pRight;
                delete t;
                return temp;
            }
            // Trường hợp 2: Node có cây con phải hoặc không có cây con
            else if (t->pRight == NULL) {
                node<T>* temp = t->pLeft;
                delete t;
                return temp;
            }
            // Trường hợp 3: Node có 2 con
            node<T>* temp = findMin(t->pRight);
            t->data = temp->data;
            t->pRight = remove(t->pRight, temp->data);
        }
        return t; // Trả về con trỏ đến gốc của cây đã cập nhật
    }

    void NLR(node<T>* t) const{
        if (t != NULL) {
            cout << t->data << " ";
            NLR(t->pLeft);
            NLR(t->pRight);
        }
    }

    void traver(node<T>* t, void (*action)(BSTSet<T>&, T), BSTSet<T>& set) const {
        if (t == NULL) return;

        traver(t->pLeft, action, set);
        action(set, t->data);
        traver(t->pRight, action, set);
    }
    
public:
    BSTSet() : root(NULL) {}
    
    // thêm phần tử vào cây
    void add(T data) {
        add(root, data);
    }

    // Xóa phần tử khỏi cây
    void remove(T data) {
        remove(root, data);
    }

    // Kiểm tra phần tử có tồn tại trong cây không
    bool contains(T data) const {
        return search(root, data);
    }

    // Hiển thị cây theo left - node - right
    void display() const {
        NLR(root);
        cout << endl;
    }

    // Giao của 2 tập hợp
    void unionWith(const BSTSet<T> &set) {
        auto it = [](BSTSet<T> &set, T data) {
           set.add(data);
        };
        traver(set.root, it, *this);
    }

    // Hiệu của 2 tập hợp
    void subtractWith(const BSTSet<T> &set) {
        auto it = [](BSTSet<T> &set, T data) {
           set.remove(data);
        };
        traver(set.root, it, *this);
    }
};

#endif