#include <iostream>
#include <string>
using namespace std;

bool isPal(const string &s, int left, int right) // 判断字符串 s 的子串 [left, right] 是否是回文
{
    while (left < right)                                 // 从两端向中间逐个字符比较
        if (s[left++] != s[right--]) 
            return false;
    return true;
}

bool likePal(const string &s) // 判断字符串 s 是否类似于回文（即最多可以删除一个字符使其成为回文）
{
    int left = 0, right = s.size() - 1;
    while (left < right)
        if (s[left++] != s[right--])
            return isPal(s, left, right + 1) || isPal(s, left - 1, right);      // 尝试跳过 left 或 right 指向的字符
    return true;                          // 如果整个字符串本身就是回文，或者可以通过删除一个字符变成回文，返回 true
}

int main() 
{
    string s;
    cin >> s;
    cout << boolalpha << likePal(s) << endl;    // 输出 likePal 函数的结果，boolalpha 用于输出 true/false 而不是 1/0
    return 0;
}