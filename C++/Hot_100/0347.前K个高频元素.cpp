/*
返回出现次数最多的 k 个不同整数，返回顺序任意。

示例
输入：nums = [1,1,1,2,2,3], k = 2
输出：[1,2]

题目链接：https://leetcode.cn/problems/top-k-frequent-elements/
*/
#include "hot100_example.h"
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

// 用哈希表计数，维护一个大小为 k 的最小堆来保留最高的频次。
// 设 D 为不同值数量，平均时间 O(n + D log(k + 1))，额外空间 O(D)。
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequencies;
        for (int value : nums)
        {
            ++frequencies[value];
        }
        using Entry = pair<int, int>;
        priority_queue<Entry, vector<Entry>, greater<Entry>> top;
        for (const auto &entry : frequencies)
        {
            top.emplace(entry.second, entry.first);
            if (int(top.size()) > k)
            {
                top.pop();
            }
        }
        vector<int> result;
        while (!top.empty())
        {
            result.push_back(top.top().second);
            top.pop();
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    hot100::print(sol.topKFrequent(nums, 2));
    return 0;
}
