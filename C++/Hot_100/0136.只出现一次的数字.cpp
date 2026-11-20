/*
除了一个只出现一次的数之外，其余数都恰好出现两次。找出只出现一次的数。

示例
输入：nums = [2,2,1]
输出：1

题目链接：https://leetcode.cn/problems/single-number/
*/
#include "hot100_example.h"
using namespace std;

// 同一个值异或两次会抵消。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int value : nums)
        {
            result ^= value;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1};
    hot100::print(sol.singleNumber(nums));
    return 0;
}
