/*
求小写字符串 s 中最长的连续子串，使其中出现过的每种字母都至少出现 k 次。
不存在非空解时返回 0。

示例 1
输入：s = "aaabb", k = 3
输出：3
可以选择 "aaa"。

示例 2
输入：s = "ababbc", k = 2
输出：5
可以选择 "ababb"。

题目链接：https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 枚举窗口允许的字母种类数。超过该种类数时收缩左端。
// 分别维护窗口中出现过的字母数和频次达到 k 的字母数。两者相等时，窗口合法。
// 时间复杂度 O(26 * n)，窗口额外空间 O(26)。
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        int result = 0;
        for (int target = 1; target <= 26 && target * k <= n; target += 1)
        {
            int count[26] = {};
            int distinct = 0;
            int enough = 0;
            int left = 0;
            for (int right = 0; right < n; right += 1)
            {
                int &incoming = count[s[right] - 'a'];
                if (incoming == 0)
                {
                    distinct += 1;
                }
                incoming += 1;
                if (incoming == k)
                {
                    enough += 1;
                }
                while (distinct > target)
                {
                    int &outgoing = count[s[left] - 'a'];
                    if (outgoing == k)
                    {
                        enough -= 1;
                    }
                    outgoing -= 1;
                    if (outgoing == 0)
                    {
                        distinct -= 1;
                    }
                    left += 1;
                }
                if (enough == distinct)
                {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestSubstring("aaabb", 3) << endl;
    cout << sol.longestSubstring("ababbc", 2) << endl;
    cout << sol.longestSubstring("abc", 4) << endl;
    return 0;
}
