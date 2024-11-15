#include <iostream>
#include <ctime>

// 基类
class Base {
public:
    // 虚函数
    virtual void virtualFunction() {
        // 虚函数的实现
    }

    // 非虚函数
    void nonVirtualFunction() {
        // 非虚函数的实现
    }

    virtual ~Base() = default; // 虚析构函数
};

// 派生类
class Derived : public Base {
public:
    // 重写虚函数
    void virtualFunction() override {
        // 派生类中虚函数的实现
    }
};

int main() {
    // 提示用户输入循环次数
    std::cout << "请输入循环次数（建议大于1000000）：";
    int loopCount;
    std::cin >> loopCount;

    // 输入错误处理
    if (std::cin.fail() || loopCount <= 0) {
        std::cerr << "输入错误：请输入一个正整数。" << std::endl;
        return 1;
    }

    // 创建派生类对象
    Derived derivedObj;

    // 向上转型为基类指针
    Base *basePtr = &derivedObj;

    // 测量虚函数调用的时间
    clock_t start = clock();
    for (int i = 0; i < loopCount; ++i) {
        basePtr->virtualFunction();
    }
    clock_t end = clock();
    double virtualTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // 测量非虚函数调用的时间
    start = clock();
    for (int i = 0; i < loopCount; ++i) {
        basePtr->nonVirtualFunction();
    }
    end = clock();
    double nonVirtualTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // 输出结果
    std::cout << "虚函数调用时间: " << virtualTime << " 秒" << std::endl;
    std::cout << "非虚函数调用时间: " << nonVirtualTime << " 秒" << std::endl;

    return 0;
}