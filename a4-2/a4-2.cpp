#include <iostream>
#include <array>
#include <stdexcept>

class Matrix4x4 {
public:
    // 默认构造函数，从标准输入读取 16 个值
    Matrix4x4() {
        std::cout << "请输入 16 个浮点数来初始化矩阵（按行输入）：" << std::endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (!(std::cin >> data[i][j])) {
                    throw std::invalid_argument("输入无效，请输入一个浮点数。");
                }
            }
        }
    }

    // 构造函数，接受一个大小为 16 的数组
    Matrix4x4(const std::array<float, 16> &arr) {
        if (arr.size() != 16) {
            throw std::invalid_argument("数组大小必须为 16。");
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] = arr[i * 4 + j];
            }
        }
    }

    // 矩阵加法
    Matrix4x4 operator+(const Matrix4x4 &other) const {
        std::array<float, 16> arr = { 0 };
        Matrix4x4 result(arr);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 矩阵乘法
    Matrix4x4 operator*(const Matrix4x4 &other) const {
        std::array<float, 16> arr = { 0 };
        Matrix4x4 result(arr);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 运算符 +=
    Matrix4x4 &operator+=(const Matrix4x4 &other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // 下标函数对象，非 const 版本
    float &operator()(int row, int column) {
        if (row < 0 || row >= 4 || column < 0 || column >= 4) {
            throw std::out_of_range("下标越界，请输入有效的行和列（0-3）。");
        }
        return data[row][column];
    }

    // 下标函数对象，const 版本
    float operator()(int row, int column) const {
        if (row < 0 || row >= 4 || column < 0 || column >= 4) {
            throw std::out_of_range("下标越界，请输入有效的行和列（0-3）。");
        }
        return data[row][column];
    }

    // 打印矩阵
    void print() const {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::array<std::array<float, 4>, 4> data;
};

int main() {
    try {
        // 从标准输入创建矩阵
        Matrix4x4 matrix1;
        std::cout << "矩阵 1：" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // 使用数组创建矩阵
        std::array<float, 16> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        Matrix4x4 matrix2(arr);
        std::cout << "矩阵 2：" << std::endl;
        matrix2.print();
        std::cout << std::endl;

        // 矩阵加法
        Matrix4x4 sum = matrix1 + matrix2;
        std::cout << "矩阵 1 和矩阵 2 的和：" << std::endl;
        sum.print();
        std::cout << std::endl;

        // 矩阵乘法
        Matrix4x4 product = matrix1 * matrix2;
        std::cout << "矩阵 1 和矩阵 2 的积：" << std::endl;
        product.print();
        std::cout << std::endl;

        // 使用 += 运算符
        matrix1 += matrix2;
        std::cout << "矩阵 1 加上矩阵 2 后的结果：" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // 使用下标函数对象
        matrix1(0, 0) = 100;
        std::cout << "矩阵 1 的 (0, 0) 元素设置为 100 后的结果：" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // 尝试访问越界的下标
        std::cout << matrix1(4, 0) << std::endl; // 这会抛出异常
    }
    catch (const std::exception &e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }

    return 0;
}