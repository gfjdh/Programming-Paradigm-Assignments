#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices) {
    if (prices.empty())
        return 0;
    int minPrice = prices[0];
    int bonus = 0;

    for (size_t i = 1; i < prices.size(); i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else
            bonus = max(bonus, prices[i] - minPrice);
    }
    return bonus;
}

int main() 
{
    vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
    cout << maxProfit(prices1) << endl;
    return 0;
}