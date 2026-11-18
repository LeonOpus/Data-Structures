/*
给定小写字母字符串 word 和正整数 k，统计符合以下要求的连续非空子串：
子串内每一种出现过的字母都恰好出现 k 次；
子串内任意两个相邻字母的字母表序号之差的绝对值不超过 2。
不同起始位置的子串分别计数。

示例 1：
输入：word = "igigee", k = 2
输出：3
解释：符合条件的子串是 "igig"、"ee" 和 "igigee"。

示例 2：
输入：word = "aaabbbccc", k = 3
输出：6
解释：三个单字母段、两个相邻双字母段以及整个字符串都符合条件。

提示：
1 <= word.length <= 10^5
1 <= k <= word.length
word 只含小写英文字母。

题目链接：https://leetcode.cn/problems/count-complete-substrings/
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// 相邻字母差超过 2 的位置不能被合法子串跨越，先按这些位置分组。
// 每组中枚举字母种类数 types，合法子串的长度只能是 types * k。
// 用定长窗口维护恰好出现 k 次的字母数 equalCount，等于 types 时窗口合法。
// 时间复杂度 O(26 * n)，额外空间复杂度 O(26)。
class Solution
{
public:
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.size();
        int result = 0;
        int left = 0;
        while (left < n)
        {
            int right = left + 1;
            while (right < n && abs(word[right] - word[right - 1]) <= 2)
            {
                right += 1;
            }
            // 当前组为 [left, right)，组内已经满足相邻字母差的限制
            for (int types = 1; types <= 26 && types * k <= right - left; types += 1)
            {
                int windowSize = types * k;
                int count[26] = {};
                int equalCount = 0;
                auto updateCount = [&](int ch, int delta)
                {
                    if (count[ch] == k)
                    {
                        equalCount -= 1;
                    }
                    count[ch] += delta;
                    if (count[ch] == k)
                    {
                        equalCount += 1;
                    }
                };
                // 处理当前长度的第一个窗口
                for (int i = left; i < left + windowSize; i += 1)
                {
                    updateCount(word[i] - 'a', 1);
                }
                if (equalCount == types)
                {
                    result += 1;
                }
                // 处理当前长度的后续窗口
                for (int i = left + windowSize; i < right; i += 1)
                {
                    updateCount(word[i - windowSize] - 'a', -1);
                    updateCount(word[i] - 'a', 1);
                    if (equalCount == types)
                    {
                        result += 1;
                    }
                }
            }
            left = right;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countCompleteSubstrings("igigee", 2) << endl;
    cout << sol.countCompleteSubstrings("aaabbbccc", 3) << endl;
    cout << sol.countCompleteSubstrings("az", 1) << endl; // 不可跨越 'a' 和 'z' 之间的分界
    return 0;
}
