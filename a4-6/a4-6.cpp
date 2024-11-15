#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ����Rectangle�ṹ��
struct Rectangle {
    int x;
    int y;

    // ����<����������ڱȽ����
    bool operator<(const Rectangle &other) const {
        return (x * y) < (other.x * other.y);
    }

    // ����>����������ڱȽ����
    bool operator>(const Rectangle &other) const {
        return (x * y) > (other.x * other.y);
    }

    // ����==����������ڱȽ����
    bool operator==(const Rectangle &other) const {
        return (x * y) == (other.x * other.y);
    }

    // ��Ԫ�������������Rectangle
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
        os << rect.x << "," << rect.y;
        return os;
    }
};

// ���ͺ���ģ�壬���ڼ������ֵ
template<typename T>
T max(T t1, T t2, T t3) {
    T max_val = t1;
    if (t2 > max_val) max_val = t2;
    if (t3 > max_val) max_val = t3;
    return max_val;
}

// �������������ڽ��������Rectangle�ṹ��
Rectangle parseRectangle(const std::string &input) {
    Rectangle rect;
    char comma;
    std::istringstream iss(input);
    if (!(iss >> rect.x >> comma >> rect.y) || comma != ',') {
        throw std::invalid_argument("Invalid input format for Rectangle");
    }
    return rect;
}

int main() {
    // ������ʾ
    std::cout << "�����������������Կո�ָ���" << std::endl;
    int int1, int2, int3;
    if (!(std::cin >> int1 >> int2 >> int3)) {
        std::cerr << "���������������Ч��������" << std::endl;
        return 1;
    }
    std::cout << max(int1, int2, int3) << std::endl;

    // ������ʾ
    std::cout << "�������������������Կո�ָ���" << std::endl;
    double double1, double2, double3;
    if (!(std::cin >> double1 >> double2 >> double3)) {
        std::cerr << "���������������Ч�ĸ�������" << std::endl;
        return 1;
    }
    std::cout << max(double1, double2, double3) << std::endl;

    // ������ʾ
    std::cout << "�����������ַ����Կո�ָ���" << std::endl;
    char char1, char2, char3;
    if (!(std::cin >> char1 >> char2 >> char3)) {
        std::cerr << "���������������Ч���ַ���" << std::endl;
        return 1;
    }
    std::cout << max(char1, char2, char3) << std::endl;

    // ������ʾ
    std::cout << "�����������ַ������Իس��ָ���" << std::endl;
    std::string string1, string2, string3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������
    if (!(std::getline(std::cin, string1) && std::getline(std::cin, string2) && std::getline(std::cin, string3))) {
        std::cerr << "���������������Ч���ַ�����" << std::endl;
        return 1;
    }
    std::cout << max(string1, string2, string3) << std::endl;

    // ������ʾ
    std::cout << "����������Rectangle�ṹ�壬��ʽΪx,y���Իس��ָ���" << std::endl;
    std::string rect1_str, rect2_str, rect3_str;
    if (!(std::getline(std::cin, rect1_str) && std::getline(std::cin, rect2_str) && std::getline(std::cin, rect3_str))) {
        std::cerr << "���������������Ч��Rectangle�ṹ�塣" << std::endl;
        return 1;
    }
    try {
        Rectangle rect1 = parseRectangle(rect1_str);
        Rectangle rect2 = parseRectangle(rect2_str);
        Rectangle rect3 = parseRectangle(rect3_str);
        std::cout << max(rect1, rect2, rect3) << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // ������ʾ
    std::cout << "����������Rectangleָ�룬��ʽΪx,y���Իس��ָ���" << std::endl;
    std::string rect_ptr1_str, rect_ptr2_str, rect_ptr3_str;
    if (!(std::getline(std::cin, rect_ptr1_str) && std::getline(std::cin, rect_ptr2_str) && std::getline(std::cin, rect_ptr3_str))) {
        std::cerr << "���������������Ч��Rectangleָ�롣" << std::endl;
        return 1;
    }
    try {
        Rectangle *rect_ptr1 = new Rectangle(parseRectangle(rect_ptr1_str));
        Rectangle *rect_ptr2 = new Rectangle(parseRectangle(rect_ptr2_str));
        Rectangle *rect_ptr3 = new Rectangle(parseRectangle(rect_ptr3_str));
        std::cout << max(*rect_ptr1, *rect_ptr2, *rect_ptr3) << std::endl;
        delete rect_ptr1;
        delete rect_ptr2;
        delete rect_ptr3;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}