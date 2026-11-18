/*
给定整数数组 nums。若一个连续子数组中任意两个元素的差的绝对值都不超过 2，
则该子数组是不间断的。求不间断子数组的个数。

示例 1
输入：nums = [5,4,2,4]
输出：8

示例 2
输入：nums = [1,2,3]
输出：6

题目链接：https://leetcode.cn/problems/continuous-subarrays/
*/
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// 只需要比较窗口最大值与最小值。用两个单调队列分别维护候选最大值和最小值的下标。
// 差值超过 2 时收缩左端。恢复合法后，累加以当前右端结尾的合法子数组数。
// 每个下标最多进出各队列一次，时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        deque<int> maximum;
        deque<int> minimum;
        int n = nums.size();
        int left = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            while (!maximum.empty() && nums[maximum.back()] <= nums[right])
            {
                maximum.pop_back();
            }
            maximum.push_back(right);
            while (!minimum.empty() && nums[minimum.back()] >= nums[right])
            {
                minimum.pop_back();
            }
            minimum.push_back(right);

            while (nums[maximum.front()] - nums[minimum.front()] > 2)
            {
                if (maximum.front() == left)
                {
                    maximum.pop_front();
                }
                if (minimum.front() == left)
                {
                    minimum.pop_front();
                }
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
    vector<int> nums = {5, 4, 2, 4};
    cout << sol.continuousSubarrays(nums) << endl;
    nums = {1, 2, 3};
    cout << sol.continuousSubarrays(nums) << endl;
    return 0;
}
