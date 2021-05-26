#pragma once
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------\n"
#define DEBAG

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>class Element
{
	T Data;			//значение элемента
	Element* pNext;		//pointer to next - указатель на следующий элемент
	static int count;	//объ€вление статического элемента
public:
	const Element* getpNext()const;
	T getData()const;
	//			Constructors:
	Element(T Data, Element* pNext = nullptr);
	~Element();
	friend class Iterator<T>;
	friend class ForwardList<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};