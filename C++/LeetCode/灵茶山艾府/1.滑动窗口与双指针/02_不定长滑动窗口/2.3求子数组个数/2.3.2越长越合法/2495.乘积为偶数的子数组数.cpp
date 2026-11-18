/*
给定正整数数组 nums，统计乘积为偶数的非空连续子数组个数。

示例 1
输入：nums = [9,6,7,13]
输出：6

示例 2
输入：nums = [7,3,5]
输出：0

题目链接：https://leetcode.cn/problems/number-of-subarrays-having-even-product/
题面参考：https://leetcode.doocs.org/lc/2495/（会员题）
*/
#include <iostream>
#include <vector>
using namespace std;

// 乘积为偶数等价于区间中存在一个偶数。维护最新偶数的下标 lastEven。
// 以当前位置为右端时，起点取 [0,lastEven] 都合法，共 lastEven + 1 个。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    long long evenProduct(vector<int> &nums)
    {
        int n = nums.size();
        int lastEven = -1;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            if (nums[right] % 2 == 0)
            {
                lastEven = right;
            }
            result += lastEven + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 6, 7, 13};
    cout << sol.evenProduct(nums) << endl;
    nums = {7, 3, 5};
    cout << sol.evenProduct(nums) << endl;
    return 0;
}
