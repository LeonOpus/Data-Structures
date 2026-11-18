/*
nums 是一个首尾相邻的环形数组，元素只有 0 和 1。
每次可以任意选择两个不同位置，交换它们的值，不要求两个位置相邻。
求把全部 1 放到一段连续环形区间内所需的最少交换次数。

示例 1：
输入：nums = [0,1,0,1,1,0,0]
输出：1

示例 2：
输入：nums = [0,1,1,1,0,0,1,1,0]
输出：2

示例 3：
输入：nums = [1,1,0,0,1]
输出：0
解释：把首尾视作相邻后，三个 1 已经连续。

提示：
1 <= nums.length <= 10^5
nums[i] 只能取 0 或 1。

题目链接：https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii/
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// 设数组中共有 k 个 1，最终它们必须占据一个长度为 k 的环形窗口。
// 窗口内有多少个 0，就需要从窗口外交换进来多少个 1。
// 时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        if (k == 0)
        {
            return 0;
        }
        int zeros = 0;
        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            zeros += nums[i] == 0;
        }
        int result = zeros;
        // 处理后续窗口，取模访问跨越数组末尾的位置
        for (int start = 1; start < n; start += 1)
        {
            zeros -= nums[start - 1] == 0;
            zeros += nums[(start + k - 1) % n] == 0;
            result = min(result, zeros);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << sol.minSwaps(nums) << endl;
    nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << sol.minSwaps(nums) << endl;
    nums = {1, 1, 0, 0, 1};
    cout << sol.minSwaps(nums) << endl;
    nums = {0, 0, 0};
    cout << sol.minSwaps(nums) << endl;
    return 0;
}
