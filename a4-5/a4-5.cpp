#include <iostream>
#include <memory>

// ����
class Base {
public:
    virtual ~Base() = default;

    // ���麯����Ҫ�����������ʵ�� clone()
    virtual std::unique_ptr<Base> clone() const = 0;

    // �麯�������ڲ��Կ�¡���������
    virtual void identify() const {
        std::cout << "����" << std::endl;
    }
};

// ������1
class Derived1 : public Base {
public:
    // ��д clone() ���������� Derived1 ���͵ĸ���
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived1>(*this);
    }

    // ��д identify() ���������ڲ��Կ�¡���������
    void identify() const override {
        std::cout << "������1��¡�ɹ�" << std::endl;
    }
};

// ������2
class Derived2 : public Base {
public:
    // ��д clone() ���������� Derived2 ���͵ĸ���
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived2>(*this);
    }

    // ��д identify() ���������ڲ��Կ�¡���������
    void identify() const override {
        std::cout << "������2��¡�ɹ�" << std::endl;
    }
};

int main() {
    // �����������������
    std::unique_ptr<Base> obj1 = std::make_unique<Derived1>();
    std::unique_ptr<Base> obj2 = std::make_unique<Derived2>();

    // ��¡����
    std::unique_ptr<Base> clonedObj1 = obj1->clone();
    std::unique_ptr<Base> clonedObj2 = obj2->clone();

    // ��֤��¡���������
    clonedObj1->identify();  // ���: This is a Derived1 object.
    clonedObj2->identify();  // ���: This is a Derived2 object.

    return 0;
}