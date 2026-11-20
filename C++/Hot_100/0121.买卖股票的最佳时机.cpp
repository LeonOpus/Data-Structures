/*
只允许买入和卖出同一支股票各一次，并且买入在前。求最大利润，无法获利时返回 0。

示例
输入：prices = [7,1,5,3,6,4]
输出：5

题目链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 访问每个卖出日，用此前最低买价计算当天能实现的利润。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lowest = prices.front();
        int result = 0;
        for (int price : prices)
        {
            result = max(result, price - lowest);
            lowest = min(lowest, price);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    hot100::print(sol.maxProfit(prices));
    return 0;
}
