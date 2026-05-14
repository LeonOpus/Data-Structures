# @lc app=leetcode.cn id=14 lang=python3
# [14] 最长公共前缀
# https://leetcode.cn/problems/longest-common-prefix/description/
# algorithms
# Easy (45.17%)
# Likes:    3507
# Dislikes: 0
# Total Accepted:    1.7M
# Total Submissions: 3.7M
# Testcase Example:  '["flower","flow","flight"]'
# 编写一个函数来查找字符串数组中的最长公共前缀。
# 如果不存在公共前缀，返回空字符串 ""。
# 示例 1：
# 输入：strs = ["flower","flow","flight"]
# 输出："fl"
# 示例 2：
# 输入：strs = ["dog","racecar","car"]
# 输出：""
# 解释：输入不存在公共前缀。
# 提示：
# 1 <= strs.length <= 200
# 0 <= strs[i].length <= 200
# strs[i] 如果非空，则仅由小写英文字母组成
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        result = strs[0]
        for i in range(1, len(strs)):
            result = self.commonPrefix_dp(result, strs[i])
            if not result:
                return ""
        return result

    # 动态规划法
    def commonPrefix_dp(self, str1: str, str2: str) -> str:
        if not str1 or not str2:
            return ""
        result = ""
        dp = [[0] * (len(str2) + 1) for _ in range(len(str1) + 1)]
        max_len = 0
        for i in range(1, min(len(str1), len(str2)) + 1):
            if str1[i - 1] == str2[i - 1]:
                dp[i][i] = dp[i - 1][i - 1] + 1
            elif str1[i - 1] != str2[i - 1]:
                break
            max_len = max(max_len, dp[i][i])
        result = str1[:max_len]
        return result

    # 暴力法
    def commonPrefix(self, str1: str, str2: str) -> str:
        if not str1 or not str2:
            return ""
        result = ""
        for i in range(min(len(str1), len(str2))):
            if str1[i] != str2[i]:
                return result
            result += str1[i]
        return result


print(Solution().longestCommonPrefix(["flower", "flow", "flight"]))  # 输出fl
print(Solution().longestCommonPrefix(["dog", "racecar", "car"]))  # 输出""
print(Solution().longestCommonPrefix([""]))  # 输出""
print(Solution().longestCommonPrefix(["a"]))  # 输出a
print(Solution().longestCommonPrefix(["ab", "a"]))  # 输出a


# @lc code=end
