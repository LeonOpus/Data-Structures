/*
给定小写字符串 s 和正整数 k。
若非空连续子串中存在任意一个字母出现至少 k 次，就计入答案。

示例 1
输入：s = "abacb", k = 2
输出：4

示例 2
输入：s = "abcde", k = 1
输出：15

题目链接：https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/
*/
#include <iostream>
#include <string>
using namespace std;

// 扩展右端前，窗口里所有字母的频次都小于 k。只有新加入的字母可能达到 k。
// 收缩到该字母的频次小于 k 后，固定右端可贡献 left 个合法子串。
// 时间复杂度 O(n)，窗口额外空间 O(26)。
class Solution
{
public:
    int numberOfSubstrings(string s, int k)
    {
        int n = s.size();
        int count[26] = {};
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = s[right] - 'a';
            count[incoming] += 1;
            while (count[incoming] >= k)
            {
                count[s[left] - 'a'] -= 1;
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
    cout << sol.numberOfSubstrings("abacb", 2) << endl;
    cout << sol.numberOfSubstrings("abcde", 1) << endl;
    return 0;
}
