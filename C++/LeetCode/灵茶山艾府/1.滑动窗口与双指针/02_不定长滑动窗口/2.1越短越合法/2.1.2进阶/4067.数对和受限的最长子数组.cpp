/*
给定正整数数组 nums，求最长的连续子数组，其中找不到三个互不相同的下标，
使前两个下标对应的元素之和等于第三个元素。

示例 1
输入：nums = [2,3,5,3,2,1]
输出：3
[3,5,3] 满足条件，任意长度为 4 的窗口都包含 2 + 3 = 5。

示例 2
输入：nums = [3,4,5,6]
输出：4

约束
nums 的长度至多为 1000，元素在 [1, 500] 内。

题目链接：https://leetcode.cn/problems/longest-subarray-with-restricted-pair-sums/
*/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// 右端加入 x 时，只有包含 x 的三元组可能破坏窗口。
// 已有数对的和或绝对差等于 x 时，这个数对能与 x 组成非法三元组。
// 对每个可能的 x 记录已有数对中最大的较小下标。左端跳过该下标后，所有这样的数对都被排除。
// 时间复杂度 O(n² + U)，额外空间 O(U)，其中 U 为元素值域上界 500。
class Solution
{
public:
    int maxSubarray(vector<int> &nums)
    {
        const int maxValue = 500;
        int latestLeft[2 * maxValue + 1];
        fill(latestLeft, latestLeft + 2 * maxValue + 1, -1);

        int n = nums.size();
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int x = nums[right];
            left = max(left, latestLeft[x] + 1);
            result = max(result, right - left + 1);

            // 查询完成后再登记包含 right 的数对，确保三个下标互不相同。
            for (int i = left; i < right; i += 1)
            {
                int sum = nums[i] + x;
                int difference = abs(nums[i] - x);
                latestLeft[sum] = max(latestLeft[sum], i);
                latestLeft[difference] = max(latestLeft[difference], i);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 5, 3, 2, 1};
    cout << sol.maxSubarray(nums) << endl;
    nums = {3, 4, 5, 6};
    cout << sol.maxSubarray(nums) << endl;
    nums = {4, 2, 2};
    cout << sol.maxSubarray(nums) << endl;
    return 0;
}
