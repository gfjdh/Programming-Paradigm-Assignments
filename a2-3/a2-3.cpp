#include <iostream>
#include <vector>
using namespace std;

bool isLuckyNum(int num) {  // �ж�һ�������Ƿ����7�����Ƿ���7�ı���
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
    int rest = n; // ʣ����ɿ�������
    int count = 1; // ������
    int index = 0;

    while (rest > 1) {
        if (chocolates[index])
        {
            if (isLuckyNum(count))
            {
                chocolates[index] = false;// �Ե���ǰ�ɿ���
                rest--;
            }
            count++;
        }
        index = (index + 1) % n;
    }
    for (int i = 0; i < n; i++)  // �ҵ����һ��Ϊtrue������
        if (chocolates[i])
            return i + 1; // �����ɿ�����ţ���1��ʼ��
    return -1; // �����ϲ���ִ�е�����
}

int main() 
{
    int n;
    cin >> n;
    cout << findLastChocolate(n) << endl;
    return 0;
}