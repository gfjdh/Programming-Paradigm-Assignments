#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <cstdlib>

// 读取用户输入的整数数组
std::vector<int> readInput() {
    std::vector<int> nums;
    std::string input;
    while (nums.empty()) {
        std::getline(std::cin, input);
        std::istringstream iss(input);  // 将输入字符串转换为字符串流
        int num;
        while (iss >> num)  // 从字符串流中逐个读取整数
            nums.push_back(num); 
        if (nums.empty())
            std::cout << "输入错误，请输入至少一个整数。" << std::endl;
    }
    return nums;
}

// 处理用户输入的错误
void handleInputError(const std::string &message) {
    std::cout << message << std::endl;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

// 判断数组中是否存在两个不同的索引 i 和 j，使得 nums[i] == nums[j] 且 abs(i - j) <= k
bool containsNearDup(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> indexMap;  // 用于存储每个数字最后一次出现的索引
    for (size_t i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (indexMap.find(num) != indexMap.end() && i - indexMap[num] <= k)
            return true;  // 如果当前数字已经出现过，并且距离上次出现的索引不超过 k，则返回 true
        indexMap[num] = i;  // 更新当前数字的最新索引
    }
    return false;  // 遍历完数组后没有找到符合条件的索引对，返回 false
}

int main() {
    std::cout << "请输入整数数组，以空格分隔：" << std::endl;
    std::vector<int> nums = readInput();  // 读取用户输入的整数数组
    int k;
    std::cout << "请输入 k 的值：" << std::endl;
    while (!(std::cin >> k) || k < 0)  // 读取 k 的值，确保 k 为非负数
        handleInputError("输入错误：k 应为非负数。");
    std::cout << std::boolalpha << containsNearDup(nums, k) << std::endl;  // 输出结果
    return 0;
}