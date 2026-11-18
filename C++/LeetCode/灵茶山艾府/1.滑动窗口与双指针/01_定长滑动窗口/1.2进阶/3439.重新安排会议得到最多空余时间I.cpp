/*
给你一个整数 eventTime 表示一个活动的总时长，这个活动开始于 t = 0 ，结束于 t = eventTime 。
同时给你两个长度为 n 的整数数组 startTime 和 endTime 。
它们表示这次活动中 n 个时间 没有重叠 的会议，其中第 i 个会议的时间为 [startTime[i], endTime[i]] 。
你可以重新安排 至多 k 个会议，安排的规则是将会议时间平移，且保持原来的 会议时长 ，你的目的是移动会议后 最大化 相邻两个会议之间的 最长 连续空余时间。
移动前后所有会议之间的 相对 顺序需要保持不变，而且会议时间也需要保持互不重叠。
请你返回重新安排会议以后，可以得到的 最大 空余时间。
注意，会议 不能 安排到整个活动的时间以外。

示例 1：
输入：eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
输出：2
解释：将 [1, 2] 的会议安排到 [2, 3] ，得到空余时间 [0, 2] 。

示例 2：
输入：eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
输出：6
解释：将 [2, 4] 的会议安排到 [1, 3] ，得到空余时间 [3, 9] 。

示例 3：
输入：eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
输出：0
解释：活动中的所有时间都被会议安排满了。

提示：
1 <= eventTime <= 109
n == startTime.length == endTime.length
2 <= n <= 105
1 <= k <= n
0 <= startTime[i] < endTime[i] <= eventTime
endTime[i] <= startTime[i + 1] 其中 i 在范围 [0, n - 2] 之间。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 移动连续的 k 个会议，可以把它们两侧共 k + 1 段空闲时间合并。
// 枚举这 k + 1 段空闲时间的总和，取最大值即可。
// gap(i) 按需计算第 i 段空闲时间，包含活动开始前和结束后的两段。
// 时间复杂度 O(n)，额外空间复杂度 O(1)。
class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        auto gap = [&](int i)
        {
            int leftEnd = i == 0 ? 0 : endTime[i - 1];
            int rightStart = i == n ? eventTime : startTime[i];
            return rightStart - leftEnd;
        };
        int sum = 0;
        // 处理第一个窗口：移动前 k 个会议，合并前 k + 1 段空闲时间
        for (int i = 0; i <= k; i += 1)
        {
            sum += gap(i);
        }
        int result = sum;
        // 处理后续窗口
        for (int i = k + 1; i <= n; i += 1)
        {
            sum += gap(i);
            sum -= gap(i - k - 1);
            result = max(result, sum);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> startTime = {1, 3};
    vector<int> endTime = {2, 5};
    cout << sol.maxFreeTime(5, 1, startTime, endTime) << endl;
    startTime = {0, 2, 9};
    endTime = {1, 4, 10};
    cout << sol.maxFreeTime(10, 1, startTime, endTime) << endl;
    startTime = {0, 1, 2, 3, 4};
    endTime = {1, 2, 3, 4, 5};
    cout << sol.maxFreeTime(5, 2, startTime, endTime) << endl;
    return 0;
}
