/*
给定字符串 s 和非负整数 k，求最长的连续子串长度，使它包含的字符种类数至多为 k。
k 为 0 时，最长合法长度为 0。

示例 1
输入：s = "eceba", k = 2
输出：3

示例 2
输入：s = "aa", k = 1
输出：2

题目链接：https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/
题面参考：https://leetcode.doocs.org/lc/340/（会员题）
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// 维护窗口内每个字符的频次和不同字符数。新增种类使窗口超出 k 时，移动左端直至合法。
// 时间复杂度 O(n)，窗口额外空间 O(字符集大小)。
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int count[UCHAR_MAX + 1] = {};
        int n = s.size();
        int distinct = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            unsigned char incoming = s[right];
            count[incoming] += 1;
            if (count[incoming] == 1)
            {
                distinct += 1;
            }
            while (distinct > k)
            {
                unsigned char outgoing = s[left];
                count[outgoing] -= 1;
                if (count[outgoing] == 0)
                {
                    distinct -= 1;
                }
                left += 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
    cout << sol.lengthOfLongestSubstringKDistinct("aa", 1) << endl;
    cout << sol.lengthOfLongestSubstringKDistinct("abc", 0) << endl;
    return 0;
}
