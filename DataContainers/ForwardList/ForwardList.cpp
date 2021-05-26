#include"ForwardList.h"

template<typename T>
unsigned int ForwardList<T>::get_size()const
{
	return size;
}
template<typename T>
const Element<T>* ForwardList<T>::getHead()const
{
	return Head;
}
template<typename T>
Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template<typename T>
const Iterator<T> ForwardList<T>::begin()const
{
	return Head;
}
template<typename T>
Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}

template<typename T>
ForwardList<T>::ForwardList()
{
	this->size = 0;
	this->Head = nullptr;	//nullptr � Head ��������, ��� ������ ����
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>
ForwardList<T>::ForwardList(const std::initializer_list<T>& il) :ForwardList()
{
	//begin() - ���������� �������� �� ������ ����������
	//end()   - ���������� �������� �� ����� ����������
	cout << typeid(il.begin()).name() << endl;
	/*for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}*/
	for (T i : il)
	{
		push_back(i);
	}
	cout << "ILConstructor:\t" << this << endl;
}
template<typename T>
ForwardList<T>::ForwardList(const ForwardList<T>& other) :ForwardList()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyConstructor:" << this << endl;
}
template<typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveConstructor:\t" << this << endl;
}
template<typename T>
ForwardList<T>::~ForwardList()
{
	while (Head)pop_front();
	//	pop_back();   - ����� �������� ����������� ������
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
template<typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
	//0) ���������, �� �������� �� ������ ����� �����:
	if (this == &other)return *this;
	//1) ������� ������ �� ������ ��������:
	while (Head)pop_front();
	//2) �������� ������:
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}
template<typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssignment:\t" << this << endl;
	return *this;
}
template<typename T>
T& ForwardList<T>::operator[](int index)
{
	if (index >= size)throw std::exception("Out of range");	//������� ����������
	Element* Temp = Head;
	for (int i = 0; i < index; i++)
		Temp = Temp->pNext;
	return Temp->Data;
}

//			Adding elements:
template<typename T>
void ForwardList<T>::push_front(T Data)
{
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;*/
	Head = new Element<T>(Data, Head);
	size++;
}
template<typename T>
void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)
	{
		push_front(Data);
		return;
	}
	Element<T>* New = new Element<T>(Data);
	Element<T>* Temp = Head;
	while (Temp->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	Temp->pNext = New;
	size++;
}
template<typename T>
void ForwardList<T>::insert(int Index, int Data)
{
	if (Index > Element::count)return;
	if (Index == 0)
	{
		push_front(Data);
		return;
	}
	Element* New = new Element(Data);
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
		Temp = Temp->pNext;
	New->pNext = Temp->pNext;
	Temp->pNext = New;
	size++;
}

//			Removing elements:
template<typename T>
void ForwardList<T>::pop_front()
{
	if (Head == nullptr)return;
	Element<T>* Temp = Head;	//1) ���������� �����, ���������� ��������
	Head = Head->pNext;			//2) ��������� ������� �� ������
	delete Temp;				//3) ������� ������� �� ������
	size--;
}

template<typename T>
void ForwardList<T>::pop_back()
{
	if (Head == nullptr)return;
	if (Head->pNext == nullptr)
	{
		pop_front();
		return;
	}
	Element<T>* Temp = Head;	//1) ������� �� ���������� ��������
	while (Temp->pNext->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	delete Temp->pNext;		//2) ������� ��������� �������
	Temp->pNext = nullptr;	//3) �������, ��� ��� ����� ������
	size--;
}
/*void ForwardList<T>::erase()
{
	Element* New = new Element(Data);
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
		Temp = Temp->pNext;
	New->pNext = Temp->pNext;
	Temp->pNext = New;
	size++;
}*/

//			Methods:
template<typename T>
void ForwardList<T>::print()const
{
		////��� ����, ����� ������ �� ������ �����:
	////1) ��������:
	//Element* Temp = Head;		//Temp - ��� ��������
	//							//�������� - ��� ���������, ��� ������ �������� ����� �������� ������
	//							//� ��������� ��������� ������
	////2) ����:
	//while (Temp != nullptr)
	//{
	//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	//	Temp = Temp->pNext;		//������� �� ��������� �������
	//}
	//	for(Start; Stop; Step).....

		/*for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)

		Element* Temp = nullptr;*/
	for (Iterator Temp = Head; Temp != nullptr; ++Temp)
		cout << *Temp << tab;
	//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << endl;
	cout << "� ������ " << size << " ���������" << endl;
	cout << "����� ���������� ���������: " << Element<T>::count << endl;
}

template<typename T>
ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left;
	for (const Element<T>* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}