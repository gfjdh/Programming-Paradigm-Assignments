#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void modByValue(string str) {  // 通过值传递字符串的函数
    reverse(str.begin(), str.end());    // 将字符串反转
    cout << "通过值传递修改后的字符串: " << str << endl;
}

void modByRef(string &str) {   // 通过引用传递字符串的函数
    for (char &c : str) // 将字符串转换为大写
        c = toupper(c);
    cout << "通过引用传递修改后的字符串: " << str << endl;
}

int main()
{
    string originalString = "Hello, World!";
    cout << "原始字符串: " << originalString << endl;

    modByValue(originalString);
    cout << "通过值传递修改后的字符串: " << originalString << endl;

    modByRef(originalString);
    cout << "通过引用传递修改后的字符串: " << originalString << endl;
    return 0;
}