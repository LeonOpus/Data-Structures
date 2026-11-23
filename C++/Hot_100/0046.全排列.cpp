/*
给定互不相同的数，返回其所有全排列。

示例
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

题目链接：https://leetcode.cn/problems/permutations/
*/
#include "hot100_example.h"
#include <utility>
using namespace std;

// 递归固定下标，把剩余的任一个值交换到当前位置，回溯时撤销。
// 时间 O(n × n!)，额外空间 O(n)，不计结果。
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size());
        backtracking(0, nums, used, path, result);
        return result;
    }
    void backtracking(int start, vector<int> &nums, vector<bool> used, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == true) // 树枝上的元素不能重复使用，如果不用树枝去重，就会出现相同元素的排列
                continue;        // 比如[1,2,3] 出现[111],[112],[113],[121],[122],[123]等，这样就会出现重复的排列
            used[i] = true;      // 题目要求是不含重复数字的排列，所以需要树枝去重
            path.push_back(nums[i]);
            backtracking(0, nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    hot100::print(sol.permute(nums));
    return 0;
}
