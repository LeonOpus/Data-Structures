/*
求连续子数组中包含至少 k 个原数组最大值的子数组数量。
最大值由整个 nums 决定。

示例 1
输入：nums = [1,3,2,3,3], k = 2
输出：6

示例 2
输入：nums = [1,4,2,1], k = 3
输出：0

题目链接：https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 先找全局最大值。窗口中最大值的次数达到 k 时收缩，直到次数少于 k。
// 固定右端，左端取 [0,left) 中任意位置都能包含足够多的最大值。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maximum = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        int left = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            count += nums[right] == maximum;
            while (count >= k)
            {
                count -= nums[left] == maximum;
                left += 1;
            }
            result += left;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 3};
    cout << sol.countSubarrays(nums, 2) << endl;
    nums = {1, 4, 2, 1};
    cout << sol.countSubarrays(nums, 3) << endl;
    return 0;
}
