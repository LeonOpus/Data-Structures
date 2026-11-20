/*
给定旋转过的严格递增数组，返回其中的最小值。

示例
输入：nums = [3,4,5,1,2]
输出：1

题目链接：https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
*/
#include "hot100_example.h"
using namespace std;

// 中点比右端大时，最小值在中点右侧，否则在中点或其左侧。时间 O(log n)，额外空间 O(1)。
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = int(nums.size()) - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    hot100::print(sol.findMin(nums));
    return 0;
}
