/*
判断二叉树的左右两侧是否互为镜像。

示例
输入：root = [1,2,2,3,4,4,3]
输出：true

题目链接：https://leetcode.cn/problems/symmetric-tree/
*/
#include "hot100_example.h"
using namespace std;

// 镜像节点要同时为空，或值相同并且它们的外侧和内侧子树分别互为镜像。时间 O(n)，递归空间 O(h)。
class Solution
{
private:
    bool mirror(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr || b == nullptr)
        {
            return a == b;
        }
        return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || mirror(root->left, root->right);
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, 2, 2, 3, 4, 4, 3});
    TreeNode *root = rootInput.root();
    hot100::print(sol.isSymmetric(root));
    return 0;
}
