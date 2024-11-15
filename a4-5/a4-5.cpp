#include <iostream>
#include <memory>

// 基类
class Base {
public:
    virtual ~Base() = default;

    // 纯虚函数，要求派生类必须实现 clone()
    virtual std::unique_ptr<Base> clone() const = 0;

    // 虚函数，用于测试克隆对象的类型
    virtual void identify() const {
        std::cout << "基类" << std::endl;
    }
};

// 派生类1
class Derived1 : public Base {
public:
    // 重写 clone() 函数，返回 Derived1 类型的副本
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived1>(*this);
    }

    // 重写 identify() 函数，用于测试克隆对象的类型
    void identify() const override {
        std::cout << "派生类1克隆成功" << std::endl;
    }
};

// 派生类2
class Derived2 : public Base {
public:
    // 重写 clone() 函数，返回 Derived2 类型的副本
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived2>(*this);
    }

    // 重写 identify() 函数，用于测试克隆对象的类型
    void identify() const override {
        std::cout << "派生类2克隆成功" << std::endl;
    }
};

int main() {
    // 创建两个派生类对象
    std::unique_ptr<Base> obj1 = std::make_unique<Derived1>();
    std::unique_ptr<Base> obj2 = std::make_unique<Derived2>();

    // 克隆对象
    std::unique_ptr<Base> clonedObj1 = obj1->clone();
    std::unique_ptr<Base> clonedObj2 = obj2->clone();

    // 验证克隆对象的类型
    clonedObj1->identify();  // 输出: This is a Derived1 object.
    clonedObj2->identify();  // 输出: This is a Derived2 object.

    return 0;
}