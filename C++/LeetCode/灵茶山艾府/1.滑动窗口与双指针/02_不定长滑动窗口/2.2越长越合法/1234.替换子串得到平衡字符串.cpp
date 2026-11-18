/*
字符串 s 只包含 Q、W、E、R，长度 n 为 4 的倍数。
可以选一段连续子串，并用任意同长度字符串替换它。
求让四种字符各出现 n / 4 次所需替换的最短长度，已经平衡时返回 0。

示例 1
输入：s = "QWER"
输出：0

示例 2
输入：s = "QQWE"
输出：1
将一个 Q 换成 R 即可。

示例 3
输入：s = "QQQW"
输出：2

约束
1 <= s.length <= 10^5，且长度是 4 的倍数。

题目链接：https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 窗口内的字符可以任意替换，窗口外各字符的频次必须不超过 n / 4。
// 满足这个条件时，各字符所缺次数之和正好等于窗口长度，可以用整个窗口补齐。
// 窗口达到条件后，移动左端尽量缩短待替换的区间。
// 时间复杂度 O(n)，窗口额外空间复杂度 O(26)。
class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size();
        int limit = n / 4;
        int outside[26] = {};
        for (char ch : s)
        {
            outside[ch - 'A'] += 1;
        }
        auto canBalance = [&]()
        {
            return outside['Q' - 'A'] <= limit && outside['W' - 'A'] <= limit &&
                   outside['E' - 'A'] <= limit && outside['R' - 'A'] <= limit;
        };
        if (canBalance())
        {
            return 0;
        }

        int left = 0;
        int result = n;
        for (int right = 0; right < n; right += 1)
        {
            outside[s[right] - 'A'] -= 1;
            while (canBalance())
            {
                result = min(result, right - left + 1);
                outside[s[left] - 'A'] += 1;
                left += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.balancedString("QWER") << endl;
    cout << sol.balancedString("QQWE") << endl;
    cout << sol.balancedString("QQQW") << endl;
    cout << sol.balancedString("QQQQ") << endl;
    return 0;
}
