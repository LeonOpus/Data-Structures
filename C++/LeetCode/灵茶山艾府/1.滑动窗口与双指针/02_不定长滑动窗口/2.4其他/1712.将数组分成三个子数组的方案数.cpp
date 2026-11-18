/*
把非负整数数组 nums 分成左、中、右三个非空连续部分。
统计满足左段和 <= 中段和 <= 右段和的分割方案，并对 10^9 + 7 取模。

示例 1
输入：nums = [1,1,1]
输出：1

示例 2
输入：nums = [1,2,2,2,5,0]
输出：3

示例 3
输入：nums = [3,2,1]
输出：0

约束
3 <= nums.length <= 10^5
0 <= nums[i] <= 10^4

题目链接：https://leetcode.cn/problems/ways-to-split-array-into-three-subarrays/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// prefix[i] 表示前 i 个元素的和。固定第一个切点 first 后，设左段和为 L，总和为 S。
// 第二个切点 second 要满足 prefix[second] >= 2 * L，且 2 * prefix[second] <= S + L。
// 前缀和单调不减，first 增加时，两条边界也只向右移动。时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {
        const int mod = 1000000007;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i += 1)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int lower = 2;
        int upper = 2;
        long long result = 0;
        for (int first = 1; first <= n - 2; first += 1)
        {
            long long leftSum = prefix[first];
            lower = max(lower, first + 1);
            while (lower < n && prefix[lower] < 2 * leftSum)
            {
                lower += 1;
            }

            upper = max(upper, lower);
            while (upper < n && 2 * prefix[upper] <= prefix[n] + leftSum)
            {
                upper += 1;
            }
            result += upper - lower;
        }
        return result % mod;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1};
    cout << sol.waysToSplit(nums) << endl;
    nums = {1, 2, 2, 2, 5, 0};
    cout << sol.waysToSplit(nums) << endl;
    nums = {3, 2, 1};
    cout << sol.waysToSplit(nums) << endl;
    nums = {0, 0, 0, 0};
    cout << sol.waysToSplit(nums) << endl;
    return 0;
}
