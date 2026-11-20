/*
给定可无限使用的硬币面额，求凑成 amount 所需的最少硬币数。凑不成时返回 -1。

示例
输入：coins = [1,2,5], amount = 11
输出：3

题目链接：https://leetcode.cn/problems/coin-change/
*/
#include "hot100_example.h"
#include <algorithm>
#include <climits>
using namespace std;

// 完全背包，按金额正序更新最少硬币数。时间 O(面额数 × amount)，额外空间 O(amount)。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[j]：装满容量为j的背包使用最少物品的数量为dp[j]
    2. 确定递推关系
    dp[j-coins[i]]装满这么大的背包最少容量是dp[j-coins[i]],所以再加上1就凑成dp[j]
    dp[j] = min(dp[j],dp[j-coins[i]]+1)
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int coinChange(vector<int> &coins, int amount)
    {
        int backpack_capacity = amount;
        vector<int> dp(backpack_capacity + 1, INT_MAX);
        dp[0] = 0;                             // 因为题目求的是最少元素数量，与组合排列无关，所以先遍历哪个都行
        for (int i = 0; i < coins.size(); i++) // 遍历物品
        {
            for (int j = coins[i]; j <= backpack_capacity; j++) // 遍历背包,递推公式里有dp[j - coins[i]]，避免出现负数下标。
            {
                if (dp[j - coins[i]] != INT_MAX) // 如果dp[j - coins[i]]是初始值则跳过
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[backpack_capacity] == INT_MAX ? -1 : dp[backpack_capacity];
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    hot100::print(sol.coinChange(coins, 11));
    return 0;
}
