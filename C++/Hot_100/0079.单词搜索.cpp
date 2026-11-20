/*
判断是否能在字母网格中沿上下左右走出 word。每个格子在同一路径中最多使用一次。

示例
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

题目链接：https://leetcode.cn/problems/word-search/
*/
#include "hot100_example.h"
using namespace std;

// 从匹配首字母的格子出发做深度优先搜索，离开时恢复临时访问标记。
// 设词长为 L，时间上界 O(mn × 4 × 3^(L - 1))，递归空间 O(L)。
class Solution
{
private:
    bool search(vector<vector<char>> &board, const string &word, int i, int j, int at)
    {
        if (i < 0 || i >= int(board.size()) || j < 0 || j >= int(board[0].size()) ||
            board[i][j] != word[at])
        {
            return false;
        }
        if (at + 1 == int(word.size()))
        {
            return true;
        }
        char saved = board[i][j];
        board[i][j] = '\0';
        bool found = search(board, word, i - 1, j, at + 1) ||
                     search(board, word, i + 1, j, at + 1) ||
                     search(board, word, i, j - 1, at + 1) ||
                     search(board, word, i, j + 1, at + 1);
        board[i][j] = saved;
        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (search(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    hot100::print(sol.exist(board, "ABCCED"));
    return 0;
}
