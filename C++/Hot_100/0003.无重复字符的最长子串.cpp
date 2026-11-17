/*
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
示例1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。
请注意，你的答案必须是子串的长度，"pwke"是一个子序列，不是子串。
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        /*
        for 循环的主场：已知明确边界的线性扫描（如遍历字符串、固定步长的数组遍历）。
        while 循环的主场：终止条件未知、步长动态变化、或者依赖数据结构状态（如队列非空、指针不为空、区间未闭合）的复杂控制流。
        单向匀速扫描（如简单遍历）：用 for。
        双指针相向而行（如二分、左右夹逼）：必须用 while。
        滑动窗口（快慢/左右同向）：for 负责推进右边界，while 负责收缩左边界，两者配合最完美！
        */
        int result = 0;
        unordered_map<char, int> map;
        int left = 0;                                     // 左边界
        for (int right = 0; right < s.size(); right += 1) // for 负责推进右边界
        {
            map[s[right]] += 1;
            while (map[s[right]] > 1) // while 负责收缩左边界
            {
                map[s[left]] -= 1;
                left += 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution s;
    string s_1 = "abcabcbb";
    string s_2 = "bbbbb";
    string s_3 = "pwwkew";
    string s_4 = "au";
    cout << s.lengthOfLongestSubstring(s_1) << endl;
    cout << s.lengthOfLongestSubstring(s_2) << endl;
    cout << s.lengthOfLongestSubstring(s_3) << endl;
    cout << s.lengthOfLongestSubstring(s_4) << endl;
    return 0;
}