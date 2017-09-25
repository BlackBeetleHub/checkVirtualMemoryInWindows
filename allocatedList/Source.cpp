#include<iostream>
#include"LinkedList.h"
#include"MemoryManager.h"

int main() {
	LinkedList<int> *list = allocate<LinkedList<int>>();
	list->push_back(34);
	list->push_back(22);
	std::cout << list->pop_back() << std::endl;
	return 0;
}