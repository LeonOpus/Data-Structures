/*
对一个只包含 '0' 和 '1' 的字符串 s，可以反复进行两种操作：
把首字符移到末尾，或者把某一位的 '0'、'1' 互换。
要求最终任意两个相邻字符都不同，求最少需要互换多少位。
首字符移到末尾的操作不计入答案。

示例 1：
输入：s = "111000"
输出：2
解释：可以将两位反转，得到 "101010"。

示例 2：
输入：s = "010"
输出：0

示例 3：
输入：s = "1110"
输出：1

提示：
1 <= s.length <= 10^5
s 的每一位都是 '0' 或 '1'。

题目链接：https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 所有循环移位都对应 s + s 中长度为 n 的窗口，用取模访问代替实际拼接。
// diff 记录窗口与全局交替序列 0101... 的不同位置数，另一种交替序列的代价是 n - diff。
// 时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        int diff = 0;
        // 处理第一个窗口
        for (int i = 0; i < n; i += 1)
        {
            diff += s[i] != char('0' + i % 2);
        }
        int result = min(diff, n - diff);
        // 处理其余 n - 1 个循环移位，避免重复统计原字符串
        for (int i = n; i < 2 * n - 1; i += 1)
        {
            diff -= s[i - n] != char('0' + (i - n) % 2);
            diff += s[i % n] != char('0' + i % 2);
            result = min(result, min(diff, n - diff));
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.minFlips("111000") << endl;
    cout << sol.minFlips("010") << endl;
    cout << sol.minFlips("1110") << endl;
    cout << sol.minFlips("001") << endl; // 循环移位后得到 "010"，不需要反转
    return 0;
}
