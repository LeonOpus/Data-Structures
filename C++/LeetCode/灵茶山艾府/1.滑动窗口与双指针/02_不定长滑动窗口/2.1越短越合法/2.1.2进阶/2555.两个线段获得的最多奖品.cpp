/*
prizePositions 按非降序给出奖品位置，同一位置可以有多个奖品。
在数轴上放置两个长度为 k 的线段，端点处的奖品也算覆盖。
线段允许重叠，每个奖品最多计一次。求最多能得到多少奖品。

示例 1
输入：prizePositions = [1,1,2,2,3,3,5], k = 2
输出：7

示例 2
输入：prizePositions = [1,2,3,4], k = 0
输出：2

题目链接：https://leetcode.cn/problems/maximize-win-from-two-segments/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 把最右侧线段的右端放到奖品位置，滑窗找它能覆盖的最左下标 left。
// 两个线段重叠时，重叠部分的奖品可全部归到右边线段。
// 用 bestPrefix[left] 查询左侧前缀里单条线段最多能覆盖多少奖品，再加上当前窗口长度。
// 时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int n = prizePositions.size();
        vector<int> bestPrefix(n + 1, 0);
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            while (prizePositions[right] - prizePositions[left] > k)
            {
                left += 1;
            }
            int covered = right - left + 1;
            result = max(result, covered + bestPrefix[left]);
            bestPrefix[right + 1] = max(bestPrefix[right], covered);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> prizes = {1, 1, 2, 2, 3, 3, 5};
    cout << sol.maximizeWin(prizes, 2) << endl;
    prizes = {1, 2, 3, 4};
    cout << sol.maximizeWin(prizes, 0) << endl;
    return 0;
}
