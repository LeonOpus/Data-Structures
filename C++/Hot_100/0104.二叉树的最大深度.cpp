/*
求从二叉树根到最深叶子的节点数。空树的深度为 0。

示例
输入：root = [3,9,20,null,null,15,7]
输出：3

题目链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree/
*/
#include "hot100_example.h"
#include <algorithm>
using namespace std;

// 当前树的深度等于较深的子树深度加一。时间 O(n)，递归空间 O(h)。
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({3, 9, 20, nullptr, nullptr, 15, 7});
    TreeNode *root = rootInput.root();
    hot100::print(sol.maxDepth(root));
    return 0;
}
