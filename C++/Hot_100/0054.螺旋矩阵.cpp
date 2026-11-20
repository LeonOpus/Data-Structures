/*
按顺时针螺旋顺序读取矩阵中的每一个元素。

示例
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

题目链接：https://leetcode.cn/problems/spiral-matrix/
*/
#include "hot100_example.h"
using namespace std;

// 按上、右、下、左四条边读取，每读取一条边就收缩相应边界。处理下边和左边前检查剩余范围。
// 时间 O(mn)，额外空间 O(1)，不计输出。
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top = 0, bottom = int(matrix.size()) - 1;
        int left = 0, right = int(matrix[0].size()) - 1;
        vector<int> result;
        while (top <= bottom && left <= right)
        {
            for (int c = left; c <= right; ++c) result.push_back(matrix[top][c]);
            ++top;
            for (int r = top; r <= bottom; ++r) result.push_back(matrix[r][right]);
            --right;
            if (top <= bottom)
            {
                for (int c = right; c >= left; --c) result.push_back(matrix[bottom][c]);
                --bottom;
            }
            if (left <= right)
            {
                for (int r = bottom; r >= top; --r) result.push_back(matrix[r][left]);
                ++left;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    hot100::print(sol.spiralOrder(matrix));
    return 0;
}
