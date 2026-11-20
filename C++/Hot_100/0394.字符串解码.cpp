/*
解码采用 k[片段] 格式的字符串，将方括号中的片段重复 k 次。编码可嵌套。

示例
输入：s = "3[a]2[bc]"
输出："aaabcbc"

题目链接：https://leetcode.cn/problems/decode-string/
*/
#include "hot100_example.h"
#include <stack>
#include <utility>
using namespace std;

// 遇左括号时保存外层已经解码的内容和重复次数，遇右括号时把当前结果展开到外层。
// 耗时取决于输入长度和展开时复制的总字符数。
class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> frames;
        string current;
        int repeats = 0;
        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9')
            {
                repeats = repeats * 10 + ch - '0';
            }
            else if (ch == '[')
            {
                frames.emplace(std::move(current), repeats);
                current.clear();
                repeats = 0;
            }
            else if (ch == ']')
            {
                string fragment = std::move(current);
                current = std::move(frames.top().first);
                int count = frames.top().second;
                frames.pop();
                for (int i = 0; i < count; ++i)
                {
                    current += fragment;
                }
            }
            else
            {
                current.push_back(ch);
            }
        }
        return current;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.decodeString("3[a]2[bc]"));
    return 0;
}
