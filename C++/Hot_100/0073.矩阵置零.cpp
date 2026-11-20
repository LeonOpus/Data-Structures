/*
若矩阵某个元素为 0，将它所在的整行与整列置零。要求原地修改。

示例
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

题目链接：https://leetcode.cn/problems/set-matrix-zeroes/
*/
#include "hot100_example.h"
using namespace std;

// 分别记首行和首列是否原本含零。将它们作为其余行列的标记区，最后处理首行首列。
// 时间 O(mn)，额外空间 O(1)。
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for (int c = 0; c < cols; ++c) firstRow |= matrix[0][c] == 0;
        for (int r = 0; r < rows; ++r) firstCol |= matrix[r][0] == 0;
        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols; ++c)
            {
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        if (firstRow)
        {
            for (int &value : matrix[0]) value = 0;
        }
        if (firstCol)
        {
            for (auto &row : matrix) row[0] = 0;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    sol.setZeroes(matrix);
    hot100::print(matrix);
    return 0;
}
