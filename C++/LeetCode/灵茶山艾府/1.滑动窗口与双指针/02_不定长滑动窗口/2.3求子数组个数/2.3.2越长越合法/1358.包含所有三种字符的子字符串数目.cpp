/*
字符串 s 只由 a、b、c 组成。统计同时包含这三种字母的非空连续子串数。

示例 1
输入：s = "abcabc"
输出：10

示例 2
输入：s = "aaacb"
输出：3

题目链接：https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/
*/
#include <iostream>
#include <string>
using namespace std;

// 当窗口已经包含三种字母时，继续移走左端，直到窗口缺少某种字母。
// 此时所有小于 left 的位置都能作为合法起点，固定右端可贡献 left 个子串。
// 时间复杂度 O(n)，窗口额外空间 O(1)。
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int count[3] = {};
        int distinct = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = count[s[right] - 'a'];
            incoming += 1;
            if (incoming == 1)
            {
                distinct += 1;
            }
            while (distinct == 3)
            {
                int &outgoing = count[s[left] - 'a'];
                outgoing -= 1;
                if (outgoing == 0)
                {
                    distinct -= 1;
                }
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
    cout << sol.numberOfSubstrings("abcabc") << endl;
    cout << sol.numberOfSubstrings("aaacb") << endl;
    cout << sol.numberOfSubstrings("abc") << endl;
    return 0;
}
