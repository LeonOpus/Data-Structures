/*
尽量多地划分字符串 s，使每个字母只出现在其中一个片段，返回每段长度。

示例
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]

题目链接：https://leetcode.cn/problems/partition-labels/
*/
#include "hot100_example.h"
#include <algorithm>
#include <numeric>
using namespace std;

// 先记录每个字母的最后位置。扩展当前片段的右边界，到达该边界就切分。
// 时间 O(n)，额外空间 O(26)，不计输出。
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        if (s.empty())
            return {};
        vector<int> result;
        vector<int> last_index(26, 0); // 字母出现最后最远的下标
        for (int i = 0; i < s.size(); i++)
        {
            last_index[s[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, last_index[s[i] - 'a']);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::print(sol.partitionLabels("ababcbacadefegdehijhklij"));
    return 0;
}
