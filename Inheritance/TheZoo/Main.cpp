#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal() {}
	virtual void sound()const = 0;	//чисто виртуальный метод (pure-virtual function),
								//благодар€ которому класс €вл€етс€ абстрактным

};

class Cat :public Animal
{
	// это тоже абстрактный класс, т.к. не реализует чисто виртуальный метод
};

class Tiger :public Cat
{
	~Tiger() {}
	void sound()const
	{
		cout << "–рррр€у" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat() {}
	void sound()const
	{
		cout << "ћр€у" << endl;
	}
};


class Dog : public Animal
{
	~Dog() {}
	void sound()const
	{
		cout << "јв-јв" << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");

	//Animal a;
	//Cat tom;
	//Dog rex;

	//1. Generalization: 
	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};
	//2. Specialisation:
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]-> sound();
	}
}