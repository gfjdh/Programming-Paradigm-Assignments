#include <iostream>
#include <array>

//�ۺϸ����汾���ŵ㣬����Ϊ�����ŵ�ʵ����ʹ�þ���˷��� constexpr ��ϵ�ʵ�֣��ȿ����ڱ���ʱ���㣬�־��нϸߵ�Ч�ʡ�
// ����˷����������� 2x2 ����
constexpr std::array<std::array<long long, 2>, 2> my_matrix_multiply(const std::array<std::array<long long, 2>, 2> &a, const std::array<std::array<long long, 2>, 2> &b) {
    std::array<std::array<long long, 2>, 2> result = { {0} };
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}
// ����ʱ����ʵ��쳲��������У�ʹ�þ���ָ��
// ���ص� n ��쳲����������ڱ���ʱ����
constexpr long long my_fibonacci_constexpr(int n) {
    if (n <= 1) return n;
    std::array<std::array<long long, 2>, 2> base = { {{1, 1}, {1, 0}} };
    std::array<std::array<long long, 2>, 2> result = { {{1, 0}, {0, 1}} };
    n--;
    while (n > 0) {
        if (n & 1) result = my_matrix_multiply(result, base);
        base = my_matrix_multiply(base, base);
        n >>= 1;
    }
    return result[0][0];
}
// ʾ���÷�
int main() {
    constexpr int n = 10; // ʾ�����룬�����Ǳ���ʱ����
    std::cout << my_fibonacci_constexpr(n) << std::endl;
}