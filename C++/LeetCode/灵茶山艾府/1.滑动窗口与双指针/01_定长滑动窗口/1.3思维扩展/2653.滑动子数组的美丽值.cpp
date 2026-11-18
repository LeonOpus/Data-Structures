/*
给定整数数组 nums，以及整数 k 和 x。
对每个长度为 k 的连续子数组，将其中的数值从小到大排列，重复值分别占一个位置。
若第 x 小的数为负数，就以这个负数作为窗口的美丽值；否则美丽值为 0。
按窗口从左到右的顺序，返回所有美丽值。

示例 1：
输入：nums = [1,-1,-3,-2,3], k = 3, x = 2
输出：[-1,-2,-2]

示例 2：
输入：nums = [-1,-2,-3,-4,-5], k = 2, x = 2
输出：[-1,-2,-3,-4]

示例 3：
输入：nums = [-3,1,2,-3,0,-3], k = 2, x = 1
输出：[-3,0,-3,-3,-3]

提示：
1 <= nums.length <= 10^5
1 <= k <= nums.length
1 <= x <= k
-50 <= nums[i] <= 50

题目链接：https://leetcode.cn/problems/sliding-subarray-beauty/
*/
#include <iostream>
#include <vector>
using namespace std;

// 只有负数可能成为答案，维护 [-50, -1] 这 50 个数在窗口中的频次。
// 从小到大累加频次，累计达到 x 时的数值就是第 x 小的数。
// 如果负数总数不足 x，第 x 小的数一定非负，返回 0。
// 时间复杂度 O(50 * n)，额外空间复杂度 O(50)，不计返回结果。
class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        int count[50] = {};
        vector<int> result;
        auto getBeauty = [&]()
        {
            int remaining = x;
            for (int i = 0; i < 50; i += 1)
            {
                remaining -= count[i];
                if (remaining <= 0)
                {
                    return i - 50;
                }
            }
            return 0;
        };
        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            if (nums[i] < 0)
            {
                count[nums[i] + 50] += 1;
            }
        }
        result.push_back(getBeauty());
        // 处理后续窗口
        for (int i = k; i < n; i += 1)
        {
            if (nums[i - k] < 0)
            {
                count[nums[i - k] + 50] -= 1;
            }
            if (nums[i] < 0)
            {
                count[nums[i] + 50] += 1;
            }
            result.push_back(getBeauty());
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -1, -3, -2, 3};
    vector<int> result = sol.getSubarrayBeauty(nums, 3, 2);
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;
    nums = {-1, -2, -3, -4, -5};
    result = sol.getSubarrayBeauty(nums, 2, 2);
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;
    nums = {-3, 1, 2, -3, 0, -3};
    result = sol.getSubarrayBeauty(nums, 2, 1);
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
