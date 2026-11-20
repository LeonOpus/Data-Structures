/*
长度为 n + 1 的数组中，每个值在 1 至 n 之间，且只有一个值重复。找出这个值。

示例
输入：nums = [1,3,4,2,2]
输出：2

题目链接：https://leetcode.cn/problems/find-the-duplicate-number/
*/
#include "hot100_example.h"
using namespace std;

// 把 i → nums[i] 看成指针。由下标 0 出发进入环，入环点有两条入边，对应重复值。
// 用快慢指针定位入口。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int entry = 0;
        while (entry != slow)
        {
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    hot100::print(sol.findDuplicate(nums));
    return 0;
}
