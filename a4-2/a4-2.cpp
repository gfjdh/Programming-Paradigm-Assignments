#include <iostream>
#include <array>
#include <stdexcept>

class Matrix4x4 {
public:
    // Ĭ�Ϲ��캯�����ӱ�׼�����ȡ 16 ��ֵ
    Matrix4x4() {
        std::cout << "������ 16 ������������ʼ�����󣨰������룩��" << std::endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (!(std::cin >> data[i][j])) {
                    throw std::invalid_argument("������Ч��������һ����������");
                }
            }
        }
    }

    // ���캯��������һ����СΪ 16 ������
    Matrix4x4(const std::array<float, 16> &arr) {
        if (arr.size() != 16) {
            throw std::invalid_argument("�����С����Ϊ 16��");
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] = arr[i * 4 + j];
            }
        }
    }

    // ����ӷ�
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

    // ����˷�
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

    // ����� +=
    Matrix4x4 &operator+=(const Matrix4x4 &other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // �±꺯�����󣬷� const �汾
    float &operator()(int row, int column) {
        if (row < 0 || row >= 4 || column < 0 || column >= 4) {
            throw std::out_of_range("�±�Խ�磬��������Ч���к��У�0-3����");
        }
        return data[row][column];
    }

    // �±꺯������const �汾
    float operator()(int row, int column) const {
        if (row < 0 || row >= 4 || column < 0 || column >= 4) {
            throw std::out_of_range("�±�Խ�磬��������Ч���к��У�0-3����");
        }
        return data[row][column];
    }

    // ��ӡ����
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
        // �ӱ�׼���봴������
        Matrix4x4 matrix1;
        std::cout << "���� 1��" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // ʹ�����鴴������
        std::array<float, 16> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        Matrix4x4 matrix2(arr);
        std::cout << "���� 2��" << std::endl;
        matrix2.print();
        std::cout << std::endl;

        // ����ӷ�
        Matrix4x4 sum = matrix1 + matrix2;
        std::cout << "���� 1 �;��� 2 �ĺͣ�" << std::endl;
        sum.print();
        std::cout << std::endl;

        // ����˷�
        Matrix4x4 product = matrix1 * matrix2;
        std::cout << "���� 1 �;��� 2 �Ļ���" << std::endl;
        product.print();
        std::cout << std::endl;

        // ʹ�� += �����
        matrix1 += matrix2;
        std::cout << "���� 1 ���Ͼ��� 2 ��Ľ����" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // ʹ���±꺯������
        matrix1(0, 0) = 100;
        std::cout << "���� 1 �� (0, 0) Ԫ������Ϊ 100 ��Ľ����" << std::endl;
        matrix1.print();
        std::cout << std::endl;

        // ���Է���Խ����±�
        std::cout << matrix1(4, 0) << std::endl; // ����׳��쳣
    }
    catch (const std::exception &e) {
        std::cerr << "����: " << e.what() << std::endl;
    }

    return 0;
}