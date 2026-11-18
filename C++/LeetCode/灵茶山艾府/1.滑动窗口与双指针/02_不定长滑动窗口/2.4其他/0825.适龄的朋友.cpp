/*
给定每位用户的年龄。年龄为 x 的用户向年龄为 y 的另一位用户发送请求，
须满足 y > x / 2 + 7、y <= x，且不能出现 y > 100 同时 x < 100 的情况。
求总请求数。两个用户之间双向发送时计为两条。

示例 1
输入：ages = [16,16]
输出：2

示例 2
输入：ages = [16,17,18]
输出：2

示例 3
输入：ages = [20,30,100,110,120]
输出：3

约束
1 <= ages.length <= 2 * 10^4
1 <= ages[i] <= 120

题目链接：https://leetcode.cn/problems/friends-of-appropriate-ages/
*/
#include <iostream>
#include <vector>
using namespace std;

// y <= x 已经排除了发送者低于 100 岁、接收者高于 100 岁的情况。
// 按年龄分组。年龄为 x 的用户只向 (x / 2 + 7, x] 中的其他用户发送请求。
// 用年龄人数前缀和查出区间人数，减去发送者自己，再乘以该年龄的总人数。
// 设 A 为年龄上限，时间复杂度 O(n + A)，额外空间 O(A)。
class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        const int maxAge = 120;
        int count[maxAge + 1] = {};
        for (int age : ages)
        {
            count[age] += 1;
        }

        int prefix[maxAge + 1] = {};
        for (int age = 1; age <= maxAge; age += 1)
        {
            prefix[age] = prefix[age - 1] + count[age];
        }

        int result = 0;
        for (int age = 15; age <= maxAge; age += 1)
        {
            if (count[age] > 0)
            {
                int recipients = prefix[age] - prefix[age / 2 + 7] - 1;
                result += count[age] * recipients;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> ages = {16, 16};
    cout << sol.numFriendRequests(ages) << endl;
    ages = {16, 17, 18};
    cout << sol.numFriendRequests(ages) << endl;
    ages = {20, 30, 100, 110, 120};
    cout << sol.numFriendRequests(ages) << endl;
    return 0;
}
