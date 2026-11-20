/*
每条先修关系 [课程, 先修课] 表示要先读完第二项才能读第一项。判断能否完成全部课程。

示例
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true

题目链接：https://leetcode.cn/problems/course-schedule/
*/
#include "hot100_example.h"
#include <queue>
using namespace std;

// 从入度为 0 的课程开始拓扑排序。每完成一门，移除它的出边并更新后继课程的入度。
// 时间和空间均为 O(课程数 + 关系数)。
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> following(numCourses);
        vector<int> degree(numCourses, 0);
        for (const auto &edge : prerequisites)
        {
            following[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
        }
        queue<int> ready;
        for (int course = 0; course < numCourses; ++course)
        {
            if (degree[course] == 0)
            {
                ready.push(course);
            }
        }
        int completed = 0;
        while (!ready.empty())
        {
            int course = ready.front();
            ready.pop();
            ++completed;
            for (int next : following[course])
            {
                if (--degree[next] == 0)
                {
                    ready.push(next);
                }
            }
        }
        return completed == numCourses;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}};
    hot100::print(sol.canFinish(2, prerequisites));
    return 0;
}
