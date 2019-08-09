#include "stack.h"


template <class T>
stack<T>::stack() {
	head = NULL;
}

template <class T>
stack<T>::~stack() {
	while (!isEmpty()) {
		pop();
	}
}

template <class T>
void stack<T>::push(T val) {
	stackNode<T>* node = new stackNode<T>(val, head);
	head = node;
}

template <class T>
void stack<T>::pop() {
	if (head) {
		stackNode<T>* node = head;
		head = head->next;
		delete node;
	}
}

template <class T>
T stack<T>::top() {
	if (head) {
		return head->val;
	}
}

template <class T>
bool stack<T>::isEmpty() {
	return !head;
}
