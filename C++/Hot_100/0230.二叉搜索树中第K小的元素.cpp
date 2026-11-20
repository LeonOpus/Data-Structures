/*
在二叉搜索树中返回按升序数到的第 k 个节点值。

示例
输入：root = [3,1,4,null,2], k = 1
输出：1

题目链接：https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
*/
#include "hot100_example.h"
#include <stack>
using namespace std;

// 中序遍历按值升序访问，访问到第 k 个节点时直接返回。时间 O(h + k)，栈空间 O(h)。
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> pending;
        while (root != nullptr || !pending.empty())
        {
            while (root != nullptr)
            {
                pending.push(root);
                root = root->left;
            }
            root = pending.top();
            pending.pop();
            if (--k == 0)
            {
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({3, 1, 4, nullptr, 2});
    TreeNode *root = rootInput.root();
    hot100::print(sol.kthSmallest(root, 1));
    return 0;
}
