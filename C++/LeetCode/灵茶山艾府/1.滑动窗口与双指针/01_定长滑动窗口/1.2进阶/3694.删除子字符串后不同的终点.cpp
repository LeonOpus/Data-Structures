/*
从坐标 (0, 0) 出发，按字符串 s 中的字符移动，每次走一格。
'U'、'D'、'L'、'R' 分别表示向上、向下、向左、向右。
必须从 s 中删除一段长度恰好为 k 的连续指令，再执行剩余指令。
求所有删除方案能够得到多少个不同的最终坐标。

示例 1：
输入：s = "LUL", k = 1
输出：2
解释：剩余指令为 "UL"、"LL" 或 "LU"，终点共有两种。

示例 2：
输入：s = "UDLR", k = 4
输出：1
解释：删去全部指令后，终点只有原点。

示例 3：
输入：s = "UU", k = 1
输出：1

提示：
1 <= s.length <= 10^5
1 <= k <= s.length
s 的字符只能是 'U'、'D'、'L'、'R'。

题目链接：https://leetcode.cn/problems/distinct-points-reachable-after-substring-removal/
*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// 最终坐标 = 全部指令的总位移 - 被删除窗口的位移。
// 总位移固定，不同窗口位移与不同最终坐标一一对应，只需对窗口位移去重。
// 位移的两个分量都在 [-k, k] 内，用 2 * k + 1 进制编码，避免坐标碰撞。
// 平均时间复杂度 O(n)，额外空间复杂度 O(n)。
class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        int n = s.size();
        int x = 0;
        int y = 0;
        auto move = [&](char ch, int sign)
        {
            x += sign * ((ch == 'R') - (ch == 'L'));
            y += sign * ((ch == 'U') - (ch == 'D'));
        };
        unordered_set<long long> positions;
        auto recordPosition = [&]()
        {
            positions.insert((x + k) * (2LL * k + 1) + y + k);
        };

        // 处理第一个窗口
        for (int i = 0; i < k; i += 1)
        {
            move(s[i], 1);
        }
        recordPosition();
        // 处理后续窗口
        for (int i = k; i < n; i += 1)
        {
            move(s[i - k], -1);
            move(s[i], 1);
            recordPosition();
        }
        return positions.size();
    }
};

int main()
{
    Solution sol;
    cout << sol.distinctPoints("LUL", 1) << endl;
    cout << sol.distinctPoints("UDLR", 4) << endl;
    cout << sol.distinctPoints("UU", 1) << endl;
    return 0;
}
