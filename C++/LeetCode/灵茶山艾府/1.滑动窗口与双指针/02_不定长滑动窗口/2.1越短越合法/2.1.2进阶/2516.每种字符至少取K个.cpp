/*
字符串 s 由 a、b、c 三种字母组成。每分钟可以从当前字符串的左端或右端取走一个字母。
求取到每种字母至少 k 个所需的最少分钟数。无法达到时返回 -1。

示例 1
输入：s = "aabaaaacaabc", k = 2
输出：8

示例 2
输入：s = "a", k = 1
输出：-1

题目链接：https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 从两端取完后，中间保留一段连续子串。窗口外的每种字符至少要剩 k 个。
// 统计窗口外的频次，右端加入的字符不足 k 个时收缩窗口。
// 求最长的可保留区间，时间复杂度 O(n)，窗口额外空间 O(1)。
class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int outside[3] = {};
        for (char ch : s)
        {
            outside[ch - 'a'] += 1;
        }
        for (int count : outside)
        {
            if (count < k)
            {
                return -1;
            }
        }

        int n = s.size();
        int left = 0;
        int longest = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = s[right] - 'a';
            outside[incoming] -= 1;
            while (outside[incoming] < k)
            {
                outside[s[left] - 'a'] += 1;
                left += 1;
            }
            longest = max(longest, right - left + 1);
        }
        return n - longest;
    }
};

int main()
{
    Solution sol;
    cout << sol.takeCharacters("aabaaaacaabc", 2) << endl;
    cout << sol.takeCharacters("a", 1) << endl;
    cout << sol.takeCharacters("abc", 0) << endl;
    return 0;
}
