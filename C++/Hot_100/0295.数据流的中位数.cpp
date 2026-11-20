/*
设计支持不断插入整数、随时查询当前中位数的数据结构。

示例
输入：依次加入 1、2 后查询，再加入 3 并查询。
输出：[1.5,2.0]

题目链接：https://leetcode.cn/problems/find-median-from-data-stream/
*/
#include "hot100_example.h"
#include <functional>
#include <queue>
using namespace std;

// 较小的一半放进大顶堆，较大的一半放进小顶堆。每次插入后调整大小，两堆顶给出中间值。
// 插入 O(log n)，查询 O(1)，额外空间 O(n)。
class MedianFinder
{
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

public:
    void addNum(int num)
    {
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        if (lower.size() > upper.size() + 1)
        {
            upper.push(lower.top());
            lower.pop();
        }
        else if (upper.size() > lower.size())
        {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian()
    {
        if (lower.size() > upper.size())
        {
            return lower.top();
        }
        return (static_cast<double>(lower.top()) + upper.top()) / 2;
    }
};

int main()
{
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    vector<double> result = {finder.findMedian()};
    finder.addNum(3);
    result.push_back(finder.findMedian());
    hot100::print(result);
    return 0;
}
