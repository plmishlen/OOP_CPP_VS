#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal() {}
	virtual void sound()const = 0;	//����� ����������� ����� (pure-virtual function),
								//��������� �������� ����� �������� �����������

};

class Cat :public Animal
{
	// ��� ���� ����������� �����, �.�. �� ��������� ����� ����������� �����
};

class Tiger :public Cat
{
	~Tiger() {}
	void sound()const
	{
		cout << "�������" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat() {}
	void sound()const
	{
		cout << "����" << endl;
	}
};


class Dog : public Animal
{
	~Dog() {}
	void sound()const
	{
		cout << "��-��" << endl;
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