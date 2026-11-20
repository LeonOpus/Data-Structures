/*
求 nums 中最长严格递增子序列的长度。子序列允许跳过原数组元素。

示例
输入：nums = [10,9,2,5,3,7,101,18]
输出：4

题目链接：https://leetcode.cn/problems/longest-increasing-subsequence/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// tails[i] 是长度为 i + 1 的递增子序列能取得的最小尾值。二分替换第一个不小于 x 的尾值。
// 时间 O(n log n)，额外空间 O(n)。
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tails;
        for (int value : nums)
        {
            auto position = lower_bound(tails.begin(), tails.end(), value);
            if (position == tails.end())
            {
                tails.push_back(value);
            }
            else
            {
                *position = value;
            }
        }
        return tails.size();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    hot100::print(sol.lengthOfLIS(nums));
    return 0;
}
