/*
给定整数数组 nums 和窗口长度 k。
对每个长度为 k 的连续子数组，找出出现次数最多的数值，作为这个窗口的众数。
如果有多个数值出现次数并列最多，取其中数值最小的一个。
窗口的权重等于众数的数值乘以它在窗口中的出现次数。
求所有长度为 k 的子数组的权重之和。

示例 1：
输入：nums = [1,2,2,3], k = 3
输出：8
解释：两个窗口的众数都是 2，出现次数都是 2，各贡献权重 4。

示例 2：
输入：nums = [1,2,1,2], k = 2
输出：3
解释：每个窗口中 1 和 2 都出现一次，并列时取 1，因此三个窗口各贡献 1。

示例 3：
输入：nums = [4,3,4,3], k = 3
输出：14
解释：两个窗口的权重分别为 4 * 2 = 8 和 3 * 2 = 6。

提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= nums.length

题目链接：https://leetcode.cn/problems/sum-of-weighted-modes-in-subarrays/
题面参考：https://leetcode.doocs.org/lc/3672/（会员题）
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

// 用哈希表维护频次，用有序集合保存 (-频次, 数值)。
// 集合首项就是频次最高、并列时数值最小的众数。
// 更新频次时先删除旧记录，再插入新记录，集合只保留当前窗口中出现过的数值。
// 平均时间复杂度 O(n * log(k + 1))，额外空间复杂度 O(k)。
// 权重及其总和使用 long long，避免整数溢出。
class Solution
{
public:
    long long modeWeight(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        set<pair<int, int>> order;
        auto updateCount = [&](int value, int delta)
        {
            int oldCount = count[value];
            if (oldCount > 0)
            {
                order.erase({-oldCount, value});
            }
            int newCount = oldCount + delta;
            if (newCount > 0)
            {
                count[value] = newCount;
                order.insert({-newCount, value});
            }
            else
            {
                count.erase(value);
            }
        };
        auto getWeight = [&]()
        {
            const pair<int, int> &mode = *order.begin();
            return -1LL * mode.first * mode.second;
        };

        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            updateCount(nums[i], 1);
        }
        long long result = getWeight();
        // 处理后续窗口
        for (int i = k; i < n; i += 1)
        {
            if (nums[i - k] != nums[i])
            {
                updateCount(nums[i - k], -1);
                updateCount(nums[i], 1);
            }
            result += getWeight();
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 3};
    cout << sol.modeWeight(nums, 3) << endl;
    nums = {1, 2, 1, 2};
    cout << sol.modeWeight(nums, 2) << endl;
    nums = {4, 3, 4, 3};
    cout << sol.modeWeight(nums, 3) << endl;
    nums = {3, 2, 1};
    cout << sol.modeWeight(nums, 1) << endl; // k = 1 时，每个元素分别贡献自身数值
    return 0;
}
