/*
nums 的长度 n 为偶数。选择长度为 0 到 n - 1 的一个前缀，把它移到数组末尾，
即可得到一种循环移位。如果新数组前 n / 2 项的和严格大于后 n / 2 项的和，
就把这次移位记为好循环移位。
求全部 n 种移位方式中有多少种是好的，内容相同的移位也分别计数。

示例 1：
输入：nums = [1,2,3,4,5,6]
输出：3

示例 2：
输入：nums = [1,2,1,2]
输出：0
解释：所有移位的前半部分与后半部分之和都相等。

提示：
2 <= nums.length <= 10^5，且数组长度为偶数。
1 <= nums[i] <= 10^9

题目链接：https://leetcode.cn/problems/count-good-cyclic-rotations/
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 每种循环移位的前半部分，都是原环形数组中长度为 n / 2 的窗口。
// 设数组总和为 total，窗口和为 sum，判断 sum > total - sum 即可。
// 时间复杂度 O(n)，额外空间复杂度 O(1)，元素之和使用 long long。
class Solution
{
public:
    int countGoodRotations(vector<int> &nums)
    {
        int n = nums.size();
        int k = n / 2;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long sum = 0;
        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            sum += nums[i];
        }
        int result = sum > total - sum;
        // 处理后续窗口
        for (int start = 1; start < n; start += 1)
        {
            sum -= nums[start - 1];
            sum += nums[(start + k - 1) % n];
            if (sum > total - sum)
            {
                result += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << sol.countGoodRotations(nums) << endl;
    nums = {1, 2, 1, 2};
    cout << sol.countGoodRotations(nums) << endl;
    nums = {1000000000, 1000000000, 1000000000, 1};
    cout << sol.countGoodRotations(nums) << endl;
    return 0;
}
