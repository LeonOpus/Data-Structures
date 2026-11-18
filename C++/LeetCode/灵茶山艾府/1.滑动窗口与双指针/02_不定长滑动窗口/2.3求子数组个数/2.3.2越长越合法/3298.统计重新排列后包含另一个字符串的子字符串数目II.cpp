/*
统计 word1 中有多少个非空连续子串，能通过重排列使 word2 成为它的前缀。
两个字符串都只含小写英文字母，word2 中重复出现的字母也要凑足次数。

示例 1
输入：word1 = "bcca", word2 = "abc"
输出：1

示例 2
输入：word1 = "abcabc", word2 = "abc"
输出：10

题目链接：https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/
*/
#include <iostream>
#include <string>
using namespace std;

// 只要窗口中每个字母的频次都达到 word2 的要求，就能重排得到所需前缀。
// need 保存尚需多少个该字母，负数表示有富余。missing 记录总缺口。
// 总缺口为零时收缩，固定右端贡献 left 个合法子串。
// 时间复杂度 O(n + m)，窗口额外空间 O(26)。
class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        int need[26] = {};
        for (char ch : word2)
        {
            need[ch - 'a'] += 1;
        }
        int missing = word2.size();
        int n = word1.size();
        int left = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = need[word1[right] - 'a'];
            if (incoming > 0)
            {
                missing -= 1;
            }
            incoming -= 1;
            while (missing == 0)
            {
                int &outgoing = need[word1[left] - 'a'];
                outgoing += 1;
                if (outgoing > 0)
                {
                    missing += 1;
                }
                left += 1;
            }
            result += left;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.validSubstringCount("bcca", "abc") << endl;
    cout << sol.validSubstringCount("abcabc", "abc") << endl;
    cout << sol.validSubstringCount("abcabc", "aaabc") << endl;
    return 0;
}
