#include"String.h"
/////////////////////////////////////////////////////////////////
/////////////   CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА   /////////

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}

//			Constructors:
String::String(int size) : size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	strcpy(this->str, str);
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//strcpy(this->str, other.str);
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0) Проверить не является ли другой объект нашим объектом
	if (this == &other)return *this;
	//1) Сначала удаляем старое значение объекта
	delete[] this->str;
	//2) И только потом присваиваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int index)const
{
	return this->str[index];
}
char& String::operator[](int index)
{
	return this->str[index];
}

//			Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
	//for (int i = 0; i < size; i++)cout << (int)str[i]; cout << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////   CLASS DEFINITION END   ////////////////////
/////////////////////////////////////////////////////////////////