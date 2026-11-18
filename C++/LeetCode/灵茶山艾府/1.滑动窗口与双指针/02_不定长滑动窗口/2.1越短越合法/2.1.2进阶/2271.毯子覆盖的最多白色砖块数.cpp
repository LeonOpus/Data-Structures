/*
每个区间 [li, ri] 内的整数位置都有一块白色砖，给定的区间互不重叠。
一张长度为 carpetLen 的毯子可以覆盖连续 carpetLen 个整数位置。
求放置这张毯子后最多能盖住多少块白砖。

示例 1
输入：tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
输出：9

示例 2
输入：tiles = [[10,11],[1,1]], carpetLen = 2
输出：2

题目链接：https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 存在一种最优摆法，使毯子右端落在某个白砖区间的右端。
// 右端在白砖内时向右移，新增的白砖不会少于移出的白砖。右端在空隙时可向左移到上一块白砖。
// 排序后枚举右端，累加相交区间，再扣掉最左区间露出的部分。
// 时间复杂度 O(n log n)，滑窗额外空间 O(1)。
class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        int left = 0;
        int covered = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            covered += tiles[right][1] - tiles[right][0] + 1;
            int carpetStart = tiles[right][1] - carpetLen + 1;
            while (tiles[left][1] < carpetStart)
            {
                covered -= tiles[left][1] - tiles[left][0] + 1;
                left += 1;
            }
            int uncovered = max(0, carpetStart - tiles[left][0]);
            result = max(result, covered - uncovered);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tiles = {{1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}};
    cout << sol.maximumWhiteTiles(tiles, 10) << endl;
    tiles = {{10, 11}, {1, 1}};
    cout << sol.maximumWhiteTiles(tiles, 2) << endl;
    return 0;
}
