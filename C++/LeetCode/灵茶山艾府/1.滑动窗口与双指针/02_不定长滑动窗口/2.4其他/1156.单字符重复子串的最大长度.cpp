/*
给定一个小写字符串 text。可以交换其中任意两个位置的字符一次，也可以不交换。
求交换后只由同一个字母组成的最长连续子串的长度。

示例 1
输入：text = "ababa"
输出：3

示例 2
输入：text = "aaabaaa"
输出：6

示例 3
输入：text = "aaabbaaa"
输出：4

约束
1 <= text.length <= 2 * 10^4

题目链接：https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 遍历相同字母组成的连续段。如果后面隔一个字符又是同一字母，可以尝试把两段接起来。
// 候选长度最多是两段已有字母数加一，也不能超过该字母在整个字符串里的总数。
// 每个位置最多被扫描两次，时间复杂度 O(n)，窗口额外空间 O(26)。
class Solution
{
public:
    int maxRepOpt1(string text)
    {
        int total[26] = {};
        for (char ch : text)
        {
            total[ch - 'a'] += 1;
        }

        int n = text.size();
        int result = 0;
        int start = 0;
        while (start < n)
        {
            char ch = text[start];
            int end = start + 1;
            while (end < n && text[end] == ch)
            {
                end += 1;
            }

            int next = end + 1;
            int nextEnd = next;
            while (nextEnd < n && text[nextEnd] == ch)
            {
                nextEnd += 1;
            }
            int joined = end - start + nextEnd - next;
            result = max(result, min(joined + 1, total[ch - 'a']));
            start = end;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxRepOpt1("ababa") << endl;
    cout << sol.maxRepOpt1("aaabaaa") << endl;
    cout << sol.maxRepOpt1("aaabbaaa") << endl;
    cout << sol.maxRepOpt1("aaaaa") << endl;
    cout << sol.maxRepOpt1("abcdef") << endl;
    return 0;
}
