#include <iostream>
#include <string>

// 基类 Traveler
class Traveler {
protected:
    std::string name;

public:
    // 构造函数，接受一个字符串参数
    Traveler(const std::string &n) : name(n) {
        std::cout << "Traveler 构造函数: " << name << std::endl;
    }

    // 复制构造函数
    Traveler(const Traveler &other) : name(other.name) {
        std::cout << "Traveler 复制构造函数: " << name << std::endl;
    }

    // 赋值运算符
    Traveler &operator=(const Traveler &other) {
        if (this != &other) {
            name = other.name;
            std::cout << "Traveler 赋值运算符: " << name << std::endl;
        }
        return *this;
    }

    // 析构函数
    ~Traveler() {
        std::cout << "Traveler 析构函数: " << name << std::endl;
    }
};

// 类 Pager
class Pager {
protected:
    std::string pagerId;

public:
    // 构造函数，接受一个字符串参数
    Pager(const std::string &id) : pagerId(id) {
        std::cout << "Pager 构造函数: " << pagerId << std::endl;
    }

    // 复制构造函数
    Pager(const Pager &other) : pagerId(other.pagerId) {
        std::cout << "Pager 复制构造函数: " << pagerId << std::endl;
    }

    // 赋值运算符
    Pager &operator=(const Pager &other) {
        if (this != &other) {
            pagerId = other.pagerId;
            std::cout << "Pager 赋值运算符: " << pagerId << std::endl;
        }
        return *this;
    }

    // 析构函数
    ~Pager() {
        std::cout << "Pager 析构函数: " << pagerId << std::endl;
    }
};

// 派生类 BusinessTraveler
class BusinessTraveler : public Traveler {
private:
    Pager pager;

public:
    // 默认构造函数
    BusinessTraveler() : Traveler("Default"), pager("DefaultPager") {
        std::cout << "BusinessTraveler 默认构造函数" << std::endl;
    }

    // 接受字符串参数的构造函数
    BusinessTraveler(const std::string &n) : Traveler(n), pager(n + "Pager") {
        std::cout << "BusinessTraveler 构造函数: " << name << std::endl;
    }

    // 复制构造函数
    BusinessTraveler(const BusinessTraveler &other) : Traveler(other), pager(other.pager) {
        std::cout << "BusinessTraveler 复制构造函数: " << name << std::endl;
    }

    // 赋值运算符
    BusinessTraveler &operator=(const BusinessTraveler &other) {
        if (this != &other) {
            Traveler::operator=(other);
            pager = other.pager;
            std::cout << "BusinessTraveler 赋值运算符: " << name << std::endl;
        }
        return *this;
    }

    // 析构函数
    ~BusinessTraveler() {
        std::cout << "BusinessTraveler 析构函数: " << name << std::endl;
    }
};

int main() {
    // 测试代码
    std::string input;
    std::cout << "请输入一个字符串来创建 BusinessTraveler 对象: ";
    std::cin >> input;

    if (input.empty()) {
        std::cerr << "错误：输入不能为空。" << std::endl;
        return 1;
    }

    BusinessTraveler bt1(input);
    BusinessTraveler bt2 = bt1; // 测试复制构造函数
    BusinessTraveler bt3;
    bt3 = bt1; // 测试赋值运算符

    return 0;
}