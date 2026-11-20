/*
给定互不相同的整数，返回全部子集，包含空集。

示例
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

题目链接：https://leetcode.cn/problems/subsets/
*/
#include "hot100_example.h"
using namespace std;

// 回溯按下标递增选数，每个递归节点对应一个子集。时间 O(n × 2^n)，递归空间 O(n)，不计结果。
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(0, nums, path, result);
        return result;
    }
    void backtracking(int start, vector<int> &nums, vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(i + 1, nums, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    hot100::print(sol.subsets(nums));
    return 0;
}
