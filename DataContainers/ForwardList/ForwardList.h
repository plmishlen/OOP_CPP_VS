#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//ForwardListSeparated 

#define tab "\t"
#define delimiter "\n--------------------------------------------------\n"
#define DEBAG

class Element
{
	int Data;			//значение элемента
	Element* pNext;		//pointer to next - указатель на следующий элемент
	static int count;	//объ€вление статического элемента
public:
	const Element* getpNext()const;
	int getData()const;
	//			Constructors:
	Element(int Data, Element* pNext = nullptr);
	~Element();
	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();
	//			Operators:
	Iterator& operator++();
	Iterator& operator++(int);

	bool operator==(const Iterator& other)const;
	bool operator!=(const Iterator& other)const;

	const int& operator*()const;
	int& operator*();

	Element* operator->()const;
	Element* operator->();

};

class ForwardList
{
	unsigned int size;
	Element* Head;		//указатель на начальный элемент списка
public:
	unsigned int get_size()const;
	const Element* getHead()const;
	Iterator begin();
	Iterator end();
	ForwardList();
	ForwardList(const std::initializer_list<int>& il);
	ForwardList(const ForwardList& other);
	ForwardList(ForwardList&& other);
	~ForwardList();
	//			Operators
	ForwardList& operator=(const ForwardList& other);
	ForwardList& operator=(ForwardList&& other);
	int& operator[](int index);
	//			Adding elements:
	void push_front(int Data);
	void push_back(int Data);
	void insert(int Index, int Data);
	//			Removing elements:
	void pop_front();
	void pop_back();
	//void erase();
	//			Methods:
	ForwardList operator+();
	void print()const;
};
