/*
从数组的第一个位置出发，每个值表示可向前跳跃的最大距离。判断能否到达最后一个位置。

示例
输入：nums = [2,3,1,1,4]
输出：true

题目链接：https://leetcode.cn/problems/jump-game/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 只扫描可达位置，并用它们更新目前能达到的最远位置。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        int n = nums.size();
        for (int i = 0; i < n && i <= farthest; ++i)
        {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    hot100::print(sol.canJump(nums));
    return 0;
}
