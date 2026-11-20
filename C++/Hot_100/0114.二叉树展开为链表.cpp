/*
原地将二叉树展开成一条沿 right 指针的链，节点顺序等于先序遍历，所有 left 置空。

示例
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

题目链接：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
*/
#include "hot100_example.h"
using namespace std;

// 按右、左、根的顺序递归。处理根时，已经展开的后缀就是它的右后继。
// 时间 O(n)，递归空间 O(h)。
class Solution
{
private:
    void link(TreeNode *root, TreeNode *&next)
    {
        if (root != nullptr)
        {
            link(root->right, next);
            link(root->left, next);
            root->right = next;
            root->left = nullptr;
            next = root;
        }
    }

public:
    void flatten(TreeNode *root)
    {
        TreeNode *next = nullptr;
        link(root, next);
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, 2, 5, 3, 4, nullptr, 6});
    TreeNode *root = rootInput.root();
    sol.flatten(root);
    hot100::printTree(root);
    return 0;
}
