/*
机器人从 m × n 网格左上角出发，每步只能向右或向下。求到右下角的路径数。

示例
输入：m = 3, n = 7
输出：28

题目链接：https://leetcode.cn/problems/unique-paths/
*/
#include "hot100_example.h"
using namespace std;

// 到达一格的路径数是上方和左方的路径数之和。用一行数组滚动更新。
// 时间 O(mn)，额外空间 O(n)。
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> paths(n, 1);
        for (int row = 1; row < m; ++row)
        {
            for (int col = 1; col < n; ++col)
            {
                paths[col] += paths[col - 1];
            }
        }
        return paths.back();
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.uniquePaths(3, 7));
    return 0;
}
