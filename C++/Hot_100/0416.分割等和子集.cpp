/*
判断正整数数组能否分成元素和相等的两个子集。

示例
输入：nums = [1,5,11,5]
输出：true

题目链接：https://leetcode.cn/problems/partition-equal-subset-sum/
*/
#include "hot100_example.h"
#include <numeric>
using namespace std;

// 总和必须为偶数。用 0-1 背包判断能否选出总和的一半，金额倒序更新以免重复选同一元素。
// 设 S 为总和，时间 O(nS)，额外空间 O(S)。
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
        {
            return false;
        }
        int target = total / 2;
        vector<bool> reachable(target + 1, false);
        reachable[0] = true;
        for (int value : nums)
        {
            for (int sum = target; sum >= value; --sum)
            {
                reachable[sum] = reachable[sum] || reachable[sum - value];
            }
        }
        return reachable[target];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    hot100::print(sol.canPartition(nums));
    return 0;
}
