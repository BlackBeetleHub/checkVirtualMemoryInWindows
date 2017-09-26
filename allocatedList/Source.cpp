#include<iostream>
#include"LinkedList.h"

int main() {
	LinkedList list;
	list.push_back(new Data("23", "23", "23", "33"));
	list.push_back(new Data("Petia", "Mira 33", "+3803040304", "3000"));
	auto tmp = list.pop_back();
	std::cout << "name: " << tmp->name << ", address: " << tmp->address << " , mob: " << tmp->mobile << " , home: " << tmp->homeMobile << std::endl;
	return 0;
}