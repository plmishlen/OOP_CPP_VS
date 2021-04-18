#include <iostream>
using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

		//	Constructors:
/*	Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
		//����������� � ����� ���������� �������� �� �������������� �����
	}
	*/
	Point(double x = 0, double y = 0)	//"=0" �������� �� ���������, ����� ����� ����� ���������
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	
	
	Point(const Point& other)
	{
		//other - ��� ������ ������
		//��� ������, ������ ����� �������� �� �������
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	double Distance (Point A, Point B)
	{
		double dist_a = A.get_x() - B.get_x();
		double dist_b = A.get_y() - B.get_y();
		double dist = sqrt(dist_a* dist_a + dist_b * dist_b);
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
		//	Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t " << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+= \t" << this << endl;
		return *this;
	}

		// Increment/Decrement
	Point& operator++()	//prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)	//postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator + " << this << endl;
		return result;
	}*/


		//	Methods

	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
	
};
//�������� ��������� ��� ����� �� ������� ����� ���� ������
//			CLASS-��� ��� ������
//			STRUCT-��� ���� ���� ������
//������� ������ ��� ���������, �������� ���������� ��������������� ����

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus: " << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	cout << "Global minus: " << endl;
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	cout << "Global multiply: " << endl;
	return Point(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);

}
Point operator/(const Point& left, const Point& right)
{
	cout << "Global divide: " << endl;
	return Point(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
	return os;
}

void function(Point* p)
{
	cout << p->get_x() << tab << p->get_y() << endl;
}
//#define INTRO
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS




void main()
{
	setlocale(LC_ALL, "");

#ifdef INTRO
	//type name;
	int a;		//��������� ���������� 'a' ���� int
	Point A;	//��������� ���������� 'A' ���� Point
				//������� ������ � ��������� Point
				//������� ��������� 'A' ��������� Point
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;

	Point* pA = &A;	//pA - pointer to 'A'
	cout << pA->get_x() << tab << pA->get_y() << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;
#endif // INTRO
#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
//A.set_x(2);
	A.print();
	//Single argument constructor
	Point B(2, 3);
	B.print();
	//cout << "���������� ����� �������: " << distance (Point A, Point B) << endl;

	Point C = 5;	//Single argument costructor
	C.print();
	Point D(8);		//Single argument costructor
	D.print();
	int b(3);		//����� ��� ���� 'int' ���������� ����������� � ����� ����������
	cout << int() << endl;	//����� ���������� ����������� �� ��������� ��� ���� 'int'
							//� ���������� �������� �� ��������� ��� ���� 'int'
							//��� ����� �������� �������� �� ��������� ��� ������ ����
	Point E{ 13 };	//Single argument costructor
	E.print();
	int c{ 8 };
	cout << c << endl;
	cout << int{} << endl;	//�������� �� ��������� ��� 'int'

	Point F = B;	//CopyConstructor
	F.print();
	Point G;		//Default constructor
	G = F;			//CopyAssignment  
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();
	A.print();
#endif // ASSIGNMENT_CHECK


	// Operators overloading	
	
#ifdef ARITHMETICAL_OPERATORS
	int a = 2;
	int b = 3;
	int c = a + b;
	cout << "����� a+b: " << c << endl;

	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B;
	C.print();
	(A - B).print();
	(A * B).print();
	(A / B).print();
#endif // ARITHMETICAL_OPERATORS

	Point A(2, 3);
	Point B(3, 4);
	Point C(4, 5);
	cout << "���������� ����� �������: " << A.distance(B, C) << endl;

	A += B;		//������� ����� ���������
	A.print();
	A.operator+=(B);	//����� ����� ���������
	A.print();
	operator/(A, B).print();	//����� ����� ����������� ���������
	++A;
	A.print();
	A++;
	A.print();
	cout << A << endl;
	Point D(4, 5);
	D.print();
}