#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> numbers(25);

    for (int i = 0; i < 25; ++i)
        numbers[i] = static_cast<float>(i + 1);
    for (const auto &num : numbers)
        cout << num << " ";
    cout << endl;

    for (auto &num : numbers)
        num = num * num;
    for (const auto &num : numbers)
        cout << num << " ";
    cout << endl;

    return 0;
}