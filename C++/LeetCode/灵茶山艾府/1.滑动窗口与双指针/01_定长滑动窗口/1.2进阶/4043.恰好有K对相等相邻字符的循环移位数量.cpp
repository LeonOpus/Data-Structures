/*
字符串 s 的每一种循环移位，都由把某个前缀移到末尾得到。
前缀长度可以是 0 到 s.length - 1，因此共有 s.length 种移位方式。
对移位后的字符串，统计相邻且相同的字符对数，不把首字符和末字符算作相邻。
返回字符对数恰好等于 k 的移位方式数量。
即使不同移位方式得到相同字符串，也要分别计数。

示例 1：
输入：s = "aab", k = 1
输出：2
解释："aab" 和 "baa" 各有一对相等的相邻字符，"aba" 没有。

示例 2：
输入：s = "abca", k = 0
输出：1
解释：只有原字符串满足条件，其余移位都包含相邻的 "aa"。

提示：
2 <= s.length <= 100
0 <= k <= s.length - 1
s 只含小写英文字母。

题目链接：https://leetcode.cn/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
*/
#include <iostream>
#include <string>
using namespace std;

// 在虚拟的 s + s 上滑动长度为 n 的窗口，维护窗口内部 n - 1 条相邻边的得分。
// 每次移除旧窗口最左侧的一条边，再加入新窗口最右侧的一条边。
// 时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int countRotations(string s, int k)
    {
        int n = s.size();
        int score = 0;
        // 处理第一个窗口
        for (int i = 1; i < n; i += 1)
        {
            score += s[i - 1] == s[i];
        }
        int result = score == k;
        // 处理其余 n - 1 个窗口，各代表一种循环移位
        for (int i = n; i < 2 * n - 1; i += 1)
        {
            score -= s[i - n] == s[i - n + 1];
            score += s[(i - 1) % n] == s[i % n];
            if (score == k)
            {
                result += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countRotations("aab", 1) << endl;
    cout << sol.countRotations("abca", 0) << endl;
    cout << sol.countRotations("aaaa", 3) << endl; // 四种移位方式分别计数
    return 0;
}
