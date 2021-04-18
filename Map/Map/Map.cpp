#include <iostream>
#include <string>
#include <map>
#include<set>
using std::cin;
using std::cout;
using std::endl;

int main()
{


//#define MAP
#define SET

#ifdef MAP
    map <string, list<string>> dictionary =
    {
        pair<string, list<string>>("space", {"космос", "пробел"}),
        pair<string, list<string>>("merry", {"веселый", "свадьба"}),
        pair<string, list<string>>("driver", {"водитель", "машинист"}),
        pair<string, list<string>>("current", {"поток","течение"}),
        pair<string, list<string>>("fire", {"огонь", "пожар"})
    };
    for (map<string, list<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
    {
        cout << it->first << ":";
        cout.wight(15);
        for (list<string>::iterator value = it->second.begin(); value != it->second.end(); value++)
            cout << *value << ", ";
        cout << "\b\b;\n";
    }
#endif // MAP
#ifdef SET
    std::set<int> numbers;
    for (int i = 0; i < 5; i++)
    {
        numbers.insert(rand() % 100);
    }
    /*for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << tab;
    }*/
    cout << endl;
    cout << "size: " << numbers.size() << endl;
#endif SET



}