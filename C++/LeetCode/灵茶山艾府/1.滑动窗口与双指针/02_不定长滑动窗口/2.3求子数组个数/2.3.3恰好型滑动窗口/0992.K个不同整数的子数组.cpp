/*
给定正整数数组 nums，求恰好包含 k 种不同值的非空连续子数组数。
题目保证 nums[i] 不超过 nums.length。

示例 1
输入：nums = [1,2,1,2,3], k = 2
输出：7

示例 2
输入：nums = [1,2,1,3,4], k = 3
输出：3

题目链接：https://leetcode.cn/problems/subarrays-with-k-different-integers/
*/
#include <iostream>
#include <vector>
using namespace std;

// 恰好 k 种等于至多 k 种减去至多 k - 1 种。
// 每次统计至多 limit 种时，用频次数组维护窗口。种类超限就缩左端。
// 时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
private:
    int countAtMost(const vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        int distinct = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = nums[right];
            count[incoming] += 1;
            if (count[incoming] == 1)
            {
                distinct += 1;
            }
            while (distinct > limit)
            {
                int outgoing = nums[left];
                count[outgoing] -= 1;
                if (count[outgoing] == 0)
                {
                    distinct -= 1;
                }
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    cout << sol.subarraysWithKDistinct(nums, 2) << endl;
    nums = {1, 2, 1, 3, 4};
    cout << sol.subarraysWithKDistinct(nums, 3) << endl;
    nums = {1, 1, 1};
    cout << sol.subarraysWithKDistinct(nums, 1) << endl;
    return 0;
}
