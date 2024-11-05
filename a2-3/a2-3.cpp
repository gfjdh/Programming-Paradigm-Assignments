#include <iostream>
#include <vector>
using namespace std;

bool isLuckyNum(int num) {  // 判断一个数字是否包含7或者是否是7的倍数
    if (num % 7 == 0) 
        return true;
    while (num) {
        if (num % 10 == 7) 
            return true;
        num /= 10;
    }
    return false;
}

int findLastChocolate(int n) {
    vector<bool> chocolates(n, true);
    int rest = n; // 剩余的巧克力数量
    int count = 1; // 计数器
    int index = 0;

    while (rest > 1) {
        if (chocolates[index])
        {
            if (isLuckyNum(count))
            {
                chocolates[index] = false;// 吃掉当前巧克力
                rest--;
            }
            count++;
        }
        index = (index + 1) % n;
    }
    for (int i = 0; i < n; i++)  // 找到最后一个为true的索引
        if (chocolates[i])
            return i + 1; // 返回巧克力编号（从1开始）
    return -1; // 理论上不会执行到这里
}

int main() 
{
    int n;
    cin >> n;
    cout << findLastChocolate(n) << endl;
    return 0;
}