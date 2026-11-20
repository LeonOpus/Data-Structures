/*
在整数数组中找出排序后第 k 大的元素。重复值各占一个名次。

示例
输入：nums = [3,2,1,5,6,4], k = 2
输出：5

题目链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 把按升序排列时下标 n - k 的元素定位到它的最终位置。nth_element 平均 O(n)。
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        auto rank = nums.end() - k;
        nth_element(nums.begin(), rank, nums.end());
        return *rank;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    hot100::print(sol.findKthLargest(nums, 2));
    return 0;
}
