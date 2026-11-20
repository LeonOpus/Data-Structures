/*
给定两个非递减数组，求将它们合在一起之后的中位数。两个数组不会同时为空。

示例
输入：nums1 = [1,3], nums2 = [2]
输出：2.0

题目链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/
*/
#include "hot100_example.h"
#include <algorithm>
#include <climits>
using namespace std;

// 在较短数组上二分分割点，另一数组的分割点由左半边的总长度决定。
// 两侧分割处没有逆序时，左半边最大值和右半边最小值就能确定中位数。
// 时间 O(log(min(m,n) + 1))，额外空间 O(1)。
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int need = (m + n + 1) / 2;
        int left = 0, right = m;
        while (left <= right)
        {
            int a = left + (right - left) / 2;
            int b = need - a;
            int leftA = a == 0 ? INT_MIN : nums1[a - 1];
            int rightA = a == m ? INT_MAX : nums1[a];
            int leftB = b == 0 ? INT_MIN : nums2[b - 1];
            int rightB = b == n ? INT_MAX : nums2[b];
            if (leftA > rightB)
            {
                right = a - 1;
            }
            else if (leftB > rightA)
            {
                left = a + 1;
            }
            else
            {
                double middle = max(leftA, leftB);
                if ((m + n) % 2 == 0)
                {
                    middle = (middle + min(rightA, rightB)) / 2;
                }
                return middle;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    hot100::print(sol.findMedianSortedArrays(nums1, nums2));
    return 0;
}
