/*
若一个子串中出现过的每种字母都同时拥有大写和小写形式，则它是美好的。
求最长的美好子串。有多个同长度答案时取最先出现的一个，没有则返回空字符串。

示例 1
输入：s = "YazaAay"
输出："aAa"

示例 2
输入：s = "dDzeE"
输出："dD"
"dD" 和 "eE" 一样长，但 "dD" 更早出现。

题目链接：https://leetcode.cn/problems/longest-nice-substring/
*/
#include <iostream>
#include <string>
using namespace std;

// 枚举窗口允许的字母种类数，大小写归到同一种字母。超过这一限制就移动左端。
// 窗口中每种字母都有两种大小写时即可更新答案。长度相同的窗口比较起点。
// 时间复杂度 O(26 * n)，窗口额外空间 O(26)，不计返回字符串。
class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        int n = s.size();
        int bestStart = 0;
        int bestLength = 0;
        for (int target = 1; target <= 26 && 2 * target <= n; target += 1)
        {
            int count[26][2] = {};
            int distinct = 0;
            int paired = 0;
            auto update = [&](char ch, int change)
            {
                bool upper = ch >= 'A' && ch <= 'Z';
                int letter = upper ? ch - 'A' : ch - 'a';
                int &frequency = count[letter][upper];
                int other = count[letter][!upper];

                bool wasPresent = frequency > 0;
                frequency += change;
                bool isPresent = frequency > 0;
                if (other > 0)
                {
                    paired += isPresent - wasPresent;
                }
                else
                {
                    distinct += isPresent - wasPresent;
                }
            };

            int left = 0;
            for (int right = 0; right < n; right += 1)
            {
                update(s[right], 1);
                while (distinct > target)
                {
                    update(s[left], -1);
                    left += 1;
                }
                int length = right - left + 1;
                if (paired == distinct &&
                    (length > bestLength || (length == bestLength && left < bestStart)))
                {
                    bestStart = left;
                    bestLength = length;
                }
            }
        }
        return s.substr(bestStart, bestLength);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestNiceSubstring("YazaAay") << endl;
    cout << sol.longestNiceSubstring("Bb") << endl;
    cout << sol.longestNiceSubstring("c") << endl;
    cout << sol.longestNiceSubstring("dDzeE") << endl;
    return 0;
}
