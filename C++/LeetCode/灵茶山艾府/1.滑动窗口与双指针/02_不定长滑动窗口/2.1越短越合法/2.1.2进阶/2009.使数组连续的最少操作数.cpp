/*
每次可把 nums 中的一个元素替换成任意整数。
若所有元素互异，而且最大值与最小值相差 nums.length - 1，就称数组连续。
求使数组连续所需的最少操作数。

示例 1
输入：nums = [4,2,5,3]
输出：0

示例 2
输入：nums = [1,2,3,5,6]
输出：1
把 6 改为 4 即可。

题目链接：https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 目标数组恰好占据一个长度为原数组长度 n 的整数区间。
// 先排序去重，每个值最多保留一份。找最大值与最小值相差至多 n - 1 的最长区间。
// 最少操作数等于 n 减去保留元素个数。时间复杂度 O(n log n)，滑窗额外空间 O(1)。
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int distinct = unique(nums.begin(), nums.end()) - nums.begin();
        int left = 0;
        int longest = 0;
        for (int right = 0; right < distinct; right += 1)
        {
            while (nums[right] - nums[left] >= n)
            {
                left += 1;
            }
            longest = max(longest, right - left + 1);
        }
        return n - longest;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 5, 3};
    cout << sol.minOperations(nums) << endl;
    nums = {1, 2, 3, 5, 6};
    cout << sol.minOperations(nums) << endl;
    nums = {1, 10, 100, 1000};
    cout << sol.minOperations(nums) << endl;
    return 0;
}
