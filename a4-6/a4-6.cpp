#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// 定义Rectangle结构体
struct Rectangle {
    int x;
    int y;

    // 重载<运算符，用于比较面积
    bool operator<(const Rectangle &other) const {
        return (x * y) < (other.x * other.y);
    }

    // 重载>运算符，用于比较面积
    bool operator>(const Rectangle &other) const {
        return (x * y) > (other.x * other.y);
    }

    // 重载==运算符，用于比较面积
    bool operator==(const Rectangle &other) const {
        return (x * y) == (other.x * other.y);
    }

    // 友元函数，用于输出Rectangle
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
        os << rect.x << "," << rect.y;
        return os;
    }
};

// 泛型函数模板，用于计算最大值
template<typename T>
T max(T t1, T t2, T t3) {
    T max_val = t1;
    if (t2 > max_val) max_val = t2;
    if (t3 > max_val) max_val = t3;
    return max_val;
}

// 辅助函数，用于解析输入的Rectangle结构体
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
    // 输入提示
    std::cout << "请输入三个整数，以空格分隔：" << std::endl;
    int int1, int2, int3;
    if (!(std::cin >> int1 >> int2 >> int3)) {
        std::cerr << "输入错误，请输入有效的整数。" << std::endl;
        return 1;
    }
    std::cout << max(int1, int2, int3) << std::endl;

    // 输入提示
    std::cout << "请输入三个浮点数，以空格分隔：" << std::endl;
    double double1, double2, double3;
    if (!(std::cin >> double1 >> double2 >> double3)) {
        std::cerr << "输入错误，请输入有效的浮点数。" << std::endl;
        return 1;
    }
    std::cout << max(double1, double2, double3) << std::endl;

    // 输入提示
    std::cout << "请输入三个字符，以空格分隔：" << std::endl;
    char char1, char2, char3;
    if (!(std::cin >> char1 >> char2 >> char3)) {
        std::cerr << "输入错误，请输入有效的字符。" << std::endl;
        return 1;
    }
    std::cout << max(char1, char2, char3) << std::endl;

    // 输入提示
    std::cout << "请输入三个字符串，以回车分隔：" << std::endl;
    std::string string1, string2, string3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区
    if (!(std::getline(std::cin, string1) && std::getline(std::cin, string2) && std::getline(std::cin, string3))) {
        std::cerr << "输入错误，请输入有效的字符串。" << std::endl;
        return 1;
    }
    std::cout << max(string1, string2, string3) << std::endl;

    // 输入提示
    std::cout << "请输入三个Rectangle结构体，格式为x,y，以回车分隔：" << std::endl;
    std::string rect1_str, rect2_str, rect3_str;
    if (!(std::getline(std::cin, rect1_str) && std::getline(std::cin, rect2_str) && std::getline(std::cin, rect3_str))) {
        std::cerr << "输入错误，请输入有效的Rectangle结构体。" << std::endl;
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

    // 输入提示
    std::cout << "请输入三个Rectangle指针，格式为x,y，以回车分隔：" << std::endl;
    std::string rect_ptr1_str, rect_ptr2_str, rect_ptr3_str;
    if (!(std::getline(std::cin, rect_ptr1_str) && std::getline(std::cin, rect_ptr2_str) && std::getline(std::cin, rect_ptr3_str))) {
        std::cerr << "输入错误，请输入有效的Rectangle指针。" << std::endl;
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