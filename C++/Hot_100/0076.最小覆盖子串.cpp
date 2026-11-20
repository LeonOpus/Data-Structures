/*
找出 s 中包含 t 中所有字符的最短连续子串。重复字符也必须达到要求的次数。找不到时返回空串。

示例
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

题目链接：https://leetcode.cn/problems/minimum-window-substring/
*/
#include "hot100_example.h"
#include <climits>
using namespace std;

// need 保存窗口还缺多少个各字符，missing 为总缺口。覆盖后尽量收缩左端。
// 只保存最优下标，最后截取一次。时间 O(n + m)，窗口额外空间 O(字符集大小)。
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int need[UCHAR_MAX + 1] = {};
        for (unsigned char ch : t)
        {
            ++need[ch];
        }
        int missing = t.size();
        int n = s.size();
        int left = 0;
        int start = 0;
        int length = n + 1;
        for (int right = 0; right < n; ++right)
        {
            unsigned char ch = s[right];
            if (need[ch]-- > 0)
            {
                --missing;
            }
            while (missing == 0)
            {
                if (right - left + 1 < length)
                {
                    start = left;
                    length = right - left + 1;
                }
                if (++need[static_cast<unsigned char>(s[left++])] > 0)
                {
                    ++missing;
                }
            }
        }
        return length > n ? "" : s.substr(start, length);
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.minWindow("ADOBECODEBANC", "ABC"));
    return 0;
}
