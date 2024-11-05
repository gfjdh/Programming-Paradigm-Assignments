#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>

// 判断是否存在满足条件的下标对
bool containsNearAlmostDup(const std::vector<int> &nums, int indexDiff, int valueDiff) {
    std::set<int> window;  // 使用有序集合来存储当前窗口内的元素
    for (size_t i = 0; i < nums.size(); ++i) {       
        auto it = window.lower_bound(nums[i] - valueDiff); // 获取当前窗口内的最小值和最大值
        if (it != window.end() && *it <= nums[i] + valueDiff)
            return true;  // 存在满足条件的下标对
        window.insert(nums[i]);// 将当前元素加入窗口
        if (i >= indexDiff) // 如果窗口大小超过 indexDiff，移除窗口最左边的元素
            window.erase(nums[i - indexDiff]);
    }
    return false;  // 遍历完数组后没有找到符合条件的下标对
}

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

int main() {
    std::cout << "请输入整数数组，以空格分隔：" << std::endl;
    std::vector<int> nums = readInput();  // 读取用户输入的整数数组
    int indexDiff = 0;
    int valueDiff = 0;
    std::cout << "请输入 indexDiff 的值：" << std::endl;
    while (!(std::cin >> indexDiff) || indexDiff <= 0)
        handleInputError("输入错误：indexDiff 应为正整数。");
    std::cout << "请输入 valueDiff 的值：" << std::endl;
    while (!(std::cin >> valueDiff) || valueDiff < 0)
        handleInputError("输入错误：valueDiff 应为非负整数。");
    std::cout << std::boolalpha << containsNearAlmostDup(nums, indexDiff, valueDiff) << std::endl;
    return 0;
}