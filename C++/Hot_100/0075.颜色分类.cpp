/*
原地将只包含 0、1、2 的数组按升序排列。

示例
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

题目链接：https://leetcode.cn/problems/sort-colors/
*/
#include "hot100_example.h"
#include <utility>
using namespace std;

// 用两个边界分隔 0 和 2。当前值为 2 时换到右边，交换来的值仍需检查。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0;
        int current = 0;
        int right = int(nums.size()) - 1;
        while (current <= right)
        {
            if (nums[current] == 0)
            {
                swap(nums[current], nums[left]);
                ++left;
                ++current;
            }
            else if (nums[current] == 2)
            {
                swap(nums[current], nums[right]);
                --right;
            }
            else
            {
                ++current;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    hot100::print(nums);
    return 0;
}
