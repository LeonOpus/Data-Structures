/*
将二叉树的每个节点的左右子树互换，并返回根节点。

示例
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

题目链接：https://leetcode.cn/problems/invert-binary-tree/
*/
#include "hot100_example.h"
#include <utility>
using namespace std;

// 递归翻转两个子树，再交换左右指针。时间 O(n)，递归空间 O(h)。
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({4, 2, 7, 1, 3, 6, 9});
    TreeNode *root = rootInput.root();
    hot100::printTree(sol.invertTree(root));
    return 0;
}
