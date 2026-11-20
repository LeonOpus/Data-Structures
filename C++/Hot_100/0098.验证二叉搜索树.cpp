/*
判断一棵树是否为二叉搜索树。左子树的所有值小于根，右子树的所有值大于根。

示例
输入：root = [2,1,3]
输出：true

题目链接：https://leetcode.cn/problems/validate-binary-search-tree/
*/
#include "hot100_example.h"
#include <stack>
using namespace std;

// 有效搜索树的中序节点值严格递增。遍历中逐项比较前后两个节点。时间 O(n)，栈空间 O(h)。
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> pending;
        TreeNode *previous = nullptr;
        while (root != nullptr || !pending.empty())
        {
            while (root != nullptr)
            {
                pending.push(root);
                root = root->left;
            }
            root = pending.top();
            pending.pop();
            if (previous != nullptr && previous->val >= root->val)
            {
                return false;
            }
            previous = root;
            root = root->right;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({2, 1, 3});
    TreeNode *root = rootInput.root();
    hot100::print(sol.isValidBST(root));
    return 0;
}
