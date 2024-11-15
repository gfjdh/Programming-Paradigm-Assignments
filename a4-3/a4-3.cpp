#include <iostream>
#include <string>

// ���� Traveler
class Traveler {
protected:
    std::string name;

public:
    // ���캯��������һ���ַ�������
    Traveler(const std::string &n) : name(n) {
        std::cout << "Traveler ���캯��: " << name << std::endl;
    }

    // ���ƹ��캯��
    Traveler(const Traveler &other) : name(other.name) {
        std::cout << "Traveler ���ƹ��캯��: " << name << std::endl;
    }

    // ��ֵ�����
    Traveler &operator=(const Traveler &other) {
        if (this != &other) {
            name = other.name;
            std::cout << "Traveler ��ֵ�����: " << name << std::endl;
        }
        return *this;
    }

    // ��������
    ~Traveler() {
        std::cout << "Traveler ��������: " << name << std::endl;
    }
};

// �� Pager
class Pager {
protected:
    std::string pagerId;

public:
    // ���캯��������һ���ַ�������
    Pager(const std::string &id) : pagerId(id) {
        std::cout << "Pager ���캯��: " << pagerId << std::endl;
    }

    // ���ƹ��캯��
    Pager(const Pager &other) : pagerId(other.pagerId) {
        std::cout << "Pager ���ƹ��캯��: " << pagerId << std::endl;
    }

    // ��ֵ�����
    Pager &operator=(const Pager &other) {
        if (this != &other) {
            pagerId = other.pagerId;
            std::cout << "Pager ��ֵ�����: " << pagerId << std::endl;
        }
        return *this;
    }

    // ��������
    ~Pager() {
        std::cout << "Pager ��������: " << pagerId << std::endl;
    }
};

// ������ BusinessTraveler
class BusinessTraveler : public Traveler {
private:
    Pager pager;

public:
    // Ĭ�Ϲ��캯��
    BusinessTraveler() : Traveler("Default"), pager("DefaultPager") {
        std::cout << "BusinessTraveler Ĭ�Ϲ��캯��" << std::endl;
    }

    // �����ַ��������Ĺ��캯��
    BusinessTraveler(const std::string &n) : Traveler(n), pager(n + "Pager") {
        std::cout << "BusinessTraveler ���캯��: " << name << std::endl;
    }

    // ���ƹ��캯��
    BusinessTraveler(const BusinessTraveler &other) : Traveler(other), pager(other.pager) {
        std::cout << "BusinessTraveler ���ƹ��캯��: " << name << std::endl;
    }

    // ��ֵ�����
    BusinessTraveler &operator=(const BusinessTraveler &other) {
        if (this != &other) {
            Traveler::operator=(other);
            pager = other.pager;
            std::cout << "BusinessTraveler ��ֵ�����: " << name << std::endl;
        }
        return *this;
    }

    // ��������
    ~BusinessTraveler() {
        std::cout << "BusinessTraveler ��������: " << name << std::endl;
    }
};

int main() {
    // ���Դ���
    std::string input;
    std::cout << "������һ���ַ��������� BusinessTraveler ����: ";
    std::cin >> input;

    if (input.empty()) {
        std::cerr << "�������벻��Ϊ�ա�" << std::endl;
        return 1;
    }

    BusinessTraveler bt1(input);
    BusinessTraveler bt2 = bt1; // ���Ը��ƹ��캯��
    BusinessTraveler bt3;
    bt3 = bt1; // ���Ը�ֵ�����

    return 0;
}