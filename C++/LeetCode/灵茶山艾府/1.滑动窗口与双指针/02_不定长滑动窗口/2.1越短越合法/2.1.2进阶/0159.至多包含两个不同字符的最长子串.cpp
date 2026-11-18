/*
给定字符串 s，求最多包含两种不同字符的最长连续子串的长度。
同一种字符在子串中可以出现任意多次。

示例 1
输入：s = "eceba"
输出：3
可以选择 "ece"。

示例 2
输入：s = "ccaabbb"
输出：5
可以选择 "aabbb"。

题目链接：https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/
题面参考：https://leetcode.doocs.org/lc/159/（会员题）
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// 用频次数组维护窗口内各字符的次数。频次从 0 变为 1 时，窗口新增一种字符。
// 出现第三种字符时收缩左端，直到重新符合条件。
// 时间复杂度 O(n)，窗口额外空间 O(字符集大小)。
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int count[UCHAR_MAX + 1] = {};
        int n = s.size();
        int distinct = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            unsigned char incoming = s[right];
            count[incoming] += 1;
            if (count[incoming] == 1)
            {
                distinct += 1;
            }
            while (distinct > 2)
            {
                unsigned char outgoing = s[left];
                count[outgoing] -= 1;
                if (count[outgoing] == 0)
                {
                    distinct -= 1;
                }
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
    cout << sol.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    cout << sol.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;
    return 0;
}
