/*
给你一个下标从 0 开始的字符串 s ，这个字符串只包含 0 到 9 的数字字符。

如果一个字符串 t 中至多有一对相邻字符是相等的，那么称这个字符串 t 是 半重复的 。
例如，"0010" 、"002020" 、"0123" 、"2002" 和 "54944" 是半重复字符串，
而 "00101022" （相邻的相同数字对是 00 和 22）和 "1101234883" （相邻的相同数字对是 11 和 88）不是半重复字符串。
请你返回 s 中最长 半重复 子字符串 的长度。

示例 1：
输入：s = "52233"
输出：4
解释：
最长的半重复子字符串是 "5223"。整个字符串 "52233" 有两个相邻的相同数字对 22 和 33，但最多只能选取一个。

示例 2：
输入：s = "5494"
输出：4
解释：
s 是一个半重复字符串。

示例 3：
输入：s = "1111111"
输出：2
解释：
最长的半重复子字符串是 "11"。子字符串 "111" 有两个相邻的相同数字对，但最多允许选取一个。
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 右端形成第二对相等相邻字符时，移动左端，直到移出第一对。
// 两个指针都只向右移动，时间复杂度 O(n)，窗口额外空间 O(1)。
class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int n = s.size();
        int result = 1;
        int left = 0;
        int equalPairs = 0;
        for (int right = 1; right < n; right += 1)
        {
            if (s[right] == s[right - 1])
            {
                equalPairs += 1;
            }
            if (equalPairs > 1)
            {
                left += 1;
                while (s[left] != s[left - 1])
                {
                    left += 1;
                }
                equalPairs = 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
int main()
{
    Solution sol;
    cout << sol.longestSemiRepetitiveSubstring("52233") << endl;
    cout << sol.longestSemiRepetitiveSubstring("5494") << endl;
    cout << sol.longestSemiRepetitiveSubstring("1111111") << endl;
    return 0;
}
