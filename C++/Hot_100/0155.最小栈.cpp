/*
实现支持常数时间入栈、出栈、取栈顶和取最小值的栈。

示例
输入：依次压入 -2、0、-3，查询最小值，弹出一次，再查询栈顶和最小值。
输出：[-3,0,-2]

题目链接：https://leetcode.cn/problems/min-stack/
*/
#include "hot100_example.h"
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

// 入栈时记录当前值以及整个栈到这层为止的最小值。每次操作 O(1)，空间 O(n)。
class MinStack
{
private:
    stack<pair<int, int>> entries;

public:
    void push(int val)
    {
        int smallest = entries.empty() ? val : min(val, entries.top().second);
        entries.emplace(val, smallest);
    }

    void pop() { entries.pop(); }
    int top() { return entries.top().first; }
    int getMin() { return entries.top().second; }
};

int main()
{
    MinStack values;
    values.push(-2);
    values.push(0);
    values.push(-3);
    vector<int> result = {values.getMin()};
    values.pop();
    result.push_back(values.top());
    result.push_back(values.getMin());
    hot100::print(result);
    return 0;
}
