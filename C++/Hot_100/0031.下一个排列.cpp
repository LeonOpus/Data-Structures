/*
将 nums 原地变为字典序中的下一个排列。若当前已是最大排列，就改成最小排列。

示例
输入：nums = [1,2,3]
输出：[1,3,2]

题目链接：https://leetcode.cn/problems/next-permutation/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 从右边找第一个可增大的位置，换成右侧比它大的最小值，然后把后缀恢复为升序。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pivot = n - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
        {
            --pivot;
        }
        if (pivot >= 0)
        {
            int successor = n - 1;
            while (nums[successor] <= nums[pivot])
            {
                --successor;
            }
            swap(nums[pivot], nums[successor]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    hot100::print(nums);
    return 0;
}
