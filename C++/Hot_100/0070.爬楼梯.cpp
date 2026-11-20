/*
每步可以爬一阶或两阶楼梯，求走到第 n 阶的不同走法数。

示例
输入：n = 2
输出：2

题目链接：https://leetcode.cn/problems/climbing-stairs/
*/
#include "hot100_example.h"
using namespace std;

// 到第 i 阶的方式数等于前一阶和前两阶的方式数之和。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    int climbStairs(int n)
    {
        int previous = 1;
        int current = 1;
        for (int i = 2; i <= n; ++i)
        {
            int next = previous + current;
            previous = current;
            current = next;
        }
        return current;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.climbStairs(2));
    return 0;
}
