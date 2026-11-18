/*
在正整数数组 nums 中，找最长的连续子数组，使其元素乘积等于最小公倍数乘最大公因数。
数组至少有两个元素，且每个元素都在 [1, 10] 内。

示例 1
输入：nums = [1,2,1,2,1,1,1]
输出：5

示例 2
输入：nums = [2,3,4,5,6]
输出：3

题目链接：https://leetcode.cn/problems/maximum-subarray-with-equal-products/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 任意两个正整数的乘积都等于它们的最小公倍数乘最大公因数，因此答案至少是 2。
// 长度至少为 3 时，对每个质因数，将各元素的指数升序排列。等式要求指数总和等于首尾指数之和，
// 也就是所有中间指数都为 0。因此每种质因数最多出现在一个元素中。
// 用四位掩码表示质因数 2、3、5、7。窗口内掩码不重叠时，可以异或移除左端。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    int maxLength(vector<int> &nums)
    {
        const int primeMask[11] = {0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5};
        int n = nums.size();
        int left = 0;
        int mask = 0;
        int result = 2;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = primeMask[nums[right]];
            while ((mask & incoming) != 0)
            {
                mask ^= primeMask[nums[left]];
                left += 1;
            }
            mask |= incoming;
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};
    cout << sol.maxLength(nums) << endl;
    nums = {2, 3, 4, 5, 6};
    cout << sol.maxLength(nums) << endl;
    nums = {1, 2, 3, 1, 4, 5, 1};
    cout << sol.maxLength(nums) << endl;
    return 0;
}
