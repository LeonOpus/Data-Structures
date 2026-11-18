/*
给定 k 个非空的非递减整数列表。找一个闭区间 [a, b]，使每个列表至少有一个数落在区间内。
优先使 b - a 最小。区间宽度相同时，选择左端点更小的区间。

示例 1
输入：nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
输出：[20,24]
区间覆盖三个列表中的 24、20 和 22。

示例 2
输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
输出：[1,1]

约束
1 <= k <= 3500
每个列表包含 1 至 50 个元素，元素取值在 [-10^5, 10^5] 内。

题目链接：https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// 把所有数和它们的列表编号放到一起，再按数值排序。
// 窗口覆盖所有列表时，用左右端点更新答案，然后缩小窗口寻找更窄的区间。
// 设 N 为所有列表的元素总数，时间复杂度 O(N log N)，额外空间复杂度 O(N)。
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        vector<pair<int, int>> entries;
        for (int group = 0; group < k; group += 1)
        {
            for (int value : nums[group])
            {
                entries.emplace_back(value, group);
            }
        }
        sort(entries.begin(), entries.end());

        vector<int> count(k, 0);
        int missing = k;
        int left = 0;
        int bestLeft = entries.front().first;
        int bestRight = entries.back().first;
        int n = entries.size();
        for (int right = 0; right < n; right += 1)
        {
            int incoming = entries[right].second;
            count[incoming] += 1;
            if (count[incoming] == 1)
            {
                missing -= 1;
            }
            while (missing == 0)
            {
                int start = entries[left].first;
                int end = entries[right].first;
                int width = end - start;
                int bestWidth = bestRight - bestLeft;
                if (width < bestWidth || (width == bestWidth && start < bestLeft))
                {
                    bestLeft = start;
                    bestRight = end;
                }

                int outgoing = entries[left].second;
                count[outgoing] -= 1;
                if (count[outgoing] == 0)
                {
                    missing += 1;
                }
                left += 1;
            }
        }
        return {bestLeft, bestRight};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> result = sol.smallestRange(nums);
    cout << result[0] << " " << result[1] << endl;
    nums = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    result = sol.smallestRange(nums);
    cout << result[0] << " " << result[1] << endl;
    nums = {{-5, 5}, {-4, 6}};
    result = sol.smallestRange(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
