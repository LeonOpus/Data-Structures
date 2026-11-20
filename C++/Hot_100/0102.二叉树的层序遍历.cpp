/*
从根开始逐层访问二叉树，每层从左到右返回节点值。

示例
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

题目链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/
*/
#include "hot100_example.h"
#include <queue>
using namespace std;

// 广度优先搜索，每轮按入队前的队列长度处理一层。时间 O(n)，队列空间 O(w)，w 为最大层宽。
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        vector<int> path;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                path.push_back(node->val);
                queue.pop();
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
            result.push_back(path);
            path.clear();
        }
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({3, 9, 20, nullptr, nullptr, 15, 7});
    TreeNode *root = rootInput.root();
    hot100::print(sol.levelOrder(root));
    return 0;
}
