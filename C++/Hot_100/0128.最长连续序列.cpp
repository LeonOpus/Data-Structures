/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
示例 3：
输入：nums = [1,0,1,2]
输出：3
*/
#include <iostream>
#include <vector>
#include <unordered_set> // 使用哈希表，保证 O(n) 时间复杂度
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
        {
            return nums.size();
        }
        int result = 0;
        // unordered_set<int> set(nums.begin(), nums.end());等价于后面两行代码
        unordered_set<int> set;
        set.reserve(nums.size()); // 提前预留好空间，防止后续 insert 触发频繁扩容
        for (int &num : nums)     // 将数组中的元素放入set中
        {
            set.insert(num);
        }
        for (int num : set) // 遍历nums找到最长的连续序列
        {
            if (set.find(num - 1) == set.end()) // 没有找到num-1，说明num是连续序列的起点
            {
                int current_num = num;
                int current_length = 1;
                while (set.find(current_num + 1) != set.end()) // 找到num的连续序列，说明num+1在set中，计算连续序列的长度
                {
                    current_num += 1;
                    current_length += 1;
                }
                result = max(result, current_length); // 更新result的值
            }
        }
        return result;
    };
};
int main()
{
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}