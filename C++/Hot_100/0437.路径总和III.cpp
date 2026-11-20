/*
统计二叉树中节点值之和等于 targetSum 的向下路径。路径可从任意节点开始和结束。

示例
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3

题目链接：https://leetcode.cn/problems/path-sum-iii/
*/
#include "hot100_example.h"
#include <unordered_map>
using namespace std;

// 沿根到当前节点维护前缀和频次。当前和减目标值能匹配路径起点之前的前缀。
// 回溯时清除当前前缀的贡献。平均时间 O(n)，额外空间 O(h)。
class Solution
{
private:
    int countPaths(TreeNode *root, long long sum, int target, unordered_map<long long, int> &counts)
    {
        if (root == nullptr)
        {
            return 0;
        }
        sum += root->val;
        auto found = counts.find(sum - target);
        int result = found == counts.end() ? 0 : found->second;
        ++counts[sum];
        result += countPaths(root->left, sum, target, counts);
        result += countPaths(root->right, sum, target, counts);
        if (--counts[sum] == 0)
        {
            counts.erase(sum);
        }
        return result;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> counts = {{0, 1}};
        return countPaths(root, 0, targetSum, counts);
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({10, 5, -3, 3, 2, nullptr, 11, 3, -2, nullptr, 1});
    TreeNode *root = rootInput.root();
    hot100::print(sol.pathSum(root, 8));
    return 0;
}
