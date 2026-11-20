/*
求非空连续子数组的最大元素和。

示例
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6

题目链接：https://leetcode.cn/problems/maximum-subarray/
*/
#include "hot100_example.h"
#include <algorithm>
#include <limits.h>
using namespace std;

// 累计和为负时，从下一项重新开始更有利。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result)
                result = count; // 取区间累计的最大值（相当于不断确定最大子序终止位置）
            if (count <= 0)
                count = 0; // 连续和变成负数或者为0的时候重置最大子序起始位置（贪心贪在这里），因为遇到负数一定是拉低总和
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    hot100::print(sol.maxSubArray(nums));
    return 0;
}
