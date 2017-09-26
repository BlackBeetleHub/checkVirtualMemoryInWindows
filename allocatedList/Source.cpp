#include<iostream>
#include"LinkedList.h"
//#include"MemoryManager.h"

int main() {
	LinkedList list;// = allocate<LinkedList<int>>();
	list.push_back(new Data("23", "23", "23", "33"));
	list.push_back(new Data("23", "23", "23", "33"));
	auto tmp = list.pop_back();
	/*list->push_back(34);
	list->push_back(22);
	std::cout << list->pop_back() << std::endl;*/
	return 0;
}