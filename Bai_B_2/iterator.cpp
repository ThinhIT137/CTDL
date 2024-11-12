#ifndef tree_cpp
#define tree_cpp 1

#include <bits/stdc++.h>
#include "stack.cpp"
#include "node.cpp"

using namespace std;

template<class T>

class Iterator {
private:
    Stack<node<T>*> s; // Stack để duyệt cây
public:
    Iterator(node<T>* root) {
        if (root != NULL) {
            s.push(root);
        }
    }

    // Lấy giá trị của node hiện tại
    T operator*() const{                             
        return s.top()->data;                   
    }

    // push phải trước để trái đuược duyệt trước
    Iterator& operator++() {
        node<T>* n = s.top();
        s.pop();
        if (n->pRight != NULL) {                
            s.push(n->pRight);
        }
        if (n->pLeft != NULL) {
            s.push(n->pLeft);
        }
        return *this;
    }

    // Kiểm tra xem còn duyệt tiếp không
    bool operator!=(const Iterator& other) {    
        return s.isEmpty() != other.s.isEmpty();
    }

    
};

#endif
