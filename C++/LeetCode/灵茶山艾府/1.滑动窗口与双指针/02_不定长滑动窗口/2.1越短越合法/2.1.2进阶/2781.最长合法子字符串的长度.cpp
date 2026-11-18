/*
给定小写字符串 word 和禁用字符串列表 forbidden。
合法子串不能包含列表中的任何字符串作为其连续片段。
求最长合法子串的长度。禁用字符串的长度最多为 10。

示例 1
输入：word = "cbaaaabc", forbidden = ["aaa","cb"]
输出：4

示例 2
输入：word = "leetcode", forbidden = ["de","le","e"]
输出：4

题目链接：https://leetcode.cn/problems/length-of-the-longest-valid-substring/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 扩展窗口右端后，只需检查以新字符结尾的禁用串。
// 从短到长检查这些后缀，命中最短的禁用后缀时，将左端移到它起点的后一位。
// 设 L 为最长禁用串长度，滑窗平均时间 O(n * L²)，包含构造和哈希子串的开销。
// 若禁用串总长度为 S，建表平均时间 O(S)，额外空间 O(S + L)。
class Solution
{
public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        unordered_set<string> banned(forbidden.begin(), forbidden.end());
        int limit = 0;
        for (const string &pattern : forbidden)
        {
            limit = max(limit, int(pattern.size()));
        }

        int n = word.size();
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int earliest = max(left, right - limit + 1);
            for (int start = right; start >= earliest; start -= 1)
            {
                if (banned.count(word.substr(start, right - start + 1)) > 0)
                {
                    left = start + 1;
                    break;
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> forbidden = {"aaa", "cb"};
    cout << sol.longestValidSubstring("cbaaaabc", forbidden) << endl;
    forbidden = {"de", "le", "e"};
    cout << sol.longestValidSubstring("leetcode", forbidden) << endl;
    return 0;
}
