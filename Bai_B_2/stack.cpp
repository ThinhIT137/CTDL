#ifndef stack_cpp
#define stack_CPP 1

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack {
private:
    T* data;         // Mảng để lưu trữ dữ liệu
    int capacity;    // Kích thước tối đa của stack
    int topIndex;    // Chỉ số phần tử đầu (top) trong stack

    void resize() {  // Tăng kích thước stack khi cần thiết
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:

    Stack(int size = 10) : capacity(size), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) { // Thêm phần tử vào stack
        if (topIndex + 1 == capacity) {
            resize();
        }
        data[++topIndex] = value;
    }

    void pop() { // Xóa phần tử đầu trong stack
        if (!isEmpty()) {
            --topIndex;
        }
    }

    T top() const { // Lấy giá trị phần tử đầu
        if (!isEmpty()) {
            return data[topIndex];
        }
        throw runtime_error("Stack is empty");
    }

    bool isEmpty() const { // Kiểm tra stack có rỗng không
        return topIndex == -1;
    }
};


#endif