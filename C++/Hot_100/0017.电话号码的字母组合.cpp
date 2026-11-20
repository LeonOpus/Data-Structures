/*
给定由 2 到 9 组成的电话号码字符串，返回九宫格上对应的所有字母组合。

示例
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

题目链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
*/
#include "hot100_example.h"
#include <unordered_map>
using namespace std;

// 递归处理每个数字，依次加入它对应的一个字母。时间 O(n × P)，P 为组合数，递归空间 O(n)。
class Solution
{
public:
    vector<string> letterCombinations(const string &digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        string path;
        unordered_map<char, string> map =
            {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}};
        backtracking(0, 0, digits, map, path, result);
        return result;
    }
    void backtracking(const int &start, const int &index, const string &digits, const unordered_map<char, string> &map, string &path, vector<string> &result)
    {
        if (path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        string str = map.at(digits[index]);
        for (int i = start; i < str.size(); i += 1)
        {
            path.push_back(str[i]);
            backtracking(0, index + 1, digits, map, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.letterCombinations("23"));
    return 0;
}
