#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
struct stackNode{
	T val;
	stackNode* next;
	stackNode(T v, stackNode* n = NULL):val(v), next(n){}
};


template <class T>
class stack {
	
private:
	stackNode<T>* head;

public:
	stack();
	void push(T val);
	void pop();
	T top();
	bool isEmpty();
	~stack();

};
#include "stack.cpp"
#endif
