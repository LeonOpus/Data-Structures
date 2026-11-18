/*
在二进制字符串 s 中，找出恰好包含 k 个 1 的最短连续子串。
若有多个相同长度的候选，返回字典序最小的一段。没有候选时返回空字符串。

示例 1
输入：s = "100011001", k = 3
输出："11001"

示例 2
输入：s = "1011", k = 2
输出："11"

示例 3
输入：s = "000", k = 1
输出：""

约束
1 <= k <= s.length <= 100

题目链接：https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/
*/
#include <iostream>
#include <string>
using namespace std;

// 最短候选的首尾都是 1，否则可以删去端点处的 0。
// 枚举右端的 1，丢掉多余的 1 和左端的 0，得到当前右端对应的最短候选。
// 同长度时比较字典序。滑窗耗时 O(n)，包含比较的总时间最坏为 O(n²)。
// 窗口额外空间复杂度 O(1)，不计返回字符串。
class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        int left = 0;
        int ones = 0;
        int bestStart = 0;
        int bestLength = n + 1;
        for (int right = 0; right < n; right += 1)
        {
            if (s[right] == '0')
            {
                continue;
            }
            ones += 1;
            if (ones < k)
            {
                continue;
            }
            while (ones > k || s[left] == '0')
            {
                ones -= s[left] == '1';
                left += 1;
            }

            int length = right - left + 1;
            if (length < bestLength ||
                (length == bestLength && s.compare(left, length, s, bestStart, bestLength) < 0))
            {
                bestStart = left;
                bestLength = length;
            }
        }
        return bestLength > n ? "" : s.substr(bestStart, bestLength);
    }
};

int main()
{
    Solution sol;
    cout << sol.shortestBeautifulSubstring("100011001", 3) << endl;
    cout << sol.shortestBeautifulSubstring("1011", 2) << endl;
    cout << sol.shortestBeautifulSubstring("000", 1) << endl;
    cout << sol.shortestBeautifulSubstring("1101011", 3) << endl; // "1011" 比同长度的 "1101" 字典序小
    return 0;
}
