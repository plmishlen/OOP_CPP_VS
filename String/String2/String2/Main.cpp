#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	String str2 = "Hello";
	str2.print();
	cout << str2 << endl;

	String str3 = str2;	//CopyConstructor
	cout << "Str3:\t" << str3 << endl;

	String str4;
	str4 = str3;	//CopyAssignment
	cout << "Str4:\t" << str4 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_PLUS_CHECK  
	String str1 = "Hello ";
	String str2 = "World!";
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;	//оператор '+' будет выполнять конкатенацию (слияние) строк
	cout << delimiter << endl;
	cout << str3 << endl;

	String str4 = str3;
	cout << str4 << endl;
#endif // OPERATOR_PLUS_CHECK  


	/*cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;
	cout << delimiter << endl;*/
}