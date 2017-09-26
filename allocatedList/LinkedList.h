#pragma once
#include<string>

class Data {
public:
	
	Data(std::string name, std::string address, std::string mobile, std::string homeMobile);
	std::string name;
	std::string address;
	std::string mobile;
	std::string homeMobile;
};


class Node {
public:
	Node(Data *data) : data(data), next(nullptr) { ; }
	Node* next;
	Data* data;
};

class LinkedList
{
public:
	void push_back(Data *data);
	Data* pop_back();
	void reset();
	LinkedList();
	~LinkedList();
private:
	Node* getEnd();

	size_t count;
	Node* first;
};

