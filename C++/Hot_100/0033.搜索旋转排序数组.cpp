/*
在旋转过的严格递增数组中查找 target，返回它的下标，找不到时返回 -1。

示例
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

题目链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/
*/
#include "hot100_example.h"
using namespace std;

// 比较中点和区间端点，判断哪一半有序。用目标是否落在这一半的值域来决定保留哪一侧。
// 时间 O(log n)，额外空间 O(1)。
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = int(nums.size()) - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    hot100::print(sol.search(nums, 0));
    return 0;
}
