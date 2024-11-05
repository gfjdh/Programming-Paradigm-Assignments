#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addLargeInt(const int m, const string &a, const int n, const string &b) {
    string longStr = m < n ? b : a;
    string shortStr = m < n ? a : b;
    reverse(longStr.begin(), longStr.end());    // 反转字符串以便从最低位开始加法
    reverse(shortStr.begin(), shortStr.end());
    string result;
    int carry = 0;
    for (unsigned i = 0; i < longStr.length(); i++) {        // 逐位相加
        int a = longStr[i] - '0';
        int b = i < shortStr.length() ? shortStr[i] - '0' : 0;
        int sum = a + b + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    if (carry)
        result.push_back('1');    // 如果最后还有进位
    reverse(result.begin(), result.end());  // 反转结果字符串
    return result;
}

int main() {
    int m, n;
    string a, b;
    cin >> m >> a >> n >> b;
    cout << addLargeInt(m, a, n, b) << endl;
    return 0;
}