/*
fruits[i] = [position, amount] 表示数轴上该位置的水果数量，位置互异且按升序排列。
从 startPos 出发，最多移动 k 个单位，经过一个位置就摘走那里的全部水果。
求能摘到的最大数量。

示例 1
输入：fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
输出：9

示例 2
输入：fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
输出：14

题目链接：https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 摘到的水果来自一个连续区间。设最左、最右的果树距起点分别向左 a 步、向右 b 步，
// 若某一侧没有覆盖，取该侧距离为 0。先走较近一侧再折返，最少需要 a + b + min(a,b) 步。
// 窗口越大，所需路程不会减少。时间复杂度 O(n)，额外空间 O(1)。
class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        int left = 0;
        int sum = 0;
        int result = 0;
        auto cost = [&](int first, int last)
        {
            int toLeft = max(0, startPos - fruits[first][0]);
            int toRight = max(0, fruits[last][0] - startPos);
            return toLeft + toRight + min(toLeft, toRight);
        };

        for (int right = 0; right < n; right += 1)
        {
            sum += fruits[right][1];
            while (left <= right && cost(left, right) > k)
            {
                sum -= fruits[left][1];
                left += 1;
            }
            result = max(result, sum);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
    cout << sol.maxTotalFruits(fruits, 5, 4) << endl;
    fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout << sol.maxTotalFruits(fruits, 5, 4) << endl;
    fruits = {{0, 3}, {6, 4}, {8, 5}};
    cout << sol.maxTotalFruits(fruits, 3, 2) << endl;
    return 0;
}
