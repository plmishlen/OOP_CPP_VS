#pragma once
#pragma once
#include<iostream>
#include<string>
#include"Iterator.h"
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------\n"
#define DEBAG

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>class ForwardList
{
	unsigned int size;
	Element<T>* Head;		//указатель на начальный элемент списка
public:
	unsigned int get_size()const;
	const Element<T>* getHead()const;
	Iterator<T> begin();
	const Iterator<T> begin()const;
	Iterator<T> end();
	const Iterator<T> end()const;
	ForwardList();
	ForwardList(const std::initializer_list<T>& il);
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other);
	~ForwardList();
	//			Operators
	ForwardList<T>& operator=(const ForwardList<T>& other);
	ForwardList<T>& operator=(ForwardList<T>&& other);
	T& operator[](int index);
	//			Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, int Data);
	//			Removing elements:
	void pop_front();
	void pop_back();
	//void erase();
	//			Methods:
	void print()const;
};