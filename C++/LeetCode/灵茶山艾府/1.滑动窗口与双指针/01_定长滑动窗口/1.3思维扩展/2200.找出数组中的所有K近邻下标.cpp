/*
给定数组 nums、目标值 key 和距离上限 k。
如果下标 i 与至少一个值等于 key 的元素的下标 j 满足 |i - j| <= k，
就称 i 为 K 近邻下标。
返回全部这样的下标，要求从小到大排列，并且每个下标只出现一次。

示例 1：
输入：nums = [3,4,9,1,3,9,5], key = 9, k = 1
输出：[1,2,3,4,5,6]
解释：两个目标元素分别覆盖下标区间 [1,3] 和 [4,6]。

示例 2：
输入：nums = [2,2,2,2,2], key = 2, k = 2
输出：[0,1,2,3,4]
解释：覆盖区间可以重叠，但结果中的下标不能重复。

提示：
1 <= nums.length <= 1000
1 <= nums[i] <= 1000
key 至少在 nums 中出现一次。
1 <= k <= nums.length

题目链接：https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 每个 nums[i] == key 的位置都覆盖 [i - k, i + k]，越界部分裁掉。
// 按下标顺序处理这些区间，用 nextIndex 跳过已经加入答案的部分。
// 每个下标最多加入一次，因此双重循环的总时间仍为 O(n)。
// 额外空间复杂度 O(1)，不计返回结果。
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        int nextIndex = 0;
        vector<int> result;
        for (int i = 0; i < n; i += 1)
        {
            if (nums[i] != key)
            {
                continue;
            }
            int left = max(nextIndex, i - k);
            int right = min(n - 1, i + k);
            for (int j = left; j <= right; j += 1)
            {
                result.push_back(j);
            }
            nextIndex = right + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    vector<int> result = sol.findKDistantIndices(nums, 9, 1);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    nums = {2, 2, 2, 2, 2};
    result = sol.findKDistantIndices(nums, 2, 2);
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
