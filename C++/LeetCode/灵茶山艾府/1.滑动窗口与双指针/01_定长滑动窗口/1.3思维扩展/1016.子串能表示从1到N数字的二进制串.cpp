/*
给定一个只包含 '0'、'1' 的字符串 s 和正整数 n。
检查从 1 到 n 的每个整数：它不带前导零的二进制表示，都必须在 s 中连续出现。
全部满足时返回 true，否则返回 false。不同整数对应的子串可以重叠。

示例 1：
输入：s = "0110", n = 3
输出：true
解释：1、2、3 的二进制分别是 "1"、"10"、"11"，都出现在 s 中。

示例 2：
输入：s = "0110", n = 4
输出：false
解释：4 的二进制 "100" 没有出现。

提示：
1 <= s.length <= 1000
1 <= n <= 10^9
s 的每一位都是 '0' 或 '1'。

题目链接：https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/
*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// 只需检查 (n / 2, n]：较小的数不断乘 2 后一定进入该区间，原二进制是新二进制的前缀。
// 设 power 为不超过 n 的最大 2 的幂，该区间只有两种二进制长度：
// [power, n] 的位数为 length，[n / 2 + 1, power - 1] 的位数为 length - 1。
// 分别用定长窗口检查两个区间，窗口数值通过位运算更新，用哈希集合去重。
// 设 m 为 s 的长度，平均时间复杂度 O(m)，额外空间复杂度 O(m)。
class Solution
{
private:
    bool checkRange(const string &s, int length, int lower, int upper)
    {
        if (lower > upper)
        {
            return true;
        }
        int m = s.size();
        int required = upper - lower + 1;
        if (length > m || required > m - length + 1)
        {
            return false; // 子串数量不足以表示区间中的全部整数
        }
        int mask = (1 << length) - 1;
        int value = 0;
        unordered_set<int> seen;
        // 处理第一个窗口
        for (int i = 0; i < length; i += 1)
        {
            value = (value << 1) | (s[i] - '0');
        }
        if (value >= lower && value <= upper)
        {
            seen.insert(value);
        }
        // 处理后续窗口，只保留最近 length 位
        for (int i = length; i < m; i += 1)
        {
            value = ((value << 1) & mask) | (s[i] - '0');
            if (value >= lower && value <= upper)
            {
                seen.insert(value);
            }
        }
        return int(seen.size()) == required;
    }

public:
    bool queryString(string s, int n)
    {
        int m = s.size();
        // 两种长度各最多提供 m 个窗口，无法容纳全部目标整数时直接返回。
        // 通过此判断后 n <= 4 * m，计算二进制位数的耗时也包含在 O(m) 内。
        if (n - n / 2 > 2 * m)
        {
            return false;
        }
        int power = 1;
        int length = 1;
        while (power <= n / 2)
        {
            power *= 2;
            length += 1;
        }
        return checkRange(s, length, power, n) &&
               checkRange(s, length - 1, n / 2 + 1, power - 1);
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.queryString("0110", 3) << endl;
    cout << sol.queryString("0110", 4) << endl;
    cout << sol.queryString("1", 1) << endl;
    cout << sol.queryString("0", 1) << endl;
    cout << sol.queryString("0110", 1000000000) << endl; // 大 n 可以通过窗口数量快速排除
    return 0;
}
