/*
已知节点值互异的二叉树先序遍历和中序遍历，恢复原树。

示例
输入：preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出：[3,9,20,null,null,15,7]

题目链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include "hot100_example.h"
#include <unordered_map>
using namespace std;

// 先序遍历的下一项是当前根。用哈希表找到它在中序中的位置，切出左右子树区间。
// 平均时间 O(n)，额外空间 O(n)。
class Solution
{
private:
    TreeNode *build(const vector<int> &preorder, const unordered_map<int, int> &positions,
                    int &next, int left, int right)
    {
        if (left == right)
        {
            return nullptr;
        }
        int value = preorder[next++];
        int middle = positions.at(value);
        TreeNode *root = new TreeNode(value);
        root->left = build(preorder, positions, next, left, middle);
        root->right = build(preorder, positions, next, middle + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> positions;
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            positions[inorder[i]] = i;
        }
        int next = 0;
        return build(preorder, positions, next, 0, n);
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *result = sol.buildTree(preorder, inorder);
    hot100::printTree(result);
    hot100::deleteTree(result);
    return 0;
}
