#pragma once
#include "LinkedList.h"
#include "MemoryManager.h"

template <typename T>
void LinkedList<T>::push_back(T data)
{
	Node<T>* end = getEnd();
	end->next = allocate<Node<T>>();
	end->next->data = data;
}

template <typename T>
T LinkedList<T>::pop_back()
{
	Node<T>* end = getEnd();
	T res = end->data;
	free(end);
	return res;
}

template <typename T>
void LinkedList<T>::reset()
{
}
template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template<typename T>
Node<T>* LinkedList<T>::getEnd()
{
	Node<T>* tmp;
	tmp = first;
	while (first->next != nullptr) {
		tmp = tmp->next;
	}
	return tmp;
}
