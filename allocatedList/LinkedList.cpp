#pragma once
#include "LinkedList.h"
#include "MemoryManager.h"

void LinkedList::push_back(Data *data)
{
	Node* end;
	if (first != nullptr) {
		end = getEnd();
		end->next = allocate<Node>(); //here use virtual allocate memory
		end->next->data = data;
	}
	else {
		first = allocate<Node>();
		first->data = data;
	}
}

Data* LinkedList::pop_back()
{
	Node* end = getEnd();
	Data *res = end->data;
	freeAllocatedMemory<Node>(end); //here use free virtual allocate memory
	return res;
}

void LinkedList::reset()
{
}

LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	/*Node *tmp = first;
	if (!first) {
		return;
	}
	while (tmp->next != nullptr) {
		Node *del = tmp;
		tmp = tmp->next;
		freeAllocatedMemory<Node>(del);
	}*/
}

Node* LinkedList::getEnd()
{
	if (!first) {
		return first;
	}
	Node* tmp;
	tmp = first;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	return tmp;
}

Data::Data(std::string name, std::string address,
	std::string mobile, std::string homeMobile) : name(name), address(address)
	, mobile(mobile), homeMobile(homeMobile)
{
}
