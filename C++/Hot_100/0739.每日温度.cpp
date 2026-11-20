/*
对每一天，返回还要等几天才有更高温度。后续没有更高温度则返回 0。

示例
输入：temperatures = [73,74,75,71,69,72,76,73]
输出：[1,1,4,2,1,1,0,0]

题目链接：https://leetcode.cn/problems/daily-temperatures/
*/
#include "hot100_example.h"
#include <stack>
using namespace std;

// 栈保存尚未找到更高温度的日期下标。新温度更高时结算栈顶的等待天数。时间和额外空间均为 O(n)。
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> pending;
        for (int day = 0; day < n; ++day)
        {
            while (!pending.empty() && temperatures[pending.top()] < temperatures[day])
            {
                int earlier = pending.top();
                pending.pop();
                result[earlier] = day - earlier;
            }
            pending.push(day);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    hot100::print(sol.dailyTemperatures(temperatures));
    return 0;
}
