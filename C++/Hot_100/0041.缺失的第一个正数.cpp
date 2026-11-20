/*
找出未在整数数组 nums 中出现的最小正整数。

示例
输入：nums = [1,2,0]
输出：3

题目链接：https://leetcode.cn/problems/first-missing-positive/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 答案最多为 n + 1。将范围内的值 x 交换到下标 x - 1，再找第一处不匹配。
// 每次交换至少归位一个值，时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int &value : nums)
        {
            while (value >= 1 && value <= n && nums[value - 1] != value)
            {
                swap(value, nums[value - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 0};
    hot100::print(sol.firstMissingPositive(nums));
    return 0;
}
