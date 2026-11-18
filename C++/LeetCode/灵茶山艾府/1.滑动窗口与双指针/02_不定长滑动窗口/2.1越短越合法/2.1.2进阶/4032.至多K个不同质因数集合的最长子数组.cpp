/*
给定正整数数组 nums。一个子数组的质因数集合，是窗口内所有元素的质因数并集。
求质因数种类数不超过 k 的最长连续子数组长度。不存在时返回 0。

示例 1
输入：nums = [7,6,10,12,11], k = 3
输出：3
[6,10,12] 的质因数并集为 {2,3,5}。

示例 2
输入：nums = [6,10,15], k = 2
输出：1

约束
nums 的长度至多为 10^5，元素在 [2, 10^5] 内。

题目链接：https://leetcode.cn/problems/longest-subarray-with-at-most-k-distinct-prime-factors/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 先筛出每个数的最小质因数，再用它分解进出窗口的元素。
// 同一个元素内重复的质因数只计一次。频次从 0 变为 1 时，窗口新增一种质因数。
// 设 M 为最大元素，筛法耗时 O(M log log M)，滑窗耗时 O(n log M)，额外空间 O(M)。
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int limit = *max_element(nums.begin(), nums.end());
        vector<int> smallestPrime(limit + 1, 0);
        for (int p = 2; p <= limit; p += 1)
        {
            if (smallestPrime[p] != 0)
            {
                continue;
            }
            for (int multiple = p; multiple <= limit; multiple += p)
            {
                if (smallestPrime[multiple] == 0)
                {
                    smallestPrime[multiple] = p;
                }
            }
        }

        vector<int> count(limit + 1, 0);
        int kinds = 0;
        auto update = [&](int value, int change)
        {
            while (value > 1)
            {
                int p = smallestPrime[value];
                if (count[p] > 0)
                {
                    kinds -= 1;
                }
                count[p] += change;
                if (count[p] > 0)
                {
                    kinds += 1;
                }
                do
                {
                    value /= p;
                } while (value % p == 0);
            }
        };

        int n = nums.size();
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            update(nums[right], 1);
            while (kinds > k)
            {
                update(nums[left], -1);
                left += 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7, 6, 10, 12, 11};
    cout << sol.longestSubarray(nums, 3) << endl;
    nums = {4, 6, 9, 18};
    cout << sol.longestSubarray(nums, 4) << endl;
    nums = {6, 10, 15};
    cout << sol.longestSubarray(nums, 2) << endl;
    return 0;
}
