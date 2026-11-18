/*
给定整数数组 nums 和正整数 k、m，求同时满足下列两个条件的非空连续子数组数量。
子数组中恰好有 k 种不同的整数，每种整数至少出现 m 次。

示例 1
输入：nums = [1,2,1,2,2], k = 2, m = 2
输出：2
[1,2,1,2] 和 [1,2,1,2,2] 中的两种值都至少出现两次。

示例 2
输入：nums = [3,1,2,4], k = 2, m = 1
输出：3

题目链接：https://leetcode.cn/problems/count-subarrays-with-k-distinct-integers/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 固定右端，用第一个窗口求「不同值至多 k 种」的最小起点 minStart。
// 用第二个窗口求「至少 k 种值的频次达到 m」的第一个不合法起点 firstInvalid。
// 同时满足两条约束的起点在 [minStart, firstInvalid) 内，这时恰好有 k 种值且全部达标。
// 设 U 为最大元素值，时间复杂度 O(n + U)，额外空间 O(U)。
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> distinctCount(maxValue + 1, 0);
        vector<int> frequencyCount(maxValue + 1, 0);
        int distinct = 0;
        int qualified = 0;
        int minStart = 0;
        int firstInvalid = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = nums[right];
            distinctCount[incoming] += 1;
            if (distinctCount[incoming] == 1)
            {
                distinct += 1;
            }
            while (distinct > k)
            {
                int outgoing = nums[minStart];
                distinctCount[outgoing] -= 1;
                if (distinctCount[outgoing] == 0)
                {
                    distinct -= 1;
                }
                minStart += 1;
            }

            frequencyCount[incoming] += 1;
            if (frequencyCount[incoming] == m)
            {
                qualified += 1;
            }
            while (qualified >= k)
            {
                int outgoing = nums[firstInvalid];
                if (frequencyCount[outgoing] == m)
                {
                    qualified -= 1;
                }
                frequencyCount[outgoing] -= 1;
                firstInvalid += 1;
            }
            result += max(0, firstInvalid - minStart);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 2};
    cout << sol.countSubarrays(nums, 2, 2) << endl;
    nums = {3, 1, 2, 4};
    cout << sol.countSubarrays(nums, 2, 1) << endl;
    nums = {1, 2, 1};
    cout << sol.countSubarrays(nums, 2, 2) << endl;
    return 0;
}
