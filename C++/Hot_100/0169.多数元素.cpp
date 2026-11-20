/*
找出出现次数严格超过数组长度一半的元素。题目保证它存在。

示例
输入：nums = [3,2,3]
输出：3

题目链接：https://leetcode.cn/problems/majority-element/
*/
#include "hot100_example.h"
using namespace std;

// 投票时将不同值成对抵消，数量超过一半的元素无法被完全抵消。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int votes = 0;
        for (int value : nums)
        {
            if (votes == 0)
            {
                candidate = value;
            }
            votes += value == candidate ? 1 : -1;
        }
        return candidate;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 3};
    hot100::print(sol.majorityElement(nums));
    return 0;
}
