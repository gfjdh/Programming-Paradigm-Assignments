#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cstdlib>

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

// �ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums[i] == nums[j] �� abs(i - j) <= k
bool containsNearDup(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> indexMap;  // ���ڴ洢ÿ���������һ�γ��ֵ�����
    for (size_t i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (indexMap.find(num) != indexMap.end() && i - indexMap[num] <= k)
            return true;  // �����ǰ�����Ѿ����ֹ������Ҿ����ϴγ��ֵ����������� k���򷵻� true
        indexMap[num] = i;  // ���µ�ǰ���ֵ���������
    }
    return false;  // �����������û���ҵ����������������ԣ����� false
}

int main() {
    std::cout << "�������������飬�Կո�ָ���" << std::endl;
    std::vector<int> nums = readInput();  // ��ȡ�û��������������
    int k;
    std::cout << "������ k ��ֵ��" << std::endl;
    while (!(std::cin >> k) || k < 0)  // ��ȡ k ��ֵ��ȷ�� k Ϊ�Ǹ���
        handleInputError("�������k ӦΪ�Ǹ�����");
    std::cout << std::boolalpha << containsNearDup(nums, k) << std::endl;  // ������
    return 0;
}