#pragma once
#include<iostream>
#include<string>
#include"Element.h"
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"
#define delimiter "\n--------------------------------------------------\n"
#define DEBAG

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();

	//			Operators:
	Iterator<T>& operator++();
	Iterator<T>& operator++(int);
	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;
	const T& operator*()const;
	T& operator*();
	Element<T>* operator->()const;
	Element<T>* operator->();
};
