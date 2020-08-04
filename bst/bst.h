#pragma once
#include <iostream>

template <class T>
struct bstNode {
	T val;
	bstNode* left;
	bstNode* right;
	bstNode(T v, bstNode* l=NULL, bstNode* r=NULL) : val(v), left(l), right(r) {}
};


template <class T>
class bst {
public:
	bst();
	void insert(T val);
	void del(T val);
	bstNode<T>* find(T val);
	bstNode<T>* findMax();
	bstNode<T>* findMin();
	T findMaxValue();
	T findMinValue();
	bool exist(T val);
	void printAll();
	~bst();

private:
	bstNode<T>* root;
	void insert(bstNode<T>*& r, T val);
	void del(bstNode<T>* &r, T val);
	void deleteAll(bstNode<T>* r);
	bstNode<T>* find(bstNode<T>* r, T val);
	bstNode<T>* findMax(bstNode<T>* r);
	bstNode<T>* findMin(bstNode<T>* r);
	void printAll(bstNode<T>* r);
};

#include "bst.cpp"