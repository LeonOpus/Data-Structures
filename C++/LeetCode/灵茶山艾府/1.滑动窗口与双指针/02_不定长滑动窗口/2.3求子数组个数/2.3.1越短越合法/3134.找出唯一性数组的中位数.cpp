/*
对 nums 的每个非空连续子数组，记录其不同元素的个数。
将所有记录排序，求中位数。记录数为偶数时取中间两项中较小的一项。

示例 1
输入：nums = [1,2,3]
输出：1

示例 2
输入：nums = [3,4,3,4,5]
输出：2

题目链接：https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 设总共有 T 个子数组，目标是排序后第 (T + 1) / 2 小的值。
// 二分不同元素数的上限，每次用滑窗数出不超过该上限的子数组数量。
// 第一个使计数达到目标排名的上限就是答案。
// 平均时间复杂度 O(n log n)，额外空间 O(n)。
class Solution
{
private:
    bool reachesRank(const vector<int> &nums, int limit, long long rank)
    {
        unordered_map<int, int> count;
        int n = nums.size();
        int distinct = 0;
        int left = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = count[nums[right]];
            incoming += 1;
            if (incoming == 1)
            {
                distinct += 1;
            }
            while (distinct > limit)
            {
                int &outgoing = count[nums[left]];
                outgoing -= 1;
                if (outgoing == 0)
                {
                    distinct -= 1;
                }
                left += 1;
            }
            result += right - left + 1;
            if (result >= rank)
            {
                return true;
            }
        }
        return false;
    }

public:
    int medianOfUniquenessArray(vector<int> &nums)
    {
        int n = nums.size();
        long long total = 1LL * n * (n + 1) / 2;
        long long rank = (total + 1) / 2;
        int low = 1;
        int high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (reachesRank(nums, mid, rank))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.medianOfUniquenessArray(nums) << endl;
    nums = {3, 4, 3, 4, 5};
    cout << sol.medianOfUniquenessArray(nums) << endl;
    nums = {4, 3, 5, 4};
    cout << sol.medianOfUniquenessArray(nums) << endl;
    return 0;
}
