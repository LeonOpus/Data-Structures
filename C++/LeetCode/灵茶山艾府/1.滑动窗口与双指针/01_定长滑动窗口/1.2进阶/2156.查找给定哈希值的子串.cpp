/*
将小写字母 'a' 到 'z' 分别映射为数值 1 到 26。
长度为 k 的子串 t 的哈希值为：
(val(t[0]) + val(t[1]) * power + ... + val(t[k - 1]) * power^(k - 1)) % modulo。
在字符串 s 中寻找长度为 k、哈希值等于 hashValue 的子串。
如果有多个答案，返回起始下标最小的一个；题目保证存在答案。

示例 1：
输入：s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
输出："ee"
解释：(5 + 5 * 7) % 20 = 0。

示例 2：
输入：s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
输出："fbx"
解释："fbx" 和 "bxz" 都匹配，但 "fbx" 的起始位置更靠左。

提示：
1 <= k <= s.length <= 2 * 10^4
1 <= power, modulo <= 10^9
0 <= hashValue < modulo
s 只含小写英文字母，并且至少有一个满足条件的子串。

题目链接：https://leetcode.cn/problems/find-substring-with-given-hash-value/
*/
#include <iostream>
#include <string>
using namespace std;

// 从右向左滑动，旧哈希乘 power 后加入左端字符，再减去移出字符乘 power^k。
// 这样不需要计算模逆元，modulo 不是质数时也适用。
// 每次匹配都更新下标，最后留下的就是最靠左的答案。
// 时间复杂度 O(n)，额外空间复杂度 O(1)，乘法使用 long long 防止溢出。
class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int n = s.size();
        long long powerK = 1;
        for (int i = 0; i < k; i += 1)
        {
            powerK = powerK * power % modulo;
        }
        // 处理最右侧的第一个窗口
        long long hash = 0;
        for (int i = n - 1; i >= n - k; i -= 1)
        {
            hash = (hash * power + s[i] - 'a' + 1) % modulo;
        }
        int resultIndex = hash == hashValue ? n - k : -1;
        // 处理左侧的后续窗口
        for (int i = n - k - 1; i >= 0; i -= 1)
        {
            long long outgoing = (s[i + k] - 'a' + 1) * powerK % modulo;
            hash = (hash * power + s[i] - 'a' + 1 - outgoing + modulo) % modulo;
            if (hash == hashValue)
            {
                resultIndex = i;
            }
        }
        return s.substr(resultIndex, k);
    }
};

int main()
{
    Solution sol;
    cout << sol.subStrHash("leetcode", 7, 20, 2, 0) << endl;
    cout << sol.subStrHash("fbxzaad", 31, 100, 3, 32) << endl;
    cout << sol.subStrHash("abc", 1, 1, 2, 0) << endl; // modulo = 1 时所有哈希值都是 0
    return 0;
}
