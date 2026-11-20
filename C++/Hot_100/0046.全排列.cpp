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
private:
    void fill(int start, vector<int> &nums, vector<vector<int>> &result)
    {
        int n = nums.size();
        if (start == n)
        {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < n; ++i)
        {
            swap(nums[start], nums[i]);
            fill(start + 1, nums, result);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        fill(0, nums, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    hot100::print(sol.permute(nums));
    return 0;
}
