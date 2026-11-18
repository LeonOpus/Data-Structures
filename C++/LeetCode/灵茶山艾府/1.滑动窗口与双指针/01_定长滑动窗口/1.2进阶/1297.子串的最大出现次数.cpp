/*
在小写字母字符串 s 中，考虑长度位于 [minSize, maxSize] 的所有连续子串。
只统计不同字母数量不超过 maxLetters 的子串，求同一个子串最多出现多少次。
不同出现位置可以重叠；如果没有符合条件的子串，返回 0。

示例 1：
输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
输出：2
解释："aab" 出现两次，而且只包含两种字母。

示例 2：
输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
输出：2
解释：两个 "aaa" 的出现位置可以重叠。

示例 3：
输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
输出：3

示例 4：
输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
输出：0

提示：
1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s 只含小写英文字母。

题目链接：https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 较长的合法子串每出现一次，它长度为 minSize 的前缀也会出现一次。
// 因此只需枚举长度为 minSize 的窗口，用哈希表统计每个合法子串的出现次数。
// 设 n 为字符串长度，平均时间复杂度 O(n * minSize)，额外空间复杂度 O(n * minSize)。
class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        (void)maxSize; // 只需要检查最短长度，较长子串不会得到更大的出现次数
        int n = s.size();
        int count[26] = {};
        int distinct = 0;
        int result = 0;
        unordered_map<string, int> frequency;

        // 处理第一个窗口
        for (int i = 0; i < minSize; i += 1)
        {
            if (count[s[i] - 'a'] == 0)
            {
                distinct += 1;
            }
            count[s[i] - 'a'] += 1;
        }
        if (distinct <= maxLetters)
        {
            result = ++frequency[s.substr(0, minSize)];
        }
        // 处理后续窗口
        for (int i = minSize; i < n; i += 1)
        {
            int outgoing = s[i - minSize] - 'a';
            count[outgoing] -= 1;
            if (count[outgoing] == 0)
            {
                distinct -= 1;
            }
            int incoming = s[i] - 'a';
            if (count[incoming] == 0)
            {
                distinct += 1;
            }
            count[incoming] += 1;
            if (distinct <= maxLetters)
            {
                int times = ++frequency[s.substr(i - minSize + 1, minSize)];
                result = max(result, times);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxFreq("aababcaab", 2, 3, 4) << endl;
    cout << sol.maxFreq("aaaa", 1, 3, 3) << endl;
    cout << sol.maxFreq("aabcabcab", 2, 2, 3) << endl;
    cout << sol.maxFreq("abcde", 2, 3, 3) << endl;
    return 0;
}
