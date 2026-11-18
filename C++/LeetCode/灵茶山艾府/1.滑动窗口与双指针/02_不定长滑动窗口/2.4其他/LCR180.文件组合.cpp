/*
求所有元素和为 target 的连续正整数序列，每个序列至少包含两个数。
序列内部按升序排列，所有序列按首项从小到大返回。

示例 1
输入：target = 12
输出：[[3,4,5]]

示例 2
输入：target = 18
输出：[[3,4,5,6],[5,6,7]]

约束
1 <= target <= 10^5

题目链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
*/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// 窗口从 [1,2] 开始。和太小时扩大右端，和达到或超过目标时移出左端。
// 恰好等于目标就先记录整个区间。窗口至少要有两个元素。
// 时间复杂度 O(target + R)，其中 R 是返回的整数总数，窗口额外空间 O(1)。
class Solution
{
public:
    vector<vector<int>> fileCombination(int target)
    {
        vector<vector<int>> result;
        int left = 1;
        int right = 2;
        int sum = left + right;
        while (left < right)
        {
            if (sum == target)
            {
                vector<int> sequence(right - left + 1);
                iota(sequence.begin(), sequence.end(), left);
                result.push_back(sequence);
            }
            if (sum < target)
            {
                right += 1;
                sum += right;
            }
            else
            {
                sum -= left;
                left += 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    for (int target : {12, 18})
    {
        vector<vector<int>> result = sol.fileCombination(target);
        for (const auto &sequence : result)
        {
            cout << "[";
            for (int i = 0; i < int(sequence.size()); i += 1)
            {
                if (i > 0)
                {
                    cout << ",";
                }
                cout << sequence[i];
            }
            cout << "]";
        }
        cout << endl;
    }
    return 0;
}
