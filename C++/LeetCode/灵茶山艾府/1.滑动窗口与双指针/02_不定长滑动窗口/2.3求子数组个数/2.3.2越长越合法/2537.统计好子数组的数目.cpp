/*
在非空连续子数组中，如果至少有 k 对互不相同的下标取到同一个值，
这个子数组就是好的。每对下标只统计一次。求好子数组的个数。

示例 1
输入：nums = [1,1,1,1,1], k = 10
输出：1

示例 2
输入：nums = [3,1,4,3,2,2,4], k = 2
输出：4

题目链接：https://leetcode.cn/problems/count-the-number-of-good-subarrays/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 加入一个值时，它与窗口内现有的每个相同值各配成一对。
// 移出一个值时，删去它与剩下相同值组成的数对。
// 当配对数跌到 k 以下时，固定右端可贡献 left 个合法子数组。
// 平均时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        int left = 0;
        long long pairs = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = count[nums[right]];
            pairs += incoming;
            incoming += 1;
            while (pairs >= k)
            {
                int &outgoing = count[nums[left]];
                outgoing -= 1;
                pairs -= outgoing;
                left += 1;
            }
            result += left;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << sol.countGood(nums, 10) << endl;
    nums = {3, 1, 4, 3, 2, 2, 4};
    cout << sol.countGood(nums, 2) << endl;
    return 0;
}
