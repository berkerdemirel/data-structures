#include "heap.h"


template <class T>
heap<T>::heap(int size):arr(size) {
	currentSize = 0;
	capacity = size;
}


template <class T>
void heap<T>::insert(T item){
	if (isFull()) {
		capacity *= 2;
		arr.resize(capacity);
	}

	int index = ++currentSize;
	for (; index > 1 && item < arr[index / 2]; index /= 2) {
		arr[index] = arr[index / 2];
	}
	arr[index] = item;
}

template <class T>
void heap<T>::deleteMin() {
	arr[1] = arr[currentSize--];
	percolateDown(1);
}


template <class T>
void heap<T>::percolateDown(int index) {
	int child;
	T tmp = arr[index];
	for (; index * 2 <= currentSize; index = child) {
		child = index * 2;
		if (child != currentSize && arr[child + 1] < arr[child]) {
			child++;
		}
		if (arr[child] < tmp) {
			arr[index] = arr[child];
		}
		else {
			break;
		}
	}
	arr[index] = tmp;
}

template <class T>
T heap<T>::findMin() {
	return arr[1];
}

template <class T>
bool heap<T>::isFull() {
	return currentSize + 1 == capacity;
}

template <class T>
bool heap<T>::isEmpty() {
	return currentSize == 0;
}

template <class T>
void heap<T>::makeEmpty() {
	currentSize = 0;
	arr.clear();
}


template <class T>
void heap<T>::buildHeap(std::vector<T> & vec) {
	arr = std::vector<T>(vec.size()+1);
	for (int i = 1; i < arr.size(); i++) {
		arr[i] = vec[i - 1];
	}
	currentSize = vec.size();
	for (int i = currentSize / 2; i > 0; i--) {
		percolateDown(i);
	}
}
