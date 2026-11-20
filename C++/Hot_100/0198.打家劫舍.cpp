/*
每间房有一定金额，不能同时选择相邻房间。求可拿到的最大金额。

示例
输入：nums = [1,2,3,1]
输出：4

题目链接：https://leetcode.cn/problems/house-robber/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 处理新房间时，可以保留上一步的最优值，或用上上步的最优值加当前金额。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int previous = 0;
        int best = 0;
        for (int amount : nums)
        {
            int next = max(best, previous + amount);
            previous = best;
            best = next;
        }
        return best;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    hot100::print(sol.rob(nums));
    return 0;
}
