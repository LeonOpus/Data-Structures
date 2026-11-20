/*
给定 nums 和窗口长度 k，依次返回每个连续窗口中的最大值。

示例
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]

题目链接：https://leetcode.cn/problems/sliding-window-maximum/
*/
#include "hot100_example.h"
#include <deque>
using namespace std;

// 双端队列保存下标，队首始终是最大值。移出过期下标，加入新下标前淘汰队尾较小值。
// 每个下标进出队列至多一次，时间 O(n)，额外空间 O(k)。
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> candidates;
        vector<int> result;
        int n = nums.size();
        for (int right = 0; right < n; ++right)
        {
            if (!candidates.empty() && candidates.front() <= right - k)
            {
                candidates.pop_front();
            }
            while (!candidates.empty() && nums[candidates.back()] <= nums[right])
            {
                candidates.pop_back();
            }
            candidates.push_back(right);
            if (right + 1 >= k)
            {
                result.push_back(nums[candidates.front()]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    hot100::print(sol.maxSlidingWindow(nums, 3));
    return 0;
}
