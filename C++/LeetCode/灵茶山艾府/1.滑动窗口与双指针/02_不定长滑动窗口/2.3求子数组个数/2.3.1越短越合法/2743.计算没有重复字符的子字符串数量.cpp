/*
给定小写字符串 s，统计所有字符彼此不同的非空连续子串。
相同内容出现在不同位置时，按不同的子串计数。

示例 1
输入：s = "abcd"
输出：10

示例 2
输入：s = "abab"
输出：7

题目链接：https://leetcode.cn/problems/count-substrings-without-repeating-character/
题面参考：https://leetcode.doocs.org/lc/2743/（会员题）
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 记住每个字母上一次出现的下标。遇到重复字母时，左端跳过这个字母的上一次出现。
// 固定右端后，窗口内的每个位置都是合法的起点。
// 时间复杂度 O(n)，窗口额外空间 O(26)。
class Solution
{
public:
    int numberOfSpecialSubstrings(string s)
    {
        int last[26];
        fill(last, last + 26, -1);
        int n = s.size();
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int letter = s[right] - 'a';
            left = max(left, last[letter] + 1);
            last[letter] = right;
            result += right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.numberOfSpecialSubstrings("abcd") << endl;
    cout << sol.numberOfSpecialSubstrings("ooo") << endl;
    cout << sol.numberOfSpecialSubstrings("abab") << endl;
    return 0;
}
