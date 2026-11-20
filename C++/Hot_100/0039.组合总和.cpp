/*
从互异的正整数 candidates 中选数，每个数可重复选。返回所有和为 target 的不同组合。

示例
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]

题目链接：https://leetcode.cn/problems/combination-sum/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 排序后回溯，维持选择下标非递减，避免产生换序的重复组合。剩余和小于当前候选时结束该层。
class Solution
{
private:
    void search(const vector<int> &nums, int start, int remaining,vector<int> &path, vector<vector<int>> &result)
    {
        if (remaining == 0)
        {
            result.push_back(path);
            return;
        }
        int n = nums.size();
        for (int i = start; i < n && nums[i] <= remaining; ++i)
        {
            path.push_back(nums[i]);
            search(nums, i, remaining - nums[i], path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        search(candidates, 0, target, path, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    hot100::print(sol.combinationSum(candidates, 7));
    return 0;
}
