/*
在只包含 0 和 1 的数组 nums 中，允许把至多一个 0 改成 1。
求操作后最长的连续 1 段的长度。

示例 1
输入：nums = [1,0,1,1,0]
输出：4
反转前一个 0 即可让前四个元素连成一段。

示例 2
输入：nums = [1,0,1,1,0,1]
输出：4

题目链接：https://leetcode.cn/problems/max-consecutive-ones-ii/
题面参考：https://leetcode.doocs.org/lc/487/（会员题）
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 合法窗口内至多有一个 0。遇到新 0 时，窗口左端直接移到上一个 0 的后一位。
// 只要记住最近一个 0 的位置，因此也可以逐个读入元素。
// 时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int lastZero = -1;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            if (nums[right] == 0)
            {
                left = lastZero + 1;
                lastZero = right;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 1, 0};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    nums = {1, 0, 1, 1, 0, 1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    nums = {1, 1, 1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
