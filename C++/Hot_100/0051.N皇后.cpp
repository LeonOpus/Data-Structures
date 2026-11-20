/*
在 n × n 棋盘上放 n 个皇后，每两枚都不能同列、同行或在同一对角线。返回全部放法。

示例
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

题目链接：https://leetcode.cn/problems/n-queens/
*/
#include "hot100_example.h"
using namespace std;

// 每行只放一个皇后，按行搜索并检查列与两条斜线。回溯时撤销当前落子。
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> chessboard(n, string(n, '.'));
        backtracking(0, n, chessboard, result);
        return result;
    }

    void backtracking(int row, int n, vector<string> &chessboard, vector<vector<string>> &result)
    {
        // 递归终止条件,每一层for循环是行，如果row==n,说明已经到了最后一行,可以将当前棋盘加入结果集
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        // 遍历每一列
        for (int col = 0; col < n; col += 1)
        {
            if (isValid(row, col, n, chessboard)) // 判断该行该列是否可以放置皇后
            {
                chessboard[row][col] = 'Q';
                backtracking(row + 1, n, chessboard, result);
                chessboard[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string> &chessboard) // 检查同行，同列，45度角，135度角是否有皇后
    {
        // 检查同列是否有皇后，即检查在当前列 col 的上方（之前的行）是否已经放置了皇后
        for (int i = 0; i < row; i += 1)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        // 检查45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i -= 1, j -= 1)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        // 检查135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i -= 1, j += 1)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.solveNQueens(4));
    return 0;
}
