/*
在小写字符串 s 中找一段连续子串，要求每种字母的出现次数都不超过 2。
返回符合条件的子串的最大长度。

示例 1：
输入：s = "bcbbbcba"
输出：4
解释：末尾的 "bcba" 中，b 出现两次，c 和 a 各出现一次。

示例 2：
输入：s = "aaaa"
输出：2
解释：可以选 "aa"，任意更长的子串里 a 都会超过两次。

提示：
2 <= s.length <= 100
s 只含小写英文字母。

题目链接：https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 每次扩展右端，只有新加入的字母可能超过两次。
// 左端持续收缩直到这个字母的频次恢复到 2，再用窗口长度更新答案。
// 时间复杂度 O(n)，窗口额外空间 O(26)。
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int count[26] = {};
        int n = s.size();
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = s[right] - 'a';
            count[incoming] += 1;
            while (count[incoming] > 2)
            {
                count[s[left] - 'a'] -= 1;
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
    cout << sol.maximumLengthSubstring("bcbbbcba") << endl;
    cout << sol.maximumLengthSubstring("aaaa") << endl;
    cout << sol.maximumLengthSubstring("abacada") << endl;
    return 0;
}
