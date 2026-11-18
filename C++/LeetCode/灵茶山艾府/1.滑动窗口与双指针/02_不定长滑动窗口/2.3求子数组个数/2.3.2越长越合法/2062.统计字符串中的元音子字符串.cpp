/*
元音子串必须只包含 a、e、i、o、u，而且这五种字母都至少出现一次。
求小写字符串 word 中这样的连续子串数量。

示例 1
输入：word = "aeiouu"
输出：2

示例 2
输入：word = "cuaieuouac"
输出：7

题目链接：https://leetcode.cn/problems/count-vowel-substrings-of-a-string/
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 对每个右端记录最近的辅音位置，以及五种元音各自最近出现的位置。
// 起点必须在最近的辅音之后，并且不晚于五种元音最近位置的最小值。
// 时间复杂度 O(5 * n)，窗口额外空间 O(5)。
class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        const string vowels = "aeiou";
        int last[5] = {-1, -1, -1, -1, -1};
        int lastConsonant = -1;
        int n = word.size();
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            size_t vowel = vowels.find(word[right]);
            if (vowel == string::npos)
            {
                lastConsonant = right;
                continue;
            }
            last[vowel] = right;
            int earliest = *min_element(last, last + 5);
            result += max(0, earliest - lastConsonant);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.countVowelSubstrings("aeiouu") << endl;
    cout << sol.countVowelSubstrings("unicornarihan") << endl;
    cout << sol.countVowelSubstrings("cuaieuouac") << endl;
    return 0;
}
