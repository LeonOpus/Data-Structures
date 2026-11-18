/*
给定正整数数组 nums 和正整数 k。
可以删掉任意位置的元素，至少要保留一个元素。
若剩余元素的最大值不超过最小值的 k 倍，则剩余数组是平衡的。
返回让数组变平衡所需的最少删除次数。

示例 1：
输入：nums = [2,1,5], k = 2
输出：1
解释：删掉 5 后，剩余最大值 2 恰好是最小值 1 的两倍。

示例 2：
输入：nums = [1,6,2,9], k = 3
输出：2
解释：可以保留 6 和 2。

示例 3：
输入：nums = [4,6], k = 2
输出：0

提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^5

题目链接：https://leetcode.cn/problems/minimum-removals-to-balance-array/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 固定保留元素的最小值和最大值后，保留夹在两者之间的元素仍然平衡。
// 对 nums 原地排序，寻找最长的连续合法区间，答案就是总长度减去该区间长度。
// 最小值乘 k 可能超过 int 范围，比较时使用 long long。
// 排序耗时 O(n log n)，滑动窗口耗时 O(n)，窗口只用常数额外空间。
class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int longest = 0;
        for (int right = 0; right < n; right += 1)
        {
            while (nums[right] > 1LL * nums[left] * k)
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
    vector<int> nums = {2, 1, 5};
    cout << sol.minRemoval(nums, 2) << endl;
    nums = {1, 6, 2, 9};
    cout << sol.minRemoval(nums, 3) << endl;
    nums = {4, 6};
    cout << sol.minRemoval(nums, 2) << endl;
    nums = {1000000000, 100000000};
    cout << sol.minRemoval(nums, 100000) << endl;
    return 0;
}
