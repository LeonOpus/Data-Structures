/*
给定仅含 0、1 的数组 nums，统计元素和恰好为 goal 的非空连续子数组。

示例 1
输入：nums = [1,0,1,0,1], goal = 2
输出：4

示例 2
输入：nums = [0,0,0,0,0], goal = 0
输出：15

题目链接：https://leetcode.cn/problems/binary-subarrays-with-sum/
*/
#include <iostream>
#include <vector>
using namespace std;

// 恰好等于 goal 的数量，等于和至多为 goal 的数量减去和至多为 goal - 1 的数量。
// 二元数组的元素非负，因此每次可以用滑窗统计所有合法后缀。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
private:
    int countAtMost(const vector<int> &nums, int limit)
    {
        if (limit < 0)
        {
            return 0;
        }

        int n = nums.size();
        int left = 0;
        int sum = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            sum += nums[right];
            while (sum > limit)
            {
                sum -= nums[left];
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << sol.numSubarraysWithSum(nums, 2) << endl;
    nums = {0, 0, 0, 0, 0};
    cout << sol.numSubarraysWithSum(nums, 0) << endl;
    return 0;
}
