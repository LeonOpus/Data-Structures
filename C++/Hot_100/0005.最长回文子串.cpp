/*
返回字符串 s 中最长的连续回文子串。若有并列答案，任取一个。

示例
输入：s = "babad"
输出："bab"

题目链接：https://leetcode.cn/problems/longest-palindromic-substring/
*/
#include "hot100_example.h"
using namespace std;

// 枚举字符中心以及相邻字符间的中心，从中心向两侧扩展。时间 O(n²)，窗口额外空间 O(1)。
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int start = 0;
        int length = 0;
        auto expand = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                --left;
                ++right;
            }
            int size = right - left - 1;
            if (size > length)
            {
                start = left + 1;
                length = size;
            }
        };
        for (int center = 0; center < n; ++center)
        {
            expand(center, center);
            expand(center, center + 1);
        }
        return s.substr(start, length);
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.longestPalindrome("babad"));
    return 0;
}
