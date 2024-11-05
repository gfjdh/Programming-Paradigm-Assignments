#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string str1;
    string str2;
    int num;
} MyStruct;

int main() 
{
    MyStruct instance = { "Hello", "World", 42 };

    cout << "��ʼֵ:" << endl;
    cout << "str1: " << instance.str1 << endl;
    cout << "str2: " << instance.str2 << endl;
    cout << "num: " << instance.num << endl;
    cout << endl;

    MyStruct *ptr = &instance;

    ptr->str1 = "Modified";
    ptr->str2 = "String";
    ptr->num = 100;

    cout << "�޸ĺ��ֵ:" << endl;
    cout << "str1: " << ptr->str1 << endl;
    cout << "str2: " << ptr->str2 << endl;
    cout << "num: " << ptr->num << endl;

    return 0;
}