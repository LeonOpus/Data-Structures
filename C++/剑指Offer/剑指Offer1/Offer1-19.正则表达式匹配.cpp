/* > 题目难度: 困难
> [原题链接](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)
题目描述
请实现一个函数用来匹配包含`.`和`*`的正则表达式。
模式中的字符`.`表示任意一个字符，而`*`表示它前面的字符可以出现任意次（含 0 次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串`"aaa"`与模式`"a.a"`和`"ab*ac*a"`匹配，但与`"aa.a"`和`"ab*a"`均不匹配。
题目样例
示例 1
输入
s = "aa"
p = "a"
输出
false
解释
"a" 无法匹配 "aa" 整个字符串。
示例 2
输入
s = "aa"
p = "a*"
输出
true
解释
因为 `*` 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3
输入
s = "aab"
p = "c*a*b"
输出
true
解释
因为 `*` 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
题目思考
1. 如何特殊处理`.`和`*`?
解决方案
思路
分析
- 分析题目, 特殊字符只有`.`和`*`. `.`比较简单, 直接可以跟任何字符匹配; 而`*`则要考虑前一个字符是什么.
- 要判断两个字符串是否匹配, 最简单的做法就是双指针依次比较即可, 这里也不例外.
- 我们需要维护当前 `s` 和 `p` 的下标 `i` 和 `j`, 然后从起点开始匹配, 分为以下几种情况分析:
  1. 边界情况 1: `p` 的字符已经用完, 即 `j == len(p)`. 此时只有当 `s` 也恰好匹配完, 才表明两个字符串匹配;
  2. 边界情况 2: `s` 的字符已经用完, 即 `i == len(s)`. 这种情况下, 如果 `p` 也恰好匹配完显然匹配; 但 `p` 没有用完的时候也可能匹配. 这是因为有`*`的存在, 它和它前一个字符可以只匹配 0 次, 这就意味着只有当前 `p` 之后的字符串满足`x*x*`这样的形式就也可以匹配;
  3. 此时 `p` 和 `s` 的字符都还有剩余, 这时候不能简单比较 `s[i]` 和 `p[j]`, 这是因为有`*`的存在, 需要继续细分为两种情况:
     1. 如果 `p[j+1]` 存在且为`*`: 此时`s[i]` 可以直接跳到与`p[j+2]`匹配, 表示不用当前的`x*`组合; 当然也可以 `j` 不动而 `i` 继续后移 (前提是`s[i]` 和 `p[j]`匹配)
     2. 否则的话意味不能跳过, 必须比较 `s[i]` 和 `p[j]`, 只有`p[j]`为`.`或者和`s[i]`相等时才成功匹配.
- 注意我们在判断过程中可以将`(i, j)`组合的结果保存起来, 避免重复计算, 这就是记忆化搜索的思想
实现
- 下面代码完全基于上述分析实现, 必要步骤都有详细注释
复杂度
- 时间复杂度 `O(MN)`
  - 采用了记忆化方法, 每个字符只需要计算一次匹配
- 空间复杂度 `O(MN)`
  - 需要存所有下标组合的匹配结果
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // dp[i][j] 表示 s[0..i-1] 与 p[0..j-1] 是否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // 初始化: s 为空时, p 必须是 x*x*... 的形式才能匹配
        for (int j = 2; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    // * 匹配 0 次: 跳过 x* 组合
                    dp[i][j] = dp[i][j - 2];
                    // * 匹配 1 次或多次: 前一个模式字符与 s[i-1] 匹配
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                else if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    // "aa" vs "a" => false
    cout << s.isMatch("aa", "a") << endl;
    // "aa" vs "a*" => true
    cout << s.isMatch("aa", "a*") << endl;
    // "aab" vs "c*a*b" => true
    cout << s.isMatch("aab", "c*a*b") << endl;
    // "mississippi" vs "mis*is*p*." => false
    cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
    // "" vs "" => true
    cout << s.isMatch("", "") << endl;
    // "a" vs ".*" => true
    cout << s.isMatch("a", ".*") << endl;
    return 0;
}
