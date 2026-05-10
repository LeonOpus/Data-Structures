#include "BinaryTree.h"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return postOrder(root, p, q);
    }
    TreeNode *postOrder(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        TreeNode *left = postOrder(root->left, p, q);
        TreeNode *right = postOrder(root->right, p, q);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        if (left && right)
            return root;
        return root;
    }
};
int main()
{
    // [3,5,1,6,2,0,8,null,null,7,4], p=5, q=1 => 3
    TreeNode *root = createBinaryTree({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    TreeNode *p = root->left;  // 5
    TreeNode *q = root->right; // 1
    Solution s;
    cout << s.lowestCommonAncestor(root, p, q)->val << endl; // 3
    // p=5, q=4 => 5
    TreeNode *q2 = root->left->right->right;                  // 4
    cout << s.lowestCommonAncestor(root, p, q2)->val << endl; // 5
    return 0;
}
