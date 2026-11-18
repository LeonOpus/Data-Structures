/*
若 nums 的一个非空连续子数组恰好包含 k 个奇数，就称它是优美子数组。
求优美子数组的总数。

示例 1
输入：nums = [1,1,2,1,1], k = 3
输出：2

示例 2
输入：nums = [2,4,6], k = 1
输出：0

题目链接：https://leetcode.cn/problems/count-number-of-nice-subarrays/
*/
#include <iostream>
#include <vector>
using namespace std;

// 每个奇数给窗口计数加一，偶数不改变计数。
// 滑窗分别计算奇数个数至多为 k、k - 1 的子数组数，然后求差。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
private:
    int countAtMost(const vector<int> &nums, int limit)
    {
        int n = nums.size();
        int left = 0;
        int odds = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            odds += nums[right] % 2;
            while (odds > limit)
            {
                odds -= nums[left] % 2;
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    cout << sol.numberOfSubarrays(nums, 3) << endl;
    nums = {2, 4, 6};
    cout << sol.numberOfSubarrays(nums, 1) << endl;
    nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << sol.numberOfSubarrays(nums, 2) << endl;
    return 0;
}
