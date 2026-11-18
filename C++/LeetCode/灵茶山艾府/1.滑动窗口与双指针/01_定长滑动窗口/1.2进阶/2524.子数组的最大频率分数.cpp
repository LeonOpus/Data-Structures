/*
给定正整数数组 nums 和窗口长度 k。
对一个子数组，若某个不同的数值 x 出现了 c 次，它对频率分数的贡献就是 x^c。
把所有出现过的不同数值的贡献相加，再对 10^9 + 7 取模，得到这个子数组的分数。
求 nums 中所有长度为 k 的连续子数组的最大分数。
注意：每个窗口都要先取模，然后比较分数，不能先比较实际值再对最大值取模。

示例 1：
输入：nums = [1,1,1,2,1,2], k = 3
输出：5
解释：窗口 [2,1,2] 的分数为 2^2 + 1^1 = 5。

示例 2：
输入：nums = [1,1,1,1,1,1], k = 4
输出：1

提示：
1 <= k <= nums.length <= 10^5
1 <= nums[i] <= 10^6

题目链接：https://leetcode.cn/problems/maximum-frequency-score-of-a-subarray/
题面参考：https://leetcode.doocs.org/lc/2524/（会员题）
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 定长窗口只改变移出、移入的两种数值的频次。
// 更新一种数值时，先减去旧频次对应的幂，再加上新频次对应的幂。
// 频次为 0 时贡献是 0，不能按 x^0 = 1 计算；减法取模后需要恢复到非负范围。
// 使用快速幂，平均时间复杂度 O(n * log(k + 1))，额外空间复杂度 O(k)。
class Solution
{
private:
    static const int MOD = 1000000007;

    long long quickPow(long long base, int exponent)
    {
        long long result = 1;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exponent /= 2;
        }
        return result;
    }

public:
    int maxFrequencyScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            count[nums[i]] += 1;
        }
        long long score = 0;
        for (const auto &entry : count)
        {
            score = (score + quickPow(entry.first, entry.second)) % MOD;
        }
        long long result = score;
        auto updateCount = [&](int value, int delta)
        {
            int &frequency = count[value];
            if (frequency > 0)
            {
                score = (score - quickPow(value, frequency) + MOD) % MOD;
            }
            frequency += delta;
            if (frequency > 0)
            {
                score = (score + quickPow(value, frequency)) % MOD;
            }
            else
            {
                count.erase(value);
            }
        };
        // 处理后续窗口
        for (int i = k; i < n; i += 1)
        {
            if (nums[i - k] == nums[i])
            {
                continue; // 相同数值一出一入，窗口分数不变
            }
            updateCount(nums[i - k], -1);
            updateCount(nums[i], 1);
            result = max(result, score);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 1, 2};
    cout << sol.maxFrequencyScore(nums, 3) << endl;
    nums = {1, 1, 1, 1, 1, 1};
    cout << sol.maxFrequencyScore(nums, 4) << endl;
    nums = {1000000, 1000000, 1000000, 999999};
    cout << sol.maxFrequencyScore(nums, 3) << endl; // 取模后两个窗口的分数为 49、992999
    return 0;
}
