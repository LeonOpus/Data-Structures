/*
给定一个二进制字符串 s 和正整数 k。
长度为 k 的二进制串共有 2^k 种，这些字符串允许以 '0' 开头。
判断它们是否全部作为连续子串出现在 s 中，全部出现返回 true，否则返回 false。

示例 1：
输入：s = "00110110", k = 2
输出：true
解释："00"、"01"、"10"、"11" 四种字符串都出现了。

示例 2：
输入：s = "0110", k = 1
输出：true

示例 3：
输入：s = "0110", k = 2
输出：false
解释：缺少 "00"。

提示：
1 <= s.length <= 5 * 10^5
1 <= k <= 20
s 的每一位都是 '0' 或 '1'。

题目链接：https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 将长度为 k 的二进制窗口编码为 [0, 2^k - 1] 内的整数，用布尔数组标记是否出现。
// 窗口右移时左移一位、加入新位，再通过掩码保留低 k 位。
// 不同窗口的数值必须去重，重复出现的子串不能代替缺少的字符串。
// 设 m 为字符串长度，时间复杂度 O(m)，额外空间复杂度 O(2^k)。
class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int m = s.size();
        int required = 1 << k;
        if (k > m || m - k + 1 < required)
        {
            return false;
        }
        // 通过数量判断后 2^k <= m，初始化标记数组的时间也不会超过 O(m)
        vector<bool> seen(required, false);
        int found = 0;
        int value = 0;
        int mask = required - 1;
        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            value = (value << 1) | (s[i] - '0');
        }
        seen[value] = true;
        found += 1;
        // 处理后续窗口
        for (int i = k; i < m; i += 1)
        {
            value = ((value << 1) & mask) | (s[i] - '0');
            if (!seen[value])
            {
                seen[value] = true;
                found += 1;
            }
        }
        return found == required;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.hasAllCodes("00110110", 2) << endl;
    cout << sol.hasAllCodes("0110", 1) << endl;
    cout << sol.hasAllCodes("0110", 2) << endl;
    cout << sol.hasAllCodes("0", 2) << endl; // k 大于字符串长度
    return 0;
}
