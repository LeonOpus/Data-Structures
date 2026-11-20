/*
直方图的各柱宽度均为 1。求能在这些柱子下方放入的最大矩形面积。

示例
输入：heights = [2,1,5,6,2,3]
输出：10

题目链接：https://leetcode.cn/problems/largest-rectangle-in-histogram/
*/
#include "hot100_example.h"
#include <algorithm>
#include <stack>
using namespace std;

// 单调栈保存柱高递增的下标。遇到更矮的柱子时，弹出高柱并确定它能充当矩形最矮边的最大宽度。
// 尾部视为高度 0 以结算剩余柱子。时间和空间均为 O(n)。
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> increasing;
        int best = 0;
        for (int right = 0; right <= n; ++right)
        {
            int height = right == n ? 0 : heights[right];
            while (!increasing.empty() && heights[increasing.top()] >= height)
            {
                int shortest = heights[increasing.top()];
                increasing.pop();
                int left = increasing.empty() ? -1 : increasing.top();
                best = max(best, shortest * (right - left - 1));
            }
            if (right < n)
            {
                increasing.push(right);
            }
        }
        return best;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    hot100::print(sol.largestRectangleArea(heights));
    return 0;
}
