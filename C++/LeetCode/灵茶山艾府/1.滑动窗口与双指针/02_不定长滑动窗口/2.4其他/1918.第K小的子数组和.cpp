/*
给定正整数数组 nums，统计每个非空连续子数组的元素和。
将这些和从小到大排列，求第 k 项。不同子数组得到相同的和时分别计入排名。

示例 1
输入：nums = [2,1,3], k = 4
输出：3
排序后得到 [1,2,3,3,4,6]。

示例 2
输入：nums = [3,3,5,5], k = 7
输出：10

约束
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 5 * 10^4
1 <= k <= nums.length * (nums.length + 1) / 2

题目链接：https://leetcode.cn/problems/kth-smallest-subarray-sum/
题面参考：https://leetcode.doocs.org/lc/1918/（会员题）
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 对候选和 limit，滑窗统计元素和不超过 limit 的子数组数量。
// 计数随 limit 单调不减。二分寻找使计数至少为 k 的最小 limit。
// 设 S 为数组元素总和，时间复杂度 O(n log(S + 1))，额外空间 O(1)。
class Solution
{
private:
    bool reachesRank(const vector<int> &nums, long long limit, int k)
    {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        long long count = 0;
        for (int right = 0; right < n; right += 1)
        {
            sum += nums[right];
            while (sum > limit)
            {
                sum -= nums[left];
                left += 1;
            }
            count += right - left + 1;
            if (count >= k)
            {
                return true;
            }
        }
        return false;
    }

public:
    int kthSmallestSubarraySum(vector<int> &nums, int k)
    {
        long long low = *min_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (reachesRank(nums, mid, k))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return static_cast<int>(low);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3};
    cout << sol.kthSmallestSubarraySum(nums, 4) << endl;
    nums = {3, 3, 5, 5};
    cout << sol.kthSmallestSubarraySum(nums, 7) << endl;
    return 0;
}
