#pragma once

class Data {

};


template<typename T>
class Node {
public:
	Node(T data) : data(data), next(nullptr) { ; }
	Node<T> *next;
	T data;
};

template<typename T>
class LinkedList
{
public:
	void push_back(T data);
	T pop_back();
	void reset();
	LinkedList();
	~LinkedList();
private:
	Node<T>* getEnd();

	size_t count;
	Node<T>* first;
};

