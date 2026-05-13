# @lc app=leetcode.cn id=5 lang=python3
# [5] 最长回文子串
# https://leetcode.cn/problems/longest-palindromic-substring/description/
# algorithms
# Medium (40.81%)
# Likes:    8075
# Dislikes: 0
# Total Accepted:    2.4M
# Total Submissions: 5.8M
# Testcase Example:  '"babad"'
# 给你一个字符串 s，找到 s 中最长的 回文 子串。
# 示例 1：
# 输入：s = "babad"
# 输出："bab"
# 解释："aba" 同样是符合题意的答案。
# 示例 2：
# 输入：s = "cbbd"
# 输出："bb"
# 提示：
# 1 <= s.length <= 1000
# s 仅由数字和英文字母组成
# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        result = ""
        dp = [[False] * len(s) for _ in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if s[i] != s[j]:
                    dp[i][j] = False
                elif s[i] == s[j]:
                    if j - i == 0:
                        dp[i][j] = True
                    elif j - i == 1:
                        dp[i][j] = True
                    elif j - i > 1:
                        dp[i][j] = dp[i + 1][j - 1]
                if dp[i][j] == True:
                    if j - i + 1 > len(result):
                        result = s[i : j + 1]
        return result


print(Solution().longestPalindrome("babad"))  # Output: "bab"
print(Solution().longestPalindrome("cbbd"))  # Output: "bb"
print(Solution().longestPalindrome("a"))  # Output: "a"
print(Solution().longestPalindrome("ac"))  # Output: "a"
print(Solution().longestPalindrome("aacabdkacaa"))  # Output: "aca"
# @lc code=end
