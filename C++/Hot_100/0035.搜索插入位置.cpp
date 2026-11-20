/*
在升序数组中寻找 target。未找到时返回保持有序的插入下标。

示例
输入：nums = [1,3,5,6], target = 5
输出：2

题目链接：https://leetcode.cn/problems/search-insert-position/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 寻找第一个大于等于 target 的位置。时间 O(log n)，额外空间 O(1)。
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    hot100::print(sol.searchInsert(nums, 5));
    return 0;
}
