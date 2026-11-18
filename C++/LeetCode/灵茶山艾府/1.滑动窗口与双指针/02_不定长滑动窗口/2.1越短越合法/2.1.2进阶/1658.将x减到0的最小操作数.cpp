/*
每步从正整数数组 nums 的左端或右端移除一个元素，同时从 x 中减去它。
求让 x 恰好减到 0 所需的最少步数。无法做到时返回 -1。

示例 1
输入：nums = [1,1,4,2,3], x = 5
输出：2
移除最右边的 3 和 2 即可。

示例 2
输入：nums = [5,6,7,8,9], x = 4
输出：-1

示例 3
输入：nums = [3,2,20,1,1,3], x = 10
输出：5

题目链接：https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 从两端删除后，留下的是一段连续子数组，其元素和必须等于总和减 x。
// 用滑窗找出和等于目标值的最长子数组，答案为总长度减去保留长度。
// 时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0)
        {
            return -1;
        }
        if (target == 0)
        {
            return n;
        }

        int left = 0;
        int sum = 0;
        int longest = -1;
        for (int right = 0; right < n; right += 1)
        {
            sum += nums[right];
            while (sum > target)
            {
                sum -= nums[left];
                left += 1;
            }
            if (sum == target)
            {
                longest = max(longest, right - left + 1);
            }
        }
        return longest == -1 ? -1 : n - longest;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 4, 2, 3};
    cout << sol.minOperations(nums, 5) << endl;
    nums = {5, 6, 7, 8, 9};
    cout << sol.minOperations(nums, 4) << endl;
    nums = {3, 2, 20, 1, 1, 3};
    cout << sol.minOperations(nums, 10) << endl;
    return 0;
}
