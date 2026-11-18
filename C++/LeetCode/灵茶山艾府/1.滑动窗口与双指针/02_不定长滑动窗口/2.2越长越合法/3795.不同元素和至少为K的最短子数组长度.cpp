/*
给定正整数数组 nums 和整数 k。
一个连续子数组的不同元素和，是其中各个数值只加一次得到的和。
求不同元素和至少为 k 的最短非空子数组长度，不存在时返回 -1。

示例 1
输入：nums = [2,2,3,1], k = 4
输出：2
[2,3] 中的不同元素和是 5。

示例 2
输入：nums = [3,2,3,4], k = 5
输出：2

示例 3
输入：nums = [5,5,4], k = 5
输出：1

约束
1 <= nums.length, nums[i] <= 10^5
1 <= k <= 10^9

题目链接：https://leetcode.cn/problems/minimum-subarray-length-with-distinct-sum-at-least-k/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 用频次数组记录窗口内每个数值的出现次数。
// 频次从 0 变为 1 时才加上该值，从 1 变为 0 时才减去该值。
// 窗口内的不同元素和达到 k 时，尽量向右收缩左端并更新最短长度。
// 设 M 为数组最大值，时间复杂度 O(n + M)，额外空间复杂度 O(M)。
class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int limit = *max_element(nums.begin(), nums.end());
        vector<int> count(limit + 1, 0);
        int left = 0;
        int shortest = n + 1;
        long long distinctSum = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = nums[right];
            count[incoming] += 1;
            if (count[incoming] == 1)
            {
                distinctSum += incoming;
            }

            while (distinctSum >= k)
            {
                shortest = min(shortest, right - left + 1);
                int outgoing = nums[left];
                count[outgoing] -= 1;
                if (count[outgoing] == 0)
                {
                    distinctSum -= outgoing;
                }
                left += 1;
            }
        }
        return shortest > n ? -1 : shortest;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 3, 1};
    cout << sol.minLength(nums, 4) << endl;
    nums = {3, 2, 3, 4};
    cout << sol.minLength(nums, 5) << endl;
    nums = {5, 5, 4};
    cout << sol.minLength(nums, 5) << endl;
    nums = {4, 4, 4};
    cout << sol.minLength(nums, 5) << endl;
    return 0;
}
