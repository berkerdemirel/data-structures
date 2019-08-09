#pragma once

#include <vector>

template <class T>
class heap {

private:
	std::vector<T> arr;
	int currentSize;
	int capacity;
	void percolateDown(int index);

public:
	heap(int s=101);
	void deleteMin();
	T findMin();
	void insert(T item);
	void makeEmpty();
	bool isFull();
	bool isEmpty();
	void buildHeap(std::vector<T> & vec);
};

#include "heap.cpp"