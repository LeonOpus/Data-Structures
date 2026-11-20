/*
给定整数数组 nums，统计元素和恰好为 k 的连续非空子数组。

示例
输入：nums = [1,1,1], k = 2
输出：2

题目链接：https://leetcode.cn/problems/subarray-sum-equals-k/
*/
#include "hot100_example.h"
#include <unordered_map>
using namespace std;

// 遍历前缀和。若当前和为 sum，之前每个和为 sum - k 的前缀都对应一个答案。
// 时间复杂度平均 O(n)，额外空间 O(n)。
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int result = 0;              // 记录合法子数组的个数
        unordered_map<int, int> map; // 记录 <某个前缀和, 它出现的次数>
        int sum = 0;                 // 当前一路累加的总和
        map[sum] = 1;                // 比如刚开始还没加任何数时，前缀和为 0，默认算出现过 1 次
        for (int i = 0; i < nums.size(); i += 1)
        {
            sum += nums[i];                     // 累加当前数字
            if (map.find(sum - k) != map.end()) // 核心：查一下哈希表里，有没有出现过 (sum - k)
            {
                result += map[sum - k]; // 出现过几次，就说明有几个合法的连续子数组
            }
            map[sum] += 1; // 把当前的总和记到本子上，次数 +1
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1};
    hot100::print(sol.subarraySum(nums, 2));
    return 0;
}
