/*
找出元素乘积最大的非空连续子数组，返回它的乘积。

示例
输入：nums = [2,3,-2,4]
输出：6

题目链接：https://leetcode.cn/problems/maximum-product-subarray/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 负数相乘会翻转大小关系，因此同时维护以当前位置结尾的最大和最小乘积。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int largest = nums.front();
        int smallest = nums.front();
        int result = largest;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            int value = nums[i];
            int a = largest * value;
            int b = smallest * value;
            largest = max(value, max(a, b));
            smallest = min(value, min(a, b));
            result = max(result, largest);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    hot100::print(sol.maxProduct(nums));
    return 0;
}
