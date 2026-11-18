/*
给定正整数数组 nums。如果一段连续子数组内任意两个不同位置的元素按位与均为 0，
这段子数组就是优雅的。求优雅子数组的最大长度。

示例 1
输入：nums = [1,3,8,48,10]
输出：3
可以取 [3,8,48]。

示例 2
输入：nums = [3,1,5,11,13]
输出：1

约束
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

题目链接：https://leetcode.cn/problems/longest-nice-subarray/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 合法窗口内每个二进制位最多被一个元素占用，用按位或记录所有已占用的位。
// 若新元素与掩码有重叠，就移出左端。由于各元素的位互不重叠，可用异或撤销它占用的位。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int mask = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            while ((mask & nums[right]) != 0)
            {
                mask ^= nums[left];
                left += 1;
            }
            mask |= nums[right];
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 8, 48, 10};
    cout << sol.longestNiceSubarray(nums) << endl;
    nums = {3, 1, 5, 11, 13};
    cout << sol.longestNiceSubarray(nums) << endl;
    return 0;
}
