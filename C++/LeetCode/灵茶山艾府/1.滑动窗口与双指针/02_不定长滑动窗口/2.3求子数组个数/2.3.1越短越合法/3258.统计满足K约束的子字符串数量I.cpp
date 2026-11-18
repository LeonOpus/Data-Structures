/*
求二进制字符串 s 中满足 K 约束的非空子串数目。
只要子串中 0 的个数或 1 的个数有任意一个不超过 k，子串就合法。

示例 1
输入：s = "10101", k = 1
输出：12

示例 2
输入：s = "1010101", k = 2
输出：25

题目链接：https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/
*/
#include <iostream>
#include <string>
using namespace std;

// 只有 0 和 1 都超过 k 时，窗口才不合法。收缩后，所有以当前右端结尾的窗口后缀都合法。
// 时间复杂度 O(n)，窗口额外空间 O(1)。
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int n = s.size();
        int count[2] = {};
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            count[s[right] - '0'] += 1;
            while (count[0] > k && count[1] > k)
            {
                count[s[left] - '0'] -= 1;
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countKConstraintSubstrings("10101", 1) << endl;
    cout << sol.countKConstraintSubstrings("1010101", 2) << endl;
    cout << sol.countKConstraintSubstrings("11111", 1) << endl;
    return 0;
}
