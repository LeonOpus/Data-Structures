/*
返回二叉树按左子树、根节点、右子树顺序访问得到的节点值。

示例
输入：root = [1,null,2,3]
输出：[1,3,2]

题目链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/
*/
#include "hot100_example.h"
using namespace std;

// 递归完成左右子树的遍历，并在两次递归之间记录根值。时间 O(n)，递归空间 O(h)。
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
    void inOrder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, nullptr, 2, 3});
    TreeNode *root = rootInput.root();
    hot100::print(sol.inorderTraversal(root));
    return 0;
}
