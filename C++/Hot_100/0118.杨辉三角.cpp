/*
生成杨辉三角的前 numRows 行。

示例
输入：numRows = 5
输出：[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

题目链接：https://leetcode.cn/problems/pascals-triangle/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 每行两端为 1，中间元素由上一行相邻的两项相加。时间 O(n²)，额外空间 O(1)，不计输出。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]:表示第i行第j列的值
    2. 确定递推关系
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    3. 确定初始值
    dp[0][0] = 1
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> dp(numRows);
        for (int i = 0; i < numRows; i++)
        {
            dp[i].resize(i + 1);
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
        return dp;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.generate(5));
    return 0;
}
