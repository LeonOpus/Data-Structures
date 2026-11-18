/*
给定观察者的位置 location、平面点集 points 和视野宽度 angle（度）。
观察者可以转向任意方向。落在视野边界上的点以及与观察者重合的点都可见。
点可以有重复。求转向后最多能同时看见多少个点。

示例 1
输入：points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
输出：3

示例 2
输入：points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
输出：4

题目链接：https://leetcode.cn/problems/maximum-number-of-visible-points/
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 与观察者重合的点始终可见，单独计数。其余点用 atan2 计算极角后排序。
// 把排序后的角度加一整圈接在末尾，便可连续地处理跨越角度起点的窗口。
// 窗口至多包含原有极角数，避免把同一个点重复计入。时间 O(n log n)，额外空间 O(n)。
class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        vector<double> directions;
        int samePosition = 0;
        for (const auto &point : points)
        {
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];
            if (dx == 0 && dy == 0)
            {
                samePosition += 1;
            }
            else
            {
                directions.push_back(atan2(dy, dx));
            }
        }

        sort(directions.begin(), directions.end());
        int n = directions.size();
        const double pi = acos(-1.0);
        for (int i = 0; i < n; i += 1)
        {
            directions.push_back(directions[i] + 2 * pi);
        }

        const double width = angle * pi / 180.0;
        const double epsilon = 1e-10;
        int left = 0;
        int result = 0;
        for (int right = 0; right < 2 * n; right += 1)
        {
            while (right - left + 1 > n || directions[right] - directions[left] > width + epsilon)
            {
                left += 1;
            }
            result = max(result, right - left + 1);
        }
        return result + samePosition;
    }
};

int main()
{
    Solution sol;
    vector<int> location = {1, 1};
    vector<vector<int>> points = {{2, 1}, {2, 2}, {3, 3}};
    cout << sol.visiblePoints(points, 90, location) << endl;
    points = {{2, 1}, {2, 2}, {3, 4}, {1, 1}};
    cout << sol.visiblePoints(points, 90, location) << endl;
    points = {{1, 0}, {2, 1}};
    cout << sol.visiblePoints(points, 13, location) << endl;
    return 0;
}
