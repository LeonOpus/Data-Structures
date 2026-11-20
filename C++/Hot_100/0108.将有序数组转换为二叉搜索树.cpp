/*
将严格递增的数组转换成高度平衡的二叉搜索树。

示例
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]

题目链接：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
*/
#include "hot100_example.h"
using namespace std;

// 选择区间中点为根，两个半段分别成为左右子树。递归传下标，避免复制子数组。
// 时间 O(n)，递归空间 O(log n)。
class Solution
{
private:
    TreeNode *build(const vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nullptr;
        }
        int middle = left + (right - left) / 2;
        return new TreeNode(nums[middle], build(nums, left, middle), build(nums, middle + 1, right));
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *result = sol.sortedArrayToBST(nums);
    hot100::printTree(result);
    hot100::deleteTree(result);
    return 0;
}
