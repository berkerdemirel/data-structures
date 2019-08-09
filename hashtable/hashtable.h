#pragma once
#include <string>
enum entryType { ACTIVE, EMPTY, DELETED };

template <class T>
struct hashEntry {
	T val;
	entryType type;
	hashEntry(T v = T(), entryType t = EMPTY): val(v), type(t){}
};


template <class T>
class hashtable {
public:
	hashtable(T not_found, int size=101);
	T & find(T & x);
	void makeEmpty();
	void insert(T & x);
	void remove(T & x);
	~hashtable();
	hashEntry<T>* arr;
	int currentSize;
	int capacity;

private:
	bool isActive(int index);
	T ITEM_NOT_FOUND;
	int findPos(T & x);
	unsigned int hash(T & x);
	void rehash();
};


#include "hashtable.cpp"