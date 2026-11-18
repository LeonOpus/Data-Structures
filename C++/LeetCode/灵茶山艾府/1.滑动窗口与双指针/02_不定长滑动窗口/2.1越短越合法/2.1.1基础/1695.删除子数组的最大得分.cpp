/*
从正整数数组 nums 中选出一个连续子数组并删除。
所选子数组的元素必须互不相同，得分为这些元素的和。
返回删除一个符合要求的子数组能得到的最高分。

示例 1：
输入：nums = [4,2,4,5,6]
输出：17
解释：选择 [2,4,5,6]，和为 17。

示例 2：
输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：[5,2,1] 和 [1,2,5] 都能得到 8 分。

提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4

题目链接：https://leetcode.cn/problems/maximum-erasure-value/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 用频次数组判断重复，同时维护窗口的元素和。
// 右端加入的数重复时，左端向右移动到重复消除为止。
// 所有元素为正数，固定右端时，最长的合法窗口也有最大的和。
// 设 U 为元素值域上界 10^4，时间复杂度 O(n + U)，额外空间复杂度 O(U)。
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        const int maxValue = 10000;
        int count[maxValue + 1] = {};
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = nums[right];
            count[incoming] += 1;
            sum += incoming;
            while (count[incoming] > 1)
            {
                int outgoing = nums[left];
                count[outgoing] -= 1;
                sum -= outgoing;
                left += 1;
            }
            result = max(result, sum);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << sol.maximumUniqueSubarray(nums) << endl;
    nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << sol.maximumUniqueSubarray(nums) << endl;
    nums = {10000, 10000, 10000};
    cout << sol.maximumUniqueSubarray(nums) << endl;
    return 0;
}
