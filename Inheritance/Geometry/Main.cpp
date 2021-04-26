#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Shape
{
	string color;
public:
	Shape(const string color)
	{
		this->color = color;
	}
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side > 0)this->side = side;
		else this->side = 1;
	}
	explicit Square(double side, const string& color = "white") :Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double area()const
	{
		return side * side;
	}
	double perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Rectangle :public Shape
{
	double side1;
	double side2;
public:
	double get_side1()const
	{
		return side1;
	}
	double get_side2()const
	{
		return side2;
	}
	void set_side1(double side1)
	{
		if (side1 > 0)this->side1 = side1;
		else this->side1 = 1;
	}
	void set_side2(double side2)
	{
		if (side2 > 0)this->side2 = side2;
		else this->side2 = 1;
	}
	explicit Rectangle(double side1, double side2, const string& color = "white") :Shape(color)
	{
		set_side1(side1);
		set_side2(side2);
	}
	~Rectangle()
	{

	}
	double area()const
	{
		return side1 * side2;
	}
	double perimeter()const
	{
		return side1 * 2 + side2 * 2;
	}
	void draw()const
	{
		for (int i = 0; i < side1; i++)
		{
			for (int j = 0; j < side2; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	//Shape shap;
	Square square(5);
	cout << "Площадь квадрата: " << square.area() << endl;
	cout << "Периметр квадрата: " << square.perimeter() << endl;
	square.draw();
	Rectangle rect(4, 3);
	cout << "Площадь прямоугольника: " << rect.area() << endl;
	cout << "Периметр прямоугольника: " << rect.perimeter() << endl;
	rect.draw();

}