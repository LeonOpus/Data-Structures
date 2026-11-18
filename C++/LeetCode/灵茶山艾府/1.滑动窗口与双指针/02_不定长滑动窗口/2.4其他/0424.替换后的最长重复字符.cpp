/*
字符串 s 只含大写英文字母。每次可以把一个字符替换为任意大写字母，最多替换 k 次。
求操作后最长的连续相同字母段的长度。

示例 1
输入：s = "ABAB", k = 2
输出：4

示例 2
输入：s = "AABABBA", k = 1
输出：4

约束
1 <= s.length <= 10^5
0 <= k <= s.length

题目链接：https://leetcode.cn/problems/longest-repeating-character-replacement/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 把一个窗口变成同一字母所需的最少替换次数等于窗口长度减去其中的最高频次。
// 收缩时保留历史最高频次，窗口长度只增不减。
// 每次长度刷新，都可以从曾达到该频次的窗口出发，扩展到新长度，最多需要 k 次替换。
// 时间复杂度 O(n)，窗口额外空间 O(26)。
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int count[26] = {};
        int highest = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = count[s[right] - 'A'];
            incoming += 1;
            highest = max(highest, incoming);
            while (right - left + 1 - highest > k)
            {
                count[s[left] - 'A'] -= 1;
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
    cout << sol.characterReplacement("ABAB", 2) << endl;
    cout << sol.characterReplacement("AABABBA", 1) << endl;
    cout << sol.characterReplacement("ABBB", 0) << endl;
    return 0;
}
