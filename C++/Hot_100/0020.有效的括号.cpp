/*
判断由圆括号、方括号和花括号组成的字符串是否正确闭合。

示例
输入：s = "()"
输出：true

题目链接：https://leetcode.cn/problems/valid-parentheses/
*/
#include <stack>
#include <iostream>
using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> chStack;
        for (char &ch : s)
        {
            if (ch == '{' || ch == '(' || ch == '[')
            {
                chStack.push(ch);
            }
            else if (ch == '}' || ch == ')' || ch == ']')
            {
                if (chStack.empty())
                    return false;
                else if (!chStack.empty())
                {
                    char top = chStack.top();
                    chStack.pop();
                    if (top != '{' && ch == '}')
                        return false;
                    else if (top != '(' && ch == ')')
                        return false;
                    else if (top != '[' && ch == ']')
                        return false;
                }
            }
        }
        return chStack.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    return 0;
}