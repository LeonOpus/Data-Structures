/*
给定正整数数组 nums。子数组得分等于元素和乘以长度。
求得分严格小于 k 的非空连续子数组个数。

示例 1
输入：nums = [2,1,4,3,5], k = 10
输出：6

示例 2
输入：nums = [1,1,1], k = 5
输出：5

题目链接：https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/
*/
#include <iostream>
#include <vector>
using namespace std;

// 元素为正数，增大窗口只会增加得分。达到 k 时收缩左端，再累加合法的后缀个数。
// 和、得分与总计数均使用 long long。时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            sum += nums[right];
            while (sum * (right - left + 1) >= k)
            {
                sum -= nums[left];
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 4, 3, 5};
    cout << sol.countSubarrays(nums, 10) << endl;
    nums = {1, 1, 1};
    cout << sol.countSubarrays(nums, 5) << endl;
    return 0;
}
