/*
给定整数数组 nums、正整数 k 和一组闭区间查询。
当查询区间内恰好有 k 种不同的值，并且每种值的出现次数均为偶数时，返回 true。
按查询顺序返回所有布尔结果。

示例 1
输入：nums = [1,2,2,1], k = 2, queries = [[0,1],[0,3],[1,2]]
输出：[false,true,false]

示例 2
输入：nums = [3,3,3], k = 1, queries = [[1,2],[0,2]]
输出：[true,false]

约束
2 <= nums.length <= 10^5
1 <= nums[i], queries.length <= 10^5
1 <= k <= nums.length

题目链接：https://leetcode.cn/problems/valid-k-unique-subarrays-i/
*/
#include <array>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 分别预处理至多 k 种和至多 k - 1 种的窗口左端。给定右端时，恰好 k 种的起点在两者之间。
// 全为偶数等价于区间两端之前的前缀拥有相同的频次奇偶状态。
// 从单个值的奇偶状态出发，逐层合并相邻值域块。用两个子块编号的有序对给父块状态编号。
// 每层重放整个数组的更新。两个子块编号都相同才复用编号，因此根编号的相等判断是精确的。
// 设 U 为最大元素，平均时间复杂度 O(n log(U + 1) + U + q)，额外空间 O(n + U)，不计返回数组。
class Solution
{
private:
    vector<int> atMostStarts(const vector<int> &nums, int limit, int maxValue)
    {
        int n = nums.size();
        vector<int> starts(n);
        vector<int> count(maxValue + 1, 0);
        int distinct = 0;
        int left = 0;
        for (int right = 0; right < n; right += 1)
        {
            if (++count[nums[right]] == 1)
            {
                distinct += 1;
            }
            while (distinct > limit)
            {
                if (--count[nums[left]] == 0)
                {
                    distinct -= 1;
                }
                left += 1;
            }
            starts[right] = left;
        }
        return starts;
    }

    vector<int> prefixParityIds(const vector<int> &nums, int maxValue)
    {
        int n = nums.size();
        vector<int> ids(n + 1, 0);
        vector<int> odd(maxValue + 1, 0);
        for (int i = 0; i < n; i += 1)
        {
            odd[nums[i]] ^= 1;
            ids[i + 1] = odd[nums[i]];
        }

        // ids[i + 1] 是第 i 次更新后，包含 nums[i] 的当前层块的编号。
        // 合并后，只有包含 nums[i] 的那个子块改变，另一个子块沿用此前的编号。
        for (int half = 1; half <= maxValue; half *= 2)
        {
            int width = 2 * half;
            vector<array<int, 2>> children(maxValue / width + 1, {0, 0});
            unordered_map<uint64_t, int> states;
            states.reserve(n + 1);
            states.emplace(0, 0); // 全偶状态在每一层都使用编号 0

            for (int i = 0; i < n; i += 1)
            {
                int value = nums[i];
                auto &child = children[value / width];
                child[(value / half) % 2] = ids[i + 1];
                uint64_t key = (uint64_t(child[0]) << 32) | uint64_t(child[1]);
                auto entry = states.emplace(key, int(states.size()));
                ids[i + 1] = entry.first->second;
            }
        }
        return ids;
    }

public:
    vector<bool> validSubarrays(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        int maxValue = 0;
        for (int value : nums)
        {
            if (value > maxValue)
            {
                maxValue = value;
            }
        }

        vector<int> wide = atMostStarts(nums, k, maxValue);
        vector<int> narrow = atMostStarts(nums, k - 1, maxValue);
        vector<int> parity = prefixParityIds(nums, maxValue);
        vector<bool> result;
        result.reserve(queries.size());
        for (const auto &query : queries)
        {
            int left = query[0];
            int right = query[1];
            result.push_back(left >= wide[right] && left < narrow[right] &&
                             parity[left] == parity[right + 1]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<int> nums = {1, 2, 2, 1};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {1, 2}};
    for (bool valid : sol.validSubarrays(nums, 2, queries))
    {
        cout << valid << endl;
    }
    nums = {3, 3, 3};
    queries = {{1, 2}, {0, 2}};
    for (bool valid : sol.validSubarrays(nums, 1, queries))
    {
        cout << valid << endl;
    }
    return 0;
}
