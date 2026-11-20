/*
矩阵每行有序，相邻两行满足后一行的首项大于前一行的末项。判断 target 是否存在。

示例
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

题目链接：https://leetcode.cn/problems/search-a-2d-matrix/
*/
#include "hot100_example.h"
using namespace std;

// 把整个矩阵视为按行拼接的有序数组，用除法和取模将一维下标映射回行列。
// 时间 O(log(mn))，额外空间 O(1)。
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int cols = matrix[0].size();
        int left = 0;
        int right = int(matrix.size()) * cols;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int value = matrix[mid / cols][mid % cols];
            if (value == target)
            {
                return true;
            }
            if (value < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    hot100::print(sol.searchMatrix(matrix, 3));
    return 0;
}
