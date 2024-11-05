#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

// 函数声明
bool containsDup(const std::vector<int> &nums);
std::vector<int> readInput();

int main() {
    std::cout << "请输入一个整数数组，元素之间用空格分隔：" << std::endl;
    std::vector<int> nums = readInput();
    if (containsDup(nums))
        std::cout << "数组中存在重复元素。" << std::endl;
    else
        std::cout << "数组中不存在重复元素。" << std::endl;
    return 0;
}

// 检查数组中是否存在重复元素
bool containsDup(const std::vector<int> &nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end())
            return true;
        seen.insert(num);
    }
    return false;
}

// 读取用户输入的整数数组
std::vector<int> readInput() {
    std::vector<int> nums;
    std::string input;
    while (nums.empty()) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int num;                      //题目说了 -10^9 <= nums[i] <= 10^9，所以使用int类型
        while (iss >> num)
            nums.push_back(num);
        if (nums.empty())
            std::cout << "输入错误，请输入至少一个整数。" << std::endl;
    }
    return nums;
}