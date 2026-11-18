/*
把小写字符串 s 中的一个连续片段切成相邻的两段，两段都非空。
当两段中的不同字母数相等时，计为一个神奇对。
按两段的起点、分割点、终点计数。相同内容出现在不同位置时分别计算。

示例 1
输入：s = "aba"
输出：2

示例 2
输入：s = "kkk"
输出：4

示例 3
输入：s = "abcac"
输出：7

题目链接：https://leetcode.cn/problems/count-magical-substring-pairs-ii/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 枚举不同字母数 d。每个右端用两个窗口得到至多 d 种与至多 d - 1 种的起点边界。
// 两条边界的差就是恰好 d 种的子串数。逆向遍历可按同样的方法得到以每个位置开头的计数。
// 对每个分割点，把以分割点结尾的左侧计数与紧随其后的右侧计数相乘。
// 时间复杂度 O(26 * n)，额外空间 O(n)。
class Solution
{
private:
    void countExact(const string &s, int distinct, int start, int stop, int step, vector<int> &ways)
    {
        int wide[26] = {};
        int narrow[26] = {};
        int wideKinds = 0;
        int narrowKinds = 0;
        int wideStart = start;
        int narrowStart = start;
        for (int i = start; i != stop; i += step)
        {
            int incoming = s[i] - 'a';
            wideKinds += (++wide[incoming] == 1);
            narrowKinds += (++narrow[incoming] == 1);
            while (wideKinds > distinct)
            {
                wideKinds -= (--wide[s[wideStart] - 'a'] == 0);
                wideStart += step;
            }
            while (narrowKinds >= distinct)
            {
                narrowKinds -= (--narrow[s[narrowStart] - 'a'] == 0);
                narrowStart += step;
            }
            ways[i] = (narrowStart - wideStart) * step;
        }
    }

public:
    long long countMagicalPairs(string s)
    {
        int n = s.size();
        bool seen[26] = {};
        int alphabetSize = 0;
        for (char ch : s)
        {
            int letter = ch - 'a';
            if (!seen[letter])
            {
                seen[letter] = true;
                alphabetSize += 1;
            }
        }

        vector<int> ending(n, 0);
        vector<int> starting(n, 0);
        long long result = 0;
        for (int distinct = 1; distinct <= alphabetSize && 2 * distinct <= n; distinct += 1)
        {
            countExact(s, distinct, 0, n - 1, 1, ending);
            countExact(s, distinct, n - 1, 0, -1, starting);
            for (int middle = 0; middle + 1 < n; middle += 1)
            {
                result += 1LL * ending[middle] * starting[middle + 1];
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countMagicalPairs("aba") << endl;
    cout << sol.countMagicalPairs("kkk") << endl;
    cout << sol.countMagicalPairs("abcac") << endl;
    return 0;
}
