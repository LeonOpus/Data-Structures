/*
数轴上有至少三颗石子，位置互不相同。
每次只能移动最左或最右的一颗，落点必须为空，而且该石子移完后必须位于两端之间。
求让所有石子占据连续位置所需的最少和最多移动次数，按此顺序返回。

示例 1
输入：stones = [7,4,9]
输出：[1,2]

示例 2
输入：stones = [6,5,4,3,10]
输出：[2,3]

题目链接：https://leetcode.cn/problems/moving-stones-until-consecutive-ii/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 最大次数取两种首步方向中较大的一种。首步选定端点后，另一侧剩余 n - 1 颗石子之间的空位
// 决定了可用的步数预算，之后每次可让这个预算只减少 1。
// 最少次数用滑窗找跨度不超过 n - 1 的石子组。通常把窗口外的石子填进空位即可。
// 若窗口内 n - 1 颗已经连续，远处最后一颗不能直接移到它们外侧，这种窗口需两步。
// 时间复杂度 O(n log n)，滑窗额外空间 O(1)。
class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - (n - 2);

        int minMoves = n;
        int left = 0;
        for (int right = 0; right < n; right += 1)
        {
            while (stones[right] - stones[left] >= n)
            {
                left += 1;
            }
            int kept = right - left + 1;
            int moves = n - kept;
            if (kept == n - 1 && stones[right] - stones[left] == n - 2)
            {
                moves = 2;
            }
            minMoves = min(minMoves, moves);
        }
        return {minMoves, maxMoves};
    }
};

int main()
{
    Solution sol;
    vector<int> stones = {7, 4, 9};
    vector<int> result = sol.numMovesStonesII(stones);
    cout << result[0] << " " << result[1] << endl;
    stones = {6, 5, 4, 3, 10};
    result = sol.numMovesStonesII(stones);
    cout << result[0] << " " << result[1] << endl;
    stones = {1, 2, 3};
    result = sol.numMovesStonesII(stones);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
