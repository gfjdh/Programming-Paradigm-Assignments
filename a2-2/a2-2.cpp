#include <iostream>
using namespace std;

int power(int base, int ex) // ���������ĳ˷�
{  
    int result = 1;
    for (int i = 0; i < ex; i++) 
        result *= base;
    return result;
}

int mogCount(int n) // ����ë����������
{   
    if (n % 2)
        return power(5, (n + 1) / 2) * power(4, (n - 1) / 2);
    else
        return power(5, n / 2) * power(4, n / 2);
}

int main() 
{
    int n;
    cin >> n;
    cout << mogCount(n) << endl; 
    return 0;
}