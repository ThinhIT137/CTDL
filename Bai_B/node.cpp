#ifndef node_h
#define node_h 1
#include <bits/stdc++.h>

using namespace std;
template<class T>

class node{
public:
	T data;
	node *pLeft; // con trỏ trái
	node *pRight; // con trỏ phải

	node(T val) : data(val), pLeft(NULL), pRight(NULL) {}
};

#endif