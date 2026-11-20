/*
求两个字符串的最长公共子序列长度。子序列允许跳过字符，但必须保留相对顺序。

示例
输入：text1 = "abcde", text2 = "ace"
输出：3

题目链接：https://leetcode.cn/problems/longest-common-subsequence/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 前缀末尾字符相同时接在较短前缀的解后面，不同时可跳过任一末尾。
// 时间和额外空间均为 O(mn)。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]:表示text1[0...i-1]和text2[0...j-1]的最长公共子序列的长度
    动态规划求
    2. 确定递推关系
    dp[i][j] =
    if text1[i-1] == text2[j-1]
        dp[i-1][j-1] + 1
    else max(dp[i-1][j], dp[i][j-1])
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= text1.size(); i += 1)
        {
            for (int j = 1; j <= text2.size(); j += 1)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (text1[i - 1] != text2[j - 1])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.longestCommonSubsequence("abcde", "ace"));
    return 0;
}
