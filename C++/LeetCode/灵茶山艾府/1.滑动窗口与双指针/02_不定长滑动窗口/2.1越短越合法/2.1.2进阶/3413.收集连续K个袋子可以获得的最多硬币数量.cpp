/*
数轴上每个整数位置都有一个袋子。coins[i] = [li, ri, ci] 表示闭区间内每个袋子有 ci 枚硬币。
给定的区间互不重叠，其余袋子为空。求选取连续 k 个袋子能收集的最多硬币数。

示例 1
输入：coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
输出：10

示例 2
输入：coins = [[1,10,3]], k = 2
输出：6

题目链接：https://leetcode.cn/problems/maximum-coins-from-k-consecutive-bags/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 取最靠左的最优窗口。它从左边移来时收益增加，继续右移时收益不再增加。
// 这要求左端进入一个硬币区间的起点，或右端到达一个硬币区间的终点。
// 先枚举右端对齐的窗口，再镜像坐标来覆盖左端对齐的情况。用 long long 累加区间贡献。
// 时间复杂度 O(n log n)，额外空间 O(n) 用于镜像区间。
class Solution
{
private:
    long long maxAtRightEdge(const vector<vector<int>> &intervals, int k)
    {
        int n = intervals.size();
        int left = 0;
        long long sum = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            const auto &incoming = intervals[right];
            sum += 1LL * (incoming[1] - incoming[0] + 1) * incoming[2];

            int windowStart = incoming[1] - k + 1;
            while (intervals[left][1] < windowStart)
            {
                const auto &outgoing = intervals[left];
                sum -= 1LL * (outgoing[1] - outgoing[0] + 1) * outgoing[2];
                left += 1;
            }

            const auto &first = intervals[left];
            long long uncovered = 1LL * max(0, windowStart - first[0]) * first[2];
            result = max(result, sum - uncovered);
        }
        return result;
    }

public:
    long long maximumCoins(vector<vector<int>> &coins, int k)
    {
        sort(coins.begin(), coins.end());

        vector<vector<int>> reflected;
        reflected.reserve(coins.size());
        for (auto it = coins.rbegin(); it != coins.rend(); ++it)
        {
            reflected.push_back({-(*it)[1], -(*it)[0], (*it)[2]});
        }
        return max(maxAtRightEdge(coins, k), maxAtRightEdge(reflected, k));
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> coins = {{8, 10, 1}, {1, 3, 2}, {5, 6, 4}};
    cout << sol.maximumCoins(coins, 4) << endl;
    coins = {{1, 10, 3}};
    cout << sol.maximumCoins(coins, 2) << endl;
    return 0;
}
