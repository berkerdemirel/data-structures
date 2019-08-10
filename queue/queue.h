#pragma once
#include <iostream>

template <class T>
struct queueNode {
	T val;
	queueNode* next;
	queueNode(T v = T(), queueNode* n= NULL): val(v), next(n){}
};

template <class T>
class queue {
private:
	queueNode<T> * front;
	queueNode<T> * rear;
	int currentSize;
public:
	queue();
	void enqueue(T val);
	void dequeue();
	T getFront();
	int getSize();
	bool isEmpty();
	~queue();
};

#include "queue.cpp"