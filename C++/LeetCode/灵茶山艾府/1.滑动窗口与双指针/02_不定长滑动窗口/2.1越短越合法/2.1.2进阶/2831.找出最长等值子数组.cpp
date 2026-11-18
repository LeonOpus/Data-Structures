/*
可以在数组 nums 中删除至多 k 个元素，剩余元素保留原有顺序。
求操作后只包含同一种值的最长连续子数组长度。

示例 1
输入：nums = [1,3,2,3,1,3], k = 3
输出：3

示例 2
输入：nums = [1,1,2,2,1,1], k = 2
输出：4
删去两个 2 后，四个 1 连在一起。

约束
1 <= nums[i] <= nums.length <= 10^5，且 k 可以为 0。

题目链接：https://leetcode.cn/problems/find-the-longest-equal-subarray/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 按数值把出现位置分组。对同一个值，若保留从该组 left 到 right 的所有出现位置，
// 需要删掉的位置数就是原区间长度减去该值出现次数。
// 各组的总长度为 n，时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> positions(n + 1);
        for (int i = 0; i < n; i += 1)
        {
            positions[nums[i]].push_back(i);
        }

        int result = 0;
        for (const auto &group : positions)
        {
            int size = group.size();
            int left = 0;
            for (int right = 0; right < size; right += 1)
            {
                while (group[right] - group[left] - (right - left) > k)
                {
                    left += 1;
                }
                result = max(result, right - left + 1);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1, 3};
    cout << sol.longestEqualSubarray(nums, 3) << endl;
    nums = {1, 1, 2, 2, 1, 1};
    cout << sol.longestEqualSubarray(nums, 2) << endl;
    return 0;
}
