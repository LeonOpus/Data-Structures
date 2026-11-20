/*
将字符串切成若干连续子串，要求每段都是回文。返回全部切分方案。

示例
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

题目链接：https://leetcode.cn/problems/palindrome-partitioning/
*/
#include "hot100_example.h"
using namespace std;

// 先预处理每个区间是否回文，再回溯枚举下一段终点。
// 最坏时间 O(n × 2^n)，额外空间 O(n²)，不计结果。
class Solution
{
private:
    void search(const string &s, const vector<vector<bool>> &palindrome, int start,
                vector<string> &path, vector<vector<string>> &result)
    {
        int n = s.size();
        if (start == n)
        {
            result.push_back(path);
            return;
        }
        for (int end = start; end < n; ++end)
        {
            if (palindrome[start][end])
            {
                path.push_back(s.substr(start, end - start + 1));
                search(s, palindrome, end + 1, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int left = n - 1; left >= 0; --left)
        {
            for (int right = left; right < n; ++right)
            {
                palindrome[left][right] = s[left] == s[right] &&
                    (right - left < 2 || palindrome[left + 1][right - 1]);
            }
        }
        vector<vector<string>> result;
        vector<string> path;
        search(s, palindrome, 0, path, result);
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.partition("aab"));
    return 0;
}
