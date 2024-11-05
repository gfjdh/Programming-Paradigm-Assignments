#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sixToDec(const string &six) {     // ���������ַ���ת��Ϊʮ��������
    int dec = 0;
    for (char ch : six) {
        int digit = ch - '0';
        dec = dec * 6 + digit;
    }
    return dec;
}

string decimalToBase(int dec, int base) {    // ��ʮ��������ת��ΪĿ����Ƶ��ַ���
    if (dec == 0) 
        return "0";
    string result;
    while (dec > 0) {
        int remainder = dec % base;
        if (remainder < 10)
            result.push_back(remainder + '0');
        else
            result.push_back(remainder - 10 + 'A');
        dec /= base;
    }
    reverse(result.begin(), result.end());  //��ת�ַ���
    return result;
}

int main() 
{
    int m;
    string k;
    cin >> m >> k;
    cout << decimalToBase(sixToDec(k), m) << endl;
    return 0;
}