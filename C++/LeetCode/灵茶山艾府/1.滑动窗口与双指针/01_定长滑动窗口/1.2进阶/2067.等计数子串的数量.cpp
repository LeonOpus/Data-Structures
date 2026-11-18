/*
给定小写字母字符串 s 和正整数 count。
如果一个连续非空子串中，所有出现过的字母都分别出现 count 次，
就把它称作等计数子串。没有出现的字母不参与判断。
求 s 中等计数子串的总数，不同起始位置分别计数。

示例 1：
输入：s = "aaabcbbcc", count = 3
输出：3
解释：符合要求的子串是 "aaa"、"bcbbcc" 和 "aaabcbbcc"。

示例 2：
输入：s = "abcd", count = 2
输出：0

示例 3：
输入：s = "a", count = 5
输出：0

提示：
1 <= s.length <= 3 * 10^4
1 <= count <= 3 * 10^4
s 只含小写英文字母。

题目链接：https://leetcode.cn/problems/number-of-equal-count-substrings/
题面参考：https://leetcode.doocs.org/lc/2067/（会员题）
*/
#include <iostream>
#include <string>
using namespace std;

// 枚举子串中不同字母的数量 types，窗口长度只能是 types * count。
// 维护窗口内出现次数恰好为 count 的字母数量 equalCount。
// 当 equalCount == types 时，这些字母已经占满窗口，不可能再有其他字母。
// 时间复杂度 O(26 * n)，额外空间复杂度 O(26)。
class Solution
{
public:
    int equalCountSubstrings(string s, int count)
    {
        int n = s.size();
        int result = 0;
        for (int types = 1; types <= 26 && types * count <= n; types += 1)
        {
            int windowSize = types * count;
            int frequency[26] = {};
            int equalCount = 0;
            auto updateCount = [&](int ch, int delta)
            {
                if (frequency[ch] == count)
                {
                    equalCount -= 1;
                }
                frequency[ch] += delta;
                if (frequency[ch] == count)
                {
                    equalCount += 1;
                }
            };

            // 处理当前长度的第一个窗口
            for (int i = 0; i < windowSize; i += 1)
            {
                updateCount(s[i] - 'a', 1);
            }
            if (equalCount == types)
            {
                result += 1;
            }
            // 处理当前长度的后续窗口
            for (int i = windowSize; i < n; i += 1)
            {
                updateCount(s[i - windowSize] - 'a', -1);
                updateCount(s[i] - 'a', 1);
                if (equalCount == types)
                {
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.equalCountSubstrings("aaabcbbcc", 3) << endl;
    cout << sol.equalCountSubstrings("abcd", 2) << endl;
    cout << sol.equalCountSubstrings("a", 5) << endl;
    cout << sol.equalCountSubstrings("aaaa", 2) << endl; // 三个重叠的 "aa" 分别计数
    return 0;
}
