#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------\n"
#define DEBAG

class Element
{
	int Data;			//значение элемента
	Element* pNext;		//pointer to next - указатель на следующий элемент
	static int count;	//объявление статического элемента
public:
	const Element* getpNext()const
	{
		return pNext;
	}
	int getData()const
	{
		return Data;
	}

	//			Constructors:

	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);

};

int Element::count = 0;	//инициализация статической переменной

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "IConstructor:\t" << this << endl;
#endif // DEBUG	
	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "IDestructor:\t" << this << endl;
#endif DEBUG
	}

	//			Operators:
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator& operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}
	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}
	const int& operator*()const
	{
		return Temp->Data;
	}
	int& operator*()
	{
		return Temp->Data;
	}

	Element* operator->()const
	{
		return Temp;
	}
	Element* operator->()
	{
		return Temp;
	}

};

class ForwardList
{
	unsigned int size;
	Element* Head;		//указатель на начальный элемент списка
public:
	unsigned int get_size()const
	{
		return size;
	}
	const Element* getHead()const
	{
		return Head;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;	//nullptr в Head означает, что список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		//begin() - возвращает итератор на начало контейнера
		//end()   - возвращает итератор на конец контейнера
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
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstructor:" << this << endl;
	}
	ForwardList(ForwardList&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		//	pop_back();   - очень медленно выполняется задача
		cout << "LDestructor:\t" << this << endl;
	}

	//			Operators
	ForwardList& operator=(const ForwardList& other)
	{
		//0) Проверяем, не является ли список самим собой:
		if (this == &other)return *this;
		//1) Очищаем список от старых значений:
		while (Head)pop_front();
		//2) Копируем список:
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyAssignment:\t" << this << endl;
		return *this;
	}

	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssignment:\t" << this << endl;
		return *this;
	}

	int& operator[](int index)
	{
		if (index >= size)throw std::exception("Out of range");	//Бросить исключения
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
			Temp = Temp->pNext;
		return Temp->Data;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
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
	void insert(int Index, int Data)
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
	void pop_front()
	{
		if (Head == nullptr)return;
		Element* Temp = Head;	//1) Запоминаем адрес, удаляемого элемента
		Head = Head->pNext;		//2) Исключаем элемент из списка
		delete Temp;			//3) Удаляем элемент из памяти
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;	//1) Доходим до последнего элемента
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;		//2) Удаляем последний элемент
		Temp->pNext = nullptr;	//3) Говорим, что это конец списка
		size--;
	}
	/*void erase()
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
	void print()const
	{

		////Для того, чтобы ходить по списку нужны:
		////1) Итератор:
		//Element* Temp = Head;		//Temp - это итератор
		//							//Итератор - это указатель, при помощи которого можно получить доступ
		//							//к элементам структуры данных
		////2) Цикл:
		//while (Temp != nullptr)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;		//переход на следующий элемент
		//}
//		for(Start; Stop; Step).....

		
		/*for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
			
		Element* Temp = nullptr;*/
		for (Iterator Temp = Head; Temp != nullptr; ++Temp)
			cout << *Temp << tab;
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << endl;
		cout << "В списке " << size << " элементов" << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}
//#define BASE_CHECK
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
#define HARD_CORE

#ifdef BASE_CHECK
//#define ADDING_ELEMENTS_CHECK
//#define REMOVING_CHECK  
#endif // BASE_CHECK



void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	//list.print();
	cout << "List ready" << endl;

#ifdef REMOVING_CHECK
	list.pop_front();
	list.pop_back();
	list.print();
#endif // REMOVING_CHECK

	int value;
	int index;


#ifdef ADDING_ELEMENTS_CHECK    
	cout << "Введите индекс добавляемого элемента: ";  cin >> index;
	cout << "Введите добавляемое значение: ";  cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();
#endif // ADDING_ELEMENTS_CHECK   
#endif // BASE_CHECK

#ifdef COPY_METHODS_CHECK

	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	cout << delimiter << endl;

	//ForwardList list2 = list;		//CopyConstructor
	ForwardList list2;				//DefaultConstructor
	list2 = list;					//CopyAssignment
	list2.print();
	cout << delimiter << endl;

#endif COPY_METHODS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);
	cout << delimiter << endl;
	ForwardList list3;		//DefaultConstructor
	list3 = list1 + list2;
	list3.print();
	cout << delimiter << endl;
#endif OPERATOR_PLUS_CHECK

#ifdef HARD_CORE;
	int arr[] = { 3,5,8,13,21,34,55 };
	/*for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;*/
	cout << sizeof(Element) << endl;
	ForwardList list = { 3, 5, 8, 13, 21 };
	//range-base for(Диапазонный фор, фор для контейнера, для структуры данных)
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	//list.print();
	/*try
	{
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}
		for (int i = 0; i < 10; i++)
		{
			cout << list[i] << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;	//метод what() возвращает сообщение об ошибке
	}*/

#endif // HARD_CORE;

}