#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void modByValue(string str) {  // ͨ��ֵ�����ַ����ĺ���
    reverse(str.begin(), str.end());    // ���ַ�����ת
    cout << "ͨ��ֵ�����޸ĺ���ַ���: " << str << endl;
}

void modByRef(string &str) {   // ͨ�����ô����ַ����ĺ���
    for (char &c : str) // ���ַ���ת��Ϊ��д
        c = toupper(c);
    cout << "ͨ�����ô����޸ĺ���ַ���: " << str << endl;
}

int main()
{
    string originalString = "Hello, World!";
    cout << "ԭʼ�ַ���: " << originalString << endl;

    modByValue(originalString);
    cout << "ͨ��ֵ�����޸ĺ���ַ���: " << originalString << endl;

    modByRef(originalString);
    cout << "ͨ�����ô����޸ĺ���ַ���: " << originalString << endl;
    return 0;
}