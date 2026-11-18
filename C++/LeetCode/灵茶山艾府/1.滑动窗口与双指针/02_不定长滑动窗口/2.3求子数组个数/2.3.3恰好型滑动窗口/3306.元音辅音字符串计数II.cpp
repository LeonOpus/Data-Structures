/*
求小写字符串 word 中包含全部五种元音 a、e、i、o、u，且辅音总数恰好为 k 的非空连续子串数量。
辅音的个数按出现次数计算。

示例 1
输入：word = "aeioqq", k = 1
输出：0

示例 2
输入：word = "aeiou", k = 0
输出：1

示例 3
输入：word = "ieaouqqieaouqq", k = 1
输出：3

题目链接：https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
*/
#include <iostream>
#include <string>
using namespace std;

// 固定辅音下限。窗口包含全部元音且辅音足够时继续收缩，直到窗口不再合法。
// 此时小于 left 的位置都能作为当前右端的合法起点。
// 分别统计辅音至少为 k 和至少为 k + 1 的子串数，求差得到恰好 k 的数量。
// 时间复杂度 O(n)，窗口额外空间 O(5)。
class Solution
{
private:
    long long countAtLeast(const string &word, int limit)
    {
        const string vowels = "aeiou";
        int count[5] = {};
        int distinct = 0;
        int consonants = 0;
        int n = word.size();
        int left = 0;
        long long result = 0;
        for (int right = 0; right < n; right += 1)
        {
            size_t incoming = vowels.find(word[right]);
            if (incoming == string::npos)
            {
                consonants += 1;
            }
            else
            {
                count[incoming] += 1;
                if (count[incoming] == 1)
                {
                    distinct += 1;
                }
            }

            while (distinct == 5 && consonants >= limit)
            {
                size_t outgoing = vowels.find(word[left]);
                if (outgoing == string::npos)
                {
                    consonants -= 1;
                }
                else
                {
                    count[outgoing] -= 1;
                    if (count[outgoing] == 0)
                    {
                        distinct -= 1;
                    }
                }
                left += 1;
            }
            result += left;
        }
        return result;
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        return countAtLeast(word, k) - countAtLeast(word, k + 1);
    }
};

int main()
{
    Solution sol;
    cout << sol.countOfSubstrings("aeioqq", 1) << endl;
    cout << sol.countOfSubstrings("aeiou", 0) << endl;
    cout << sol.countOfSubstrings("ieaouqqieaouqq", 1) << endl;
    return 0;
}
