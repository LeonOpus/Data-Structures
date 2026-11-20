/*
在每行、每列都非递减的矩阵中查找 target。

示例
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true

题目链接：https://leetcode.cn/problems/search-a-2d-matrix-ii/
*/
#include "hot100_example.h"
using namespace std;

// 从右上角出发，比目标大就排除当前列，比目标小就排除当前行。时间 O(m + n)，额外空间 O(1)。
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int rows = matrix.size();
        int col = int(matrix[0].size()) - 1;
        while (row < rows && col >= 0)
        {
            int value = matrix[row][col];
            if (value == target) return true;
            if (value > target) --col;
            else ++row;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    hot100::print(sol.searchMatrix(matrix, 5));
    return 0;
}
