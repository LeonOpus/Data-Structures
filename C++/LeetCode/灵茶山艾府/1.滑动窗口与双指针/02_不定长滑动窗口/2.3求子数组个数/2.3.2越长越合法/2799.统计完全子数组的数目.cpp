/*
如果一个连续子数组包含原数组 nums 中出现过的每一种值，它就是完全子数组。
求完全子数组的个数。元素取值在 [1, 2000] 内。

示例 1
输入：nums = [1,3,1,2,2]
输出：4

示例 2
输入：nums = [5,5,5,5]
输出：10

题目链接：https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 先统计原数组的不同值总数。窗口一旦包含所有值就收缩，直到缺少一个值。
// 固定右端，把之前移出窗口的位置数 left 加到答案。
// 设 U 为值域上界，时间复杂度 O(n + U)，额外空间 O(U)。
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        const int maxValue = 2000;
        int count[maxValue + 1] = {};
        int required = 0;
        for (int value : nums)
        {
            if (count[value] == 0)
            {
                count[value] = 1;
                required += 1;
            }
        }
        fill(count, count + maxValue + 1, 0);

        int n = nums.size();
        int left = 0;
        int distinct = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int &incoming = count[nums[right]];
            incoming += 1;
            if (incoming == 1)
            {
                distinct += 1;
            }
            while (distinct == required)
            {
                int &outgoing = count[nums[left]];
                outgoing -= 1;
                if (outgoing == 0)
                {
                    distinct -= 1;
                }
                left += 1;
            }
            result += left;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 1, 2, 2};
    cout << sol.countCompleteSubarrays(nums) << endl;
    nums = {5, 5, 5, 5};
    cout << sol.countCompleteSubarrays(nums) << endl;
    return 0;
}
