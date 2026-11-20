/*
求二叉树中任意两节点之间最长路径的边数。路径可以不经过根。

示例
输入：root = [1,2,3,4,5]
输出：3

题目链接：https://leetcode.cn/problems/diameter-of-binary-tree/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 后序遍历算子树深度。经过某节点的最长路径边数就是左右子树深度之和。
// 时间 O(n)，递归空间 O(h)。
class Solution
{
private:
    int depth(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = depth(root->left, diameter);
        int right = depth(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        depth(root, result);
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, 2, 3, 4, 5});
    TreeNode *root = rootInput.root();
    hot100::print(sol.diameterOfBinaryTree(root));
    return 0;
}
