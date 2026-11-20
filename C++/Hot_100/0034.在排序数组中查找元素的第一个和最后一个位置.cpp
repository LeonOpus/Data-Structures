/*
在非递减数组 nums 中找到 target 的第一次和最后一次出现。找不到时返回 [-1,-1]。

示例
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

题目链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 二分找出第一个不小于目标的位置和第一个大于目标的位置。时间 O(log n)，额外空间 O(1)。
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto range = equal_range(nums.begin(), nums.end(), target);
        if (range.first == range.second)
        {
            return {-1, -1};
        }
        return {int(range.first - nums.begin()), int(range.second - nums.begin()) - 1};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    hot100::print(sol.searchRange(nums, 8));
    return 0;
}
