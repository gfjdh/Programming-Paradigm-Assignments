#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>

// �ж��Ƿ���������������±��
bool containsNearAlmostDup(const std::vector<int> &nums, int indexDiff, int valueDiff) {
    std::set<int> window;  // ʹ�����򼯺����洢��ǰ�����ڵ�Ԫ��
    for (size_t i = 0; i < nums.size(); ++i) {       
        auto it = window.lower_bound(nums[i] - valueDiff); // ��ȡ��ǰ�����ڵ���Сֵ�����ֵ
        if (it != window.end() && *it <= nums[i] + valueDiff)
            return true;  // ���������������±��
        window.insert(nums[i]);// ����ǰԪ�ؼ��봰��
        if (i >= indexDiff) // ������ڴ�С���� indexDiff���Ƴ���������ߵ�Ԫ��
            window.erase(nums[i - indexDiff]);
    }
    return false;  // �����������û���ҵ������������±��
}

// ��ȡ�û��������������
std::vector<int> readInput() {
    std::vector<int> nums;
    std::string input;
    while (nums.empty()) {
        std::getline(std::cin, input);
        std::istringstream iss(input);  // �������ַ���ת��Ϊ�ַ�����
        int num;
        while (iss >> num)  // ���ַ������������ȡ����
            nums.push_back(num);
        if (nums.empty())
            std::cout << "�����������������һ��������" << std::endl;
    }
    return nums;
}

// �����û�����Ĵ���
void handleInputError(const std::string &message) {
    std::cout << message << std::endl;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

int main() {
    std::cout << "�������������飬�Կո�ָ���" << std::endl;
    std::vector<int> nums = readInput();  // ��ȡ�û��������������
    int indexDiff = 0;
    int valueDiff = 0;
    std::cout << "������ indexDiff ��ֵ��" << std::endl;
    while (!(std::cin >> indexDiff) || indexDiff <= 0)
        handleInputError("�������indexDiff ӦΪ��������");
    std::cout << "������ valueDiff ��ֵ��" << std::endl;
    while (!(std::cin >> valueDiff) || valueDiff < 0)
        handleInputError("�������valueDiff ӦΪ�Ǹ�������");
    std::cout << std::boolalpha << containsNearAlmostDup(nums, indexDiff, valueDiff) << std::endl;
    return 0;
}