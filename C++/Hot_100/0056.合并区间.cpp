/*
把所有相交的闭区间合并，返回互不重叠的区间。

示例
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]

题目链接：https://leetcode.cn/problems/merge-intervals/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 按左端点排序，依次把能重叠的区间并入最后一个区间。时间 O(n log n)。
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare); // 先排序再放入result中
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (result.back()[1] >= intervals[i][0])                       // 如果此时前一个区间的右边界大于等于后续区间的左边界则比较两个区间的右边界大小合并
                result.back()[1] = max(result.back()[1], intervals[i][1]); // 如需合并区间，则只需要更新右边界，因为排序后result.back()的左边界一定是最小值
            if (result.back()[1] < intervals[i][0])                        // 如果此时前一个区间的右边界小于后续区间的左边界则区间不重叠
                result.push_back(intervals[i]);                            // 区间不重叠就添加到result中
        }
        return result;
    }

    static bool compare(const vector<int> &a, const vector<int> &b) // 使用 const 引用，明确表示不会修改传入的 vector
    {
        return a[0] < b[0];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    hot100::print(sol.merge(intervals));
    return 0;
}
