/*
字符串数组 words 中的单词长度都相同，允许有重复单词。
在字符串 s 中找出所有由 words 的全部单词拼接而成的连续子串。
拼接时可以调整单词顺序，但每个单词的使用次数必须与 words 中一致。
返回这些子串的起始下标，答案顺序不限。

示例 1：
输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：下标 0 和 9 处分别是 "barfoo" 和 "foobar"。

示例 2：
输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]

示例 3：
输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]

提示：
1 <= s.length <= 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 30
s 和 words[i] 只含小写英文字母。

题目链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 按单词长度分组，每次移动一个完整单词，维护包含 words.size() 个单词的定长窗口。
// matched 统计窗口中与目标频次匹配的单词个数，多出的重复单词不计入。
// 设 n 为 s 的长度，m 为单词数，L 为单词长度。
// 平均时间复杂度 O((n + m) * L)，额外空间复杂度 O(m * L)。
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.size();
        int wordLength = words[0].size();
        int wordCount = words.size();
        int windowSize = wordLength * wordCount;
        vector<int> result;
        if (windowSize > n)
        {
            return result;
        }

        unordered_map<string, int> need;
        for (const string &word : words)
        {
            need[word] += 1;
        }
        for (int offset = 0; offset < wordLength && offset + windowSize <= n; offset += 1)
        {
            unordered_map<string, int> count;
            int matched = 0;
            auto updateCount = [&](const string &word, int delta)
            {
                auto it = need.find(word);
                if (it == need.end())
                {
                    return;
                }
                int &current = count[word];
                matched -= min(current, it->second);
                current += delta;
                matched += min(current, it->second);
            };

            // 处理第一个窗口
            for (int i = offset; i < offset + windowSize; i += wordLength)
            {
                updateCount(s.substr(i, wordLength), 1);
            }
            if (matched == wordCount)
            {
                result.push_back(offset);
            }
            // 处理后续窗口
            for (int i = offset + windowSize; i + wordLength <= n; i += wordLength)
            {
                updateCount(s.substr(i - windowSize, wordLength), -1);
                updateCount(s.substr(i, wordLength), 1);
                if (matched == wordCount)
                {
                    result.push_back(i - windowSize + wordLength);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"foo", "bar"};
    vector<int> result = sol.findSubstring("barfoothefoobarman", words);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    words = {"word", "good", "best", "word"};
    result = sol.findSubstring("wordgoodgoodgoodbestword", words);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    words = {"bar", "foo", "the"};
    result = sol.findSubstring("barfoofoobarthefoobarman", words);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
