/*
每个值表示从该位置可跳跃的最大距离。已知最后一个位置可达，求到达它的最少跳数。

示例
输入：nums = [2,3,1,1,4]
输出：2

题目链接：https://leetcode.cn/problems/jump-game-ii/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 当前跳数覆盖一个区间，扫描这个区间来计算下一步能到达的最远边界。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;
        int result = 0;
        int cur_cover = 0;  // 当前覆盖的最远距离下标
        int next_cover = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size(); i += 1)
        {
            next_cover = max(nums[i] + i, next_cover); // 收集下一步覆盖最远距离
            if (i == cur_cover)
            {                                      // 走到当前覆盖边界,即遇到当前覆盖最远距离下标
                result+=1;                         // 必须需要走下一步，所以result+=1
                cur_cover = next_cover;           // 更新当前覆盖最远距离下标（相当于加油了）
                if (cur_cover >= nums.size() - 1) // 当前覆盖最远距到达集合终点，不用做++操作了，直接结束
                    break;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    hot100::print(sol.jump(nums));
    return 0;
}
