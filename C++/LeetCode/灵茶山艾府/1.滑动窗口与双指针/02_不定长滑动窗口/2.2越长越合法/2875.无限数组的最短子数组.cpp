/*
将正整数数组 nums 不断重复，得到一个无限数组。
求无限数组中元素和恰好等于 target 的最短连续子数组长度，不存在时返回 -1。

示例 1
输入：nums = [1,2,3], target = 5
输出：2
可选 [2,3]。

示例 2
输入：nums = [1,1,1,2,3], target = 4
输出：2
可在两轮交界处取 [3,1]。

示例 3
输入：nums = [2,4,6,8], target = 3
输出：-1

约束
1 <= nums.length, nums[i] <= 10^5
1 <= target <= 10^9

题目链接：https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 设一个周期和为 S。任意长度为 n 的连续段都恰好贡献 S。
// 不足一个周期的连续段元素和小于 S，因此完整周期数必定为 target / S。
// 在两轮 nums 上用滑窗找和为 target % S 的最短连续段，允许它跨越两轮交界。
// 用取模访问重复数组，时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long periodSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long fullLength = (target / periodSum) * n;
        long long remainder = target % periodSum;
        if (remainder == 0)
        {
            return fullLength;
        }

        int left = 0;
        int shortest = n;
        long long sum = 0;
        for (int right = 0; right < 2 * n; right += 1)
        {
            sum += nums[right % n];
            while (sum > remainder)
            {
                sum -= nums[left % n];
                left += 1;
            }
            if (sum == remainder)
            {
                shortest = min(shortest, right - left + 1);
            }
        }
        return shortest == n ? -1 : fullLength + shortest;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.minSizeSubarray(nums, 5) << endl;
    cout << sol.minSizeSubarray(nums, 10) << endl; // 一轮完整周期，加跨轮的 [3,1]
    cout << sol.minSizeSubarray(nums, 12) << endl;
    nums = {1, 1, 1, 2, 3};
    cout << sol.minSizeSubarray(nums, 4) << endl;
    nums = {2, 4, 6, 8};
    cout << sol.minSizeSubarray(nums, 3) << endl;
    return 0;
}
