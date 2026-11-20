/*
从网格左上角走到右下角，每步只向右或向下。求经过格子的数值和的最小值。

示例
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7

题目链接：https://leetcode.cn/problems/minimum-path-sum/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 每格的最小路径和等于上方与左方路径和的较小值加当前格。时间 O(mn)，额外空间 O(mn)。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示从位置[0,0]抵达位置[i-1,j-1]，路径上的数字总和为最小
    2. 确定递推关系
    dp[i][j]可以由dp[i-1][j]和dp[i][j-1]取最小值获得
    3. 确定初始值
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++))
        dp[0][j]=dp[0][j-1]+grid[0][j];
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    hot100::print(sol.minPathSum(grid));
    return 0;
}
