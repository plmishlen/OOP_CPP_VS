#include"Element.h"
#include"Element.cpp"
#include"Iterator.h"
#include"Iterator.cpp"
#include"ForwardList.h"
#include"ForwardList.cpp"

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
	cout << "¬ведите размер списка: "; cin >> n;
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
	cout << "¬ведите индекс добавл€емого элемента: ";  cin >> index;
	cout << "¬ведите добавл€емое значение: ";  cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "¬ведите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();
#endif // ADDING_ELEMENTS_CHECK   
#endif // BASE_CHECK

#ifdef COPY_METHODS_CHECK

	int n;
	cout << "¬ведите размер списка: "; cin >> n;
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
	cout << sizeof(Element<int>) << endl;
	ForwardList<int> list = { 3, 5, 8, 13, 21 };
	//range-base for(ƒиапазонный фор, фор дл€ контейнера, дл€ структуры данных)
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

	ForwardList<double> dfl = {3.14, 2.5, 2.87, 3.14, 5.9, 8.2 };
	for (double i : dfl)cout << i << tab; cout << endl;

	ForwardList<std::string> stih = { "’орошо", "живет", "на", "свете", "¬инни-ѕух" };
	for (std::string i : stih)cout << i << tab; cout << endl;
#endif // HARD_CORE;

}