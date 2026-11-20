/*
求只含圆括号的字符串中，最长有效连续括号子串的长度。

示例
输入：s = "(()"
输出：2

题目链接：https://leetcode.cn/problems/longest-valid-parentheses/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// dp[i] 记录以下标 i 结尾的最长有效段。若当前右括号能跨过上一段匹配一个左括号，
// 就接上这个左括号前面的有效段。时间 O(n)，额外空间 O(n)。
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        int result = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] != ')')
            {
                continue;
            }
            int opening = i - dp[i - 1] - 1;
            if (opening >= 0 && s[opening] == '(')
            {
                dp[i] = dp[i - 1] + 2;
                if (opening > 0)
                {
                    dp[i] += dp[opening - 1];
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.longestValidParentheses("(()"));
    return 0;
}
