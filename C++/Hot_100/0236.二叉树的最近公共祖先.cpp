/*
求二叉树中 p 和 q 的最近公共祖先，节点也可以是自己的祖先。

示例
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3

题目链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
*/
#include "hot100_example.h"
using namespace std;

// 分别在两棵子树查找。两侧都有目标时当前节点就是最近公共祖先，否则将找到的一侧继续返回。
// 时间 O(n)，递归空间 O(h)。
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left != nullptr ? left : right;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample input({3, 5, 1, 6, 2, 0, 8, nullptr, nullptr, 7, 4});
    TreeNode *ancestor = sol.lowestCommonAncestor(input.root(), input.find(5), input.find(1));
    hot100::print(ancestor->val);
    return 0;
}
