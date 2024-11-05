#include <iostream>
#include <array>

//综合各个版本的优点，我认为最优雅的实现是使用矩阵乘法和 constexpr 结合的实现，既可以在编译时计算，又具有较高的效率。
// 矩阵乘法函数，用于 2x2 矩阵
constexpr std::array<std::array<long long, 2>, 2> my_matrix_multiply(const std::array<std::array<long long, 2>, 2> &a, const std::array<std::array<long long, 2>, 2> &b) {
    std::array<std::array<long long, 2>, 2> result = { {0} };
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}
// 编译时常量实现斐波那契数列，使用矩阵指数
// 返回第 n 个斐波那契数，在编译时计算
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
// 示例用法
int main() {
    constexpr int n = 10; // 示例输入，必须是编译时常量
    std::cout << my_fibonacci_constexpr(n) << std::endl;
}