/*
每步可以把 nums 中的一个元素加 1 或减 1。
在最多 k 步内，求某个元素的出现次数最大能达到多少。

示例 1
输入：nums = [1,2,6,4], k = 3
输出：3
把 1、2、4 变成 2，一共花费 3 步。

示例 2
输入：nums = [1,4,4,2,4], k = 0
输出：3

题目链接：https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 排序后，可选一个连续区间作为要改成相同值的元素，因为对固定目标应优先选择离它最近的数。
// 让区间内的数都变为中位数时，总移动距离最小。用前缀和计算中位数两侧的花费。
// 时间复杂度 O(n log n)，额外空间 O(n)。前缀和及操作预算用 long long。
class Solution
{
public:
    int maxFrequencyScore(vector<int> &nums, long long k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i += 1)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        auto cost = [&](int left, int right)
        {
            int mid = left + (right - left) / 2;
            long long median = nums[mid];
            long long leftCost = median * (mid - left) - (prefix[mid] - prefix[left]);
            long long rightCost = prefix[right + 1] - prefix[mid + 1] - median * (right - mid);
            return leftCost + rightCost;
        };

        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            while (cost(left, right) > k)
            {
                left += 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 6, 4};
    cout << sol.maxFrequencyScore(nums, 3) << endl;
    nums = {1, 4, 4, 2, 4};
    cout << sol.maxFrequencyScore(nums, 0) << endl;
    return 0;
}
