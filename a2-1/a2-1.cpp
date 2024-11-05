#include <iostream>
#include <string>
using namespace std;

bool isPal(const string &s, int left, int right) // �ж��ַ��� s ���Ӵ� [left, right] �Ƿ��ǻ���
{
    while (left < right)                                 // ���������м�����ַ��Ƚ�
        if (s[left++] != s[right--]) 
            return false;
    return true;
}

bool likePal(const string &s) // �ж��ַ��� s �Ƿ������ڻ��ģ���������ɾ��һ���ַ�ʹ���Ϊ���ģ�
{
    int left = 0, right = s.size() - 1;
    while (left < right)
        if (s[left++] != s[right--])
            return isPal(s, left, right + 1) || isPal(s, left - 1, right);      // �������� left �� right ָ����ַ�
    return true;                          // ��������ַ���������ǻ��ģ����߿���ͨ��ɾ��һ���ַ���ɻ��ģ����� true
}

int main() 
{
    string s;
    cin >> s;
    cout << boolalpha << likePal(s) << endl;    // ��� likePal �����Ľ����boolalpha ������� true/false ������ 1/0
    return 0;
}