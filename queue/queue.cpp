#include "queue.h"
#include <cassert>

template <class T>
queue<T>::queue() {
	front = rear = NULL;
	currentSize = 0;
}

template <class T>
void queue<T>::enqueue(T val) {
	currentSize++;
	if (!front) {
		front = rear = new queueNode<T>(val);
	}
	else {
		rear->next = new queueNode<T>(val);
		rear = rear->next;
	}
}

template <class T>
void queue<T>::dequeue() {
	assert(currentSize-- > 0);
	queueNode<T>* tmp = front;
	front = front->next;
	delete tmp;
	tmp = NULL;
}

template <class T>
T queue<T>::getFront() {
	assert(front);
	return front->val;
}

template <class T>
bool queue<T>::isEmpty() {
	return front == NULL;
}

template <class T>
int queue<T>::getSize() {
	return currentSize;
}


template <class T>
queue<T>::~queue() {
	while (!isEmpty()) {
		dequeue();
	}
}
