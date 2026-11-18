/*
arrivals[i] 表示第 i 天到达的一件物品的类型。每件物品只能在到达当天决定是否丢弃。
每天检查最近 w 天，不足 w 天时检查从第一天开始的全部天数。
在这个按天数划分的窗口内，每种类型被保留的物品不能多于 m 件。
求满足所有窗口限制时，最少需要丢弃的物品总数。
注意：丢弃物品不会删除对应的日期，也不会把后面的日期提前。

示例 1：
输入：arrivals = [1,2,1,3,1], w = 4, m = 2
输出：0

示例 2：
输入：arrivals = [1,2,3,3,3,4], w = 3, m = 2
输出：1
解释：第 5 天到达的物品 3 需要丢弃。

提示：
1 <= arrivals.length <= 10^5
1 <= arrivals[i] <= 10^5
1 <= w <= arrivals.length
1 <= m <= w

题目链接：https://leetcode.cn/problems/minimum-discards-to-balance-inventory/
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 用长度最多为 w 天的窗口维护被保留物品的频次。
// 若当前类型已有 m 件，贪心丢弃当天的物品：越晚到达的物品会影响越多后续窗口。
// discarded 标记丢弃的日期，移出窗口时不能再次减少这一天的物品计数。
// 平均时间复杂度 O(n)，额外空间复杂度 O(n)。
class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int n = arrivals.size();
        int result = 0;
        vector<bool> discarded(n, false);
        unordered_map<int, int> count;
        for (int i = 0; i < n; i += 1)
        {
            // 先移出过期日期，使加入当天物品后的窗口最多包含 w 天
            if (i >= w && !discarded[i - w])
            {
                count[arrivals[i - w]] -= 1;
            }
            int type = arrivals[i];
            if (count[type] == m)
            {
                discarded[i] = true;
                result += 1;
            }
            else
            {
                count[type] += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> arrivals = {1, 2, 1, 3, 1};
    cout << sol.minArrivalsToDiscard(arrivals, 4, 2) << endl;
    arrivals = {1, 2, 3, 3, 3, 4};
    cout << sol.minArrivalsToDiscard(arrivals, 3, 2) << endl;
    arrivals = {1, 1, 1, 1};
    cout << sol.minArrivalsToDiscard(arrivals, 2, 1) << endl;
    return 0;
}
