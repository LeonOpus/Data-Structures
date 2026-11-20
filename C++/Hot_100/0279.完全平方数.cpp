/*
用若干个完全平方数表示 n，返回所需项数的最小值。平方数可以重复使用。

示例
输入：n = 12
输出：3

题目链接：https://leetcode.cn/problems/perfect-squares/
*/
#include "hot100_example.h"
#include <algorithm>
#include <climits>
using namespace std;

// 把每个平方数视为可重复选择的物品，正序更新达到每个和的最少项数。
// 时间 O(n√n)，额外空间 O(n)。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[j]表示整数j的完全平方数的最少数量
    2. 确定递推关系
    dp[j] = min(dp[j],dp[j-i*i]+1)
    3. 确定初始值
    dp[0] = 0
    4. 确定遍历顺序
    平方数可以重复选择，枚举每个平方数后正序更新状态。
    5. 举例推导dp数组
    */
    int numSquares(int n)
    {
        int backpack_capacity = n;
        vector<int> dp(backpack_capacity + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) // 遍历物品,物品的容量最大为n
        {
            for (int j = i * i; j <= backpack_capacity; j++) // 遍历背包,从物品的重量开始,每个物品的重量是(i*i)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.numSquares(12));
    return 0;
}
