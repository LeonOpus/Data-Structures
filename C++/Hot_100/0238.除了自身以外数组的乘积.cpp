/*
返回一个数组，其中第 i 项是 nums 中除下标 i 以外所有元素的乘积，要求不用除法。

示例
输入：nums = [1,2,3,4]
输出：[24,12,8,6]

题目链接：https://leetcode.cn/problems/product-of-array-except-self/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 有多个零时，所有结果都是零。有一个零时，只有零的位置可能得到非零结果。
// 无零时，用结果数组保存左侧前缀积，再乘入右侧后缀积。
// 时间 O(n)，额外空间 O(1)，不计输出。
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);
        int zeroIndex = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                if (zeroIndex != -1)
                {
                    return result;
                }
                zeroIndex = i;
            }
        }
        if (zeroIndex != -1)
        {
            long long product = 1;
            for (int value : nums)
            {
                if (value != 0)
                {
                    product *= value;
                }
            }
            result[zeroIndex] = static_cast<int>(product);
            return result;
        }

        long long prefix = 1;
        for (int i = 0; i < n; ++i)
        {
            result[i] = static_cast<int>(prefix);
            prefix *= nums[i];
        }
        long long suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            result[i] = static_cast<int>(result[i] * suffix);
            suffix *= nums[i];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    hot100::print(sol.productExceptSelf(nums));
    return 0;
}
