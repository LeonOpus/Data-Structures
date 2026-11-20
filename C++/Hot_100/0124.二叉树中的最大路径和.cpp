/*
求二叉树中至少含一个节点的简单路径的最大节点值之和。

示例
输入：root = [1,2,3]
输出：6

题目链接：https://leetcode.cn/problems/binary-tree-maximum-path-sum/
*/
#include "hot100_example.h"
#include <algorithm>
#include <climits>
using namespace std;

// 单条路径可以在当前节点连接两侧的非负收益，向父节点返回时只能带一侧。
// 时间 O(n)，递归空间 O(h)。
class Solution
{
private:
    int contribution(TreeNode *root, int &best)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = max(0, contribution(root->left, best));
        int right = max(0, contribution(root->right, best));
        best = max(best, root->val + left + right);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int best = INT_MIN;
        contribution(root, best);
        return best;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, 2, 3});
    TreeNode *root = rootInput.root();
    hot100::print(sol.maxPathSum(root));
    return 0;
}
