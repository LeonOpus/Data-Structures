/*
给定两个等长的小写字符串 s 和 t，以及可用预算 maxCost。
把位置 i 的 s[i] 改为 t[i]，需要支付两个字符编码的差的绝对值。
选一段连续位置，使该区间内的总开销不超过预算，返回能选到的最大长度。
如果连一个位置都选不了，返回 0。

示例 1：
输入：s = "abcd", t = "bcdf", maxCost = 3
输出：3
解释：前三位各花费 1，总开销为 3。

示例 2：
输入：s = "abcd", t = "cdef", maxCost = 3
输出：1

示例 3：
输入：s = "abcd", t = "acde", maxCost = 0
输出：1

提示：
1 <= s.length == t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 只含小写英文字母。

题目链接：https://leetcode.cn/problems/get-equal-substrings-within-budget/
*/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// 扩展右端时累加开销，超出预算就从左端移出字符，直到窗口重新符合预算。
// 每个位置最多进入、离开窗口各一次，时间复杂度 O(n)，窗口额外空间 O(1)。
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        int left = 0;
        int totalCost = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            totalCost += abs(s[right] - t[right]);
            while (totalCost > maxCost)
            {
                totalCost -= abs(s[left] - t[left]);
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
    cout << sol.equalSubstring("abcd", "bcdf", 3) << endl;
    cout << sol.equalSubstring("abcd", "cdef", 3) << endl;
    cout << sol.equalSubstring("abcd", "acde", 0) << endl;
    cout << sol.equalSubstring("abc", "bcd", 0) << endl;
    return 0;
}
