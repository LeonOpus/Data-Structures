/*
给定二进制字符串 s、整数 k 和多个闭区间查询 [l, r]。
对每个查询，统计完全落在该区间内的合法非空子串。
只要 0 或 1 的出现次数有任意一个不超过 k，子串就合法。

示例 1
输入：s = "0001111", k = 2, queries = [[0,6]]
输出：[26]

示例 2
输入：s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
输出：[15,9,3]

题目链接：https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 滑窗预处理每个起点的最远合法右端，以及每个右端在原串中的合法子串个数的前缀和。
// 对于查询 [l,r]，设 end 为 l 的最远合法右端与 r 中的较小者。
// [l,end] 内任意子串都合法。右端超过 end 时，合法起点都在 l 的右侧，直接用前缀和计数。
// 时间复杂度 O(n + q)，额外空间 O(n)，不计返回数组。
class Solution
{
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> lastValidEnd(n, n - 1);
        vector<long long> prefix(n + 1, 0);
        int count[2] = {};
        int left = 0;
        for (int right = 0; right < n; right += 1)
        {
            count[s[right] - '0'] += 1;
            while (count[0] > k && count[1] > k)
            {
                lastValidEnd[left] = right - 1;
                count[s[left] - '0'] -= 1;
                left += 1;
            }
            prefix[right + 1] = prefix[right] + right - left + 1;
        }

        vector<long long> result;
        result.reserve(queries.size());
        for (const auto &query : queries)
        {
            int start = query[0];
            int end = min(query[1], lastValidEnd[start]);
            long long length = end - start + 1;
            long long allValid = length * (length + 1) / 2;
            result.push_back(allValid + prefix[query[1] + 1] - prefix[end + 1]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> queries = {{0, 6}};
    cout << sol.countKConstraintSubstrings("0001111", 2, queries)[0] << endl;
    queries = {{0, 5}, {1, 4}, {2, 3}};
    vector<long long> result = sol.countKConstraintSubstrings("010101", 1, queries);
    for (long long count : result)
    {
        cout << count << endl;
    }
    return 0;
}
