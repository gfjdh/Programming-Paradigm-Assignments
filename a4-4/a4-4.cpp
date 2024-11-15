#include <iostream>
#include <ctime>

// ����
class Base {
public:
    // �麯��
    virtual void virtualFunction() {
        // �麯����ʵ��
    }

    // ���麯��
    void nonVirtualFunction() {
        // ���麯����ʵ��
    }

    virtual ~Base() = default; // ����������
};

// ������
class Derived : public Base {
public:
    // ��д�麯��
    void virtualFunction() override {
        // ���������麯����ʵ��
    }
};

int main() {
    // ��ʾ�û�����ѭ������
    std::cout << "������ѭ���������������1000000����";
    int loopCount;
    std::cin >> loopCount;

    // ���������
    if (std::cin.fail() || loopCount <= 0) {
        std::cerr << "�������������һ����������" << std::endl;
        return 1;
    }

    // �������������
    Derived derivedObj;

    // ����ת��Ϊ����ָ��
    Base *basePtr = &derivedObj;

    // �����麯�����õ�ʱ��
    clock_t start = clock();
    for (int i = 0; i < loopCount; ++i) {
        basePtr->virtualFunction();
    }
    clock_t end = clock();
    double virtualTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // �������麯�����õ�ʱ��
    start = clock();
    for (int i = 0; i < loopCount; ++i) {
        basePtr->nonVirtualFunction();
    }
    end = clock();
    double nonVirtualTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // ������
    std::cout << "�麯������ʱ��: " << virtualTime << " ��" << std::endl;
    std::cout << "���麯������ʱ��: " << nonVirtualTime << " ��" << std::endl;

    return 0;
}