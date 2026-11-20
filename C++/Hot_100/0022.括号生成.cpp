/*
给定括号对数 n，返回所有合法的括号字符串。

示例
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

题目链接：https://leetcode.cn/problems/generate-parentheses/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 左括号未用完就可以添加。右括号只能在已加的左括号更多时添加。
// 设 C 为合法方案数，时间 O(n × C)，递归空间 O(n)。
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        vector<string> result;
        string path;
        backtracking(n, 0, 0, path, result);
        return result;
    }
    void backtracking(int n, int left, int right, string &path, vector<string> &result)
    {
        if (path.size() == n * 2)
        {
            result.push_back(path);
            return;
        }
        if (left < n)
        {
            left += 1;
            path += "(";
            backtracking(n, left, right, path, result);
            path.pop_back();
            left -= 1;
        }
        if (right < left)
        {
            right += 1;
            path += ")";
            backtracking(n, left, right, path, result);
            path.pop_back();
            right -= 1;
        }
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.generateParenthesis(3));
    return 0;
}
