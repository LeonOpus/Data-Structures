/*
从右侧观察二叉树，按深度返回每层最右边的可见节点。

示例
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]

题目链接：https://leetcode.cn/problems/binary-tree-right-side-view/
*/
#include "hot100_example.h"
#include <queue>
using namespace std;

// 层序遍历，每层只记录最后出队的节点。时间 O(n)，队列空间 O(w)，w 为最大层宽。
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> result;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (i == size - 1) // 每一层的最后一个节点
                    result.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::TreeExample rootInput({1, 2, 3, nullptr, 5, nullptr, 4});
    TreeNode *root = rootInput.root();
    hot100::print(sol.rightSideView(root));
    return 0;
}
