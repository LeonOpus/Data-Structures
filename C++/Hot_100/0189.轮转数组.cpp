/*
将 nums 循环右移 k 位，直接修改原数组。

示例
输入：nums = [1,2,3,4,5,6,7], k = 3
输出：[5,6,7,1,2,3,4]

题目链接：https://leetcode.cn/problems/rotate-array/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 反转整个数组，再分别反转前 k 个元素和余下元素。时间 O(n)，除反转使用的常数状态外无额外空间。
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /*
        右旋转，其实就是反转的顺序改动一下，优先反转整个字符串，步骤如下：
        反转整个字符串
        反转区间为前k的子串
        反转区间为k到末尾的子串
        */
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    sol.rotate(nums, 3);
    hot100::print(nums);
    return 0;
}
