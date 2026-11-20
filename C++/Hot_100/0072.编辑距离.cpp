/*
计算把 word1 转换成 word2 所需的最少操作数。每次可以插入、删除或替换一个字符。

示例
输入：word1 = "horse", word2 = "ros"
输出：3

题目链接：https://leetcode.cn/problems/edit-distance/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 动态规划比较两个前缀。末尾相同直接沿用对角状态，否则取增、删、换的最小代价。
// 时间和额外空间均为 O(mn)。
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示以下标[0,i-1]的word1和下标[0,j-1]的word2，将word1转换成word2的最少操作数
    2. 确定递推关系
    if(word1[i-1] == word2[j-1])
        dp[i][j] = dp[i-1][j-1]
    else
        dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1)
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;
        dp[0][0] = 0; // word1变成word2操作次数为0,和115题之前不同的地方，115题dp的含义是word1里面有多少个word2
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 无操作的情况就继承
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1); // 增删换三个状态都考虑了
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.minDistance("horse", "ros"));
    return 0;
}
