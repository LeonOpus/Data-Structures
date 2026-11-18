/*
从 flowers 中选择一段连续的花。若每个品种在这段区间中都不超过 cnt 朵，
这束花就是美观的。求所有美观区间的个数。题目保证结果在 int 范围内。

示例 1
输入：flowers = [1,2,3,2], cnt = 1
输出：8

示例 2
输入：flowers = [5,3,3,3], cnt = 2
输出：8

题目链接：https://leetcode.cn/problems/1GxJYY/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 右端加入一朵花时，只有它所属的品种可能超出 cnt。移动左端直到该品种恢复合法。
// 固定右端，合法的起点有 right - left + 1 个。
// 平均时间复杂度 O(n)，额外空间 O(n)。
class Solution
{
public:
    int beautifulBouquet(vector<int> &flowers, int cnt)
    {
        int n = flowers.size();
        unordered_map<int, int> count;
        int left = 0;
        int result = 0;
        for (int right = 0; right < n; right += 1)
        {
            int incoming = flowers[right];
            count[incoming] += 1;
            while (count[incoming] > cnt)
            {
                count[flowers[left]] -= 1;
                left += 1;
            }
            result += right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> flowers = {1, 2, 3, 2};
    cout << sol.beautifulBouquet(flowers, 1) << endl;
    flowers = {5, 3, 3, 3};
    cout << sol.beautifulBouquet(flowers, 2) << endl;
    return 0;
}
