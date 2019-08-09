#include "hashtable.h"


template <class T>
hashtable<T>::hashtable(T not_found, int size) {
	currentSize = 0;
	capacity = size;
	arr = new hashEntry<T>[size];
	ITEM_NOT_FOUND = not_found;
}

template <class T>
bool hashtable<T>::isActive(int index) {
	return arr[index].type == ACTIVE;
}

template <class T>
T & hashtable<T>::find(T & x) {
	int index = findPos(x);
	if (isActive(index)) {
		return arr[index].val;
	}
	return ITEM_NOT_FOUND;
}

template <class T>
void hashtable<T>::makeEmpty() {
	currentSize = 0;
	delete[] arr;
	arr = new hashEntry<T>[capacity];
}

template <class T>
hashtable<T>::~hashtable() {
	delete[] arr;
}

template <class T>
void hashtable<T>::remove(T & x) {
	int index = findPos(x);
	if (isActive(index)) {
		arr[index].type = DELETED;
	}
}

template <class T>
void hashtable<T>::insert(T & x) {
	int index = findPos(x);
	if (isActive(index)) {
		return;
	}
	arr[index] = hashEntry<T>(x, ACTIVE);
	if (++currentSize >= 0.75 * capacity) {
		rehash();
	}
}

template <class T>
void hashtable<T>::rehash() {
	cout << "Previous table size: " << capacity << ", new table size: " << capacity * 2 + 1 << ", current unique word count: " << currentSize << ", current laod factor: " << (double)currentSize / (2 * capacity + 1) << ", rehashed" << endl;
	hashEntry<T>* oldarr = arr;
	arr = new hashEntry<T>[capacity * 2 + 1];
	int oldCapacity = capacity;
	capacity = 2* capacity + 1;
	currentSize = 0;
	for (int i = 0; i < oldCapacity; i++) {
		if (oldarr[i].type == ACTIVE) {
			insert(oldarr[i].val);
		}
	}
}

template <class T>
int hashtable<T>::findPos(T & x) {
	unsigned int index = hash(x) % capacity;
	while (arr[index].type != EMPTY && arr[index].val != x) {
		index = (index + 1) % capacity;
	}
	return index;
}

template <class T>
unsigned int hashtable<T>::hash(T & x) {
	std::string word = x.word;
	int hash = 7;
	for (int i = 0; i < word.length(); i++) {
		hash = hash * 17 + (int)word[i];
	}
	return hash;
}
