#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

// ��������
bool containsDup(const std::vector<int> &nums);
std::vector<int> readInput();

int main() {
    std::cout << "������һ���������飬Ԫ��֮���ÿո�ָ���" << std::endl;
    std::vector<int> nums = readInput();
    if (containsDup(nums))
        std::cout << "�����д����ظ�Ԫ�ء�" << std::endl;
    else
        std::cout << "�����в������ظ�Ԫ�ء�" << std::endl;
    return 0;
}

// ����������Ƿ�����ظ�Ԫ��
bool containsDup(const std::vector<int> &nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end())
            return true;
        seen.insert(num);
    }
    return false;
}

// ��ȡ�û��������������
std::vector<int> readInput() {
    std::vector<int> nums;
    std::string input;
    while (nums.empty()) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int num;                      //��Ŀ˵�� -10^9 <= nums[i] <= 10^9������ʹ��int����
        while (iss >> num)
            nums.push_back(num);
        if (nums.empty())
            std::cout << "�����������������һ��������" << std::endl;
    }
    return nums;
}