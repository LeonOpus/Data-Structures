/*
统计字符网格中的岛屿个数。只考虑上下左右相邻的陆地。

示例
输入：grid = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
输出：1

题目链接：https://leetcode.cn/problems/number-of-islands/
*/
#include "hot100_example.h"
#include <queue>
#include <utility>
using namespace std;

// 每次发现未访问陆地，就广度优先搜索并把整座岛的陆地标为已访问。
// 时间 O(mn)，最坏队列空间 O(mn)。
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        const int direction[5] = {0, 1, 0, -1, 0};
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] != '1')
                {
                    continue;
                }
                ++result;
                queue<pair<int, int>> pending;
                pending.emplace(r, c);
                grid[r][c] = '0';
                while (!pending.empty())
                {
                    auto cell = pending.front();
                    pending.pop();
                    for (int d = 0; d < 4; ++d)
                    {
                        int nr = cell.first + direction[d], nc = cell.second + direction[d + 1];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1')
                        {
                            grid[nr][nc] = '0';
                            pending.emplace(nr, nc);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    hot100::print(sol.numIslands(grid));
    return 0;
}
