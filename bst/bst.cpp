#include "bst.h"

template <class T>
bst<T>::bst() {
	root = NULL;
}



template <class T>
void bst<T>::insert(T val) {
	insert(root, val);
}
template <class T>
void bst<T>::insert(bstNode<T>* &r, T val) {
	if (!r) {
		r = new bstNode<T>(val);
		return;
	}
	val > r->val ? insert(r->right, val) : insert(r->left, val);
}



template <class T>
bstNode<T>* bst<T>::find(T val) {
	return find(root, val);
}
template <class T>
bstNode<T>* bst<T>::find(bstNode<T>* r, T val) {
	if (!r) {
		return NULL;
	}
	if (val == r->val) {
		return r;
	}
	return r->val > val ? find(r->left, val) : find(r->right, val);
}



template <class T>
bstNode<T>* bst<T>::findMax() {
	return findMax(root);
}
template <class T>
bstNode<T>* bst<T>::findMax(bstNode<T>* r) {
	if (!r) {
		return NULL;
	}
	if (!r->right) {
		return r;
	}
	return findMax(r->right);
}



template <class T>
bstNode<T>* bst<T>::findMin() {
	return findMin(root);
}
template <class T>
bstNode<T>* bst<T>::findMin(bstNode<T>* r) {
	if (!r) {
		return NULL;
	}
	if (!r->left) {
		return r;
	}
	return findMin(r->left);
}



template <class T>
bool bst<T>::exist(T val) {
	return find(root, val);
}



template <class T>
void bst<T>::del(T val) {
	del(root, val);
}
template <class T>
void bst<T>::del(bstNode<T>* r, T val) {
	if (r == NULL) { // element not found
		return;
	}
	if (val > r->val) {
		del(r->right, val);
	}
	else if (val < r->val) {
		del(r->left, val);
	}
	else if (r->left != NULL && r->right != NULL) { // if it has two children
		r->val = findMin(r->right)->val; // copy the minimum value of right subtree
		del(r->right, val); // delete min of right subtree
	}
	else { // if it has one child
		bstNode<T>* old_node = r;
		r = r->left ? r->left : r->right;
		delete old_node;
	}
}



template <class T>
T bst<T>::findMaxValue() {
	T noItem = T();
	bstNode* n = findMax(root);
	return n ? n->val : noItem;
}
template <class T>
T bst<T>::findMinValue() {
	T noItem = T();
	bstNode* n = findMin(root);
	return n ? n->val : noItem;
}



template <class T>
bst<T>::~bst() {
	deleteAll(root);
}
template <class T>
void bst<T>::deleteAll(bstNode<T>* r) {
	if (r) {
		deleteAll(r->left);
		deleteAll(r->left);
		delete r;
	}
	r = NULL;
}

template <class T>
void bst<T>::printAll() {
	printAll(root);
}

template <class T>
void bst<T>::printAll(bstNode<T>* r) {
	if (r) {
		printAll(r->left);
		cout << r->val << endl;
		printAll(r->right);
	}
}


