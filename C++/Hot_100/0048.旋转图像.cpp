/*
将方阵原地顺时针旋转 90 度。

示例
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

题目链接：https://leetcode.cn/problems/rotate-image/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 先沿主对角线转置，再反转每一行。时间 O(n²)，额外空间 O(1)。
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int r = 0; r < n; ++r)
        {
            for (int c = r + 1; c < n; ++c)
            {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
        for (auto &row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    hot100::print(matrix);
    return 0;
}
