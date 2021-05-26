#include"Element.h"

template<typename T>
int Element<T>::count = 0;	//������������� ����������� ����������

template<typename T>
const Element<T>* Element<T>::getpNext()const
{
	return pNext;
}

template<typename T>
T Element<T>::getData()const
{
	return Data;
}

//			Constructors:
template<typename T>
Element<T>::Element(T Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
}

template<typename T>
Element<T>::~Element()
{
	count--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}