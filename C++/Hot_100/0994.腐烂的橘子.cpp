/*
每分钟，烂橘子会使四邻中的新鲜橘子腐烂。求没有新鲜橘子所需的最短时间，无法全部腐烂时返回 -1。

示例
输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4

题目链接：https://leetcode.cn/problems/rotting-oranges/
*/
#include "hot100_example.h"
#include <queue>
#include <utility>
using namespace std;

// 以所有初始烂橘子作为同一层起点进行广度优先搜索。每处理一层经过一分钟。
// 时间和最坏队列空间均为 O(mn)。
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> pending;
        int fresh = 0;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                fresh += grid[r][c] == 1;
                if (grid[r][c] == 2)
                {
                    pending.emplace(r, c);
                }
            }
        }
        int minutes = 0;
        const int direction[5] = {0, 1, 0, -1, 0};
        while (fresh > 0 && !pending.empty())
        {
            int layer = pending.size();
            ++minutes;
            for (int i = 0; i < layer; ++i)
            {
                auto cell = pending.front();
                pending.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int r = cell.first + direction[d], c = cell.second + direction[d + 1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        --fresh;
                        pending.emplace(r, c);
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    hot100::print(sol.orangesRotting(grid));
    return 0;
}
