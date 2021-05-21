#include"ForwardList.h"

int Element::count = 0;

const Element* Element::getpNext()const
{
	return pNext;
}
int Element::getData()const
{
	return Data;
}

//			Constructors:

Element::Element(int Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
Element::~Element()
{
	count--;
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}

Iterator::Iterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "IConstructor:\t" << this << endl;
#endif // DEBUG	
}
Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "IDestructor:\t" << this << endl;
#endif DEBUG
}

//			Operators:
Iterator& Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
Iterator& Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
bool Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
bool Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
const int& Iterator::operator*()const
{
	return Temp->Data;
}
int& Iterator::operator*()
{
	return Temp->Data;
}

Element* Iterator::operator->()const
{
	return Temp;
}
Element* Iterator::operator->()
{
	return Temp;
}

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}

unsigned int ForwardList::get_size()const
{
	return size;
}
const Element* ForwardList::getHead()const
{
	return Head;
}
Iterator ForwardList::begin()
{
	return Head;
}
Iterator ForwardList::end()
{
	return nullptr;
}
ForwardList::ForwardList()
{
	this->size = 0;
	this->Head = nullptr;	//nullptr � Head ��������, ��� ������ ����
	cout << "LConstructor:\t" << this << endl;
}
ForwardList::ForwardList(const std::initializer_list<int>& il) :ForwardList()
{
	//begin() - ���������� �������� �� ������ ����������
	//end()   - ���������� �������� �� ����� ����������
	cout << typeid(il.begin()).name() << endl;
	/*for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}*/
	for (int i : il)
	{
		push_back(i);
	}
	cout << "ILConstructor:\t" << this << endl;
}
ForwardList::ForwardList(const ForwardList& other) :ForwardList()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyConstructor:" << this << endl;
}
ForwardList::ForwardList(ForwardList&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveConstructor:\t" << this << endl;
}
ForwardList::~ForwardList()
{
	while (Head)pop_front();
	//	pop_back();   - ����� �������� ����������� ������
	cout << "LDestructor:\t" << this << endl;
}

//			Operators
ForwardList& ForwardList::operator=(const ForwardList& other)
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

ForwardList& ForwardList::operator=(ForwardList&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssignment:\t" << this << endl;
	return *this;
}

int& ForwardList::operator[](int index)
{
	if (index >= size)throw std::exception("Out of range");	//������� ����������
	Element* Temp = Head;
	for (int i = 0; i < index; i++)
		Temp = Temp->pNext;
	return Temp->Data;
}

//			Adding elements:
void ForwardList::push_front(int Data)
{
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;*/
	Head = new Element(Data, Head);
	size++;
}
void ForwardList::push_back(int Data)
{
	if (Head == nullptr)
	{
		push_front(Data);
		return;
	}
	Element* New = new Element(Data);
	Element* Temp = Head;
	while (Temp->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	Temp->pNext = New;
	size++;
}
void ForwardList::insert(int Index, int Data)
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
void ForwardList::pop_front()
{
	if (Head == nullptr)return;
	Element* Temp = Head;	//1) ���������� �����, ���������� ��������
	Head = Head->pNext;		//2) ��������� ������� �� ������
	delete Temp;			//3) ������� ������� �� ������
	size--;
}
void ForwardList::pop_back()
{
	if (Head == nullptr)return;
	if (Head->pNext == nullptr)
	{
		pop_front();
		return;
	}
	Element* Temp = Head;	//1) ������� �� ���������� ��������
	while (Temp->pNext->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	delete Temp->pNext;		//2) ������� ��������� �������
	Temp->pNext = nullptr;	//3) �������, ��� ��� ����� ������
	size--;
}
/*void ForwardList::erase()
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
void ForwardList::print()const
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
//		for(Start; Stop; Step).....


		/*for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)

		Element* Temp = nullptr;*/
	for (Iterator Temp = Head; Temp != nullptr; ++Temp)
		cout << *Temp << tab;
	//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << endl;
	cout << "� ������ " << size << " ���������" << endl;
	cout << "����� ���������� ���������: " << Element::count << endl;
}

ForwardList operator+(ForwardList& left, ForwardList& right)
{
	ForwardList cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}