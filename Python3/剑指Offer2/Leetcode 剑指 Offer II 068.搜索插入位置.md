> 题目难度: 简单

> [原题链接](https://leetcode.cn/problems/N6YdxV/)

## 题目描述

给定一个排序的整数数组 nums 和一个整数目标值 target ，请在数组中找到 target ，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

### 示例 1:

- 输入: nums = [1,3,5,6], target = 5
- 输出: 2

### 示例 2:

- 输入: nums = [1,3,5,6], target = 2
- 输出: 1

### 示例 3:

- 输入: nums = [1,3,5,6], target = 7
- 输出: 4

### 示例 4:

- 输入: nums = [1,3,5,6], target = 0
- 输出: 0

### 示例 5:

- 输入: nums = [1], target = 0
- 输出: 0

### 提示:

- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums 为无重复元素的升序排列数组
- -10^4 <= target <= 10^4

## 题目思考

1. 如何利用数组的有序性?

## 解决方案

#### 思路

- 分析题目, 一个最直接的思路就是遍历数组, 返回第一个大于等于 target 的下标, 没有的话则返回数组长度作为插入位置
- 不过这样做的时间复杂度达到了 O(N), 不满足题目要求, 如何优化呢?
- 由于数组有序, 所以我们可以利用经典的二分查找来找 target
- 如果 target 存在于数组中, 则二分查找到对应下标后直接返回
- 如果 target 不存在于数组中, 则其插入位置是第一个值大于 target 的下标, 或者数组长度 (当所有值都小于 target 时)
- 具体做法如下:
  1. 初始化插入位置 res 为数组长度 (最大的插入位置)
  2. 初始化左右边界 s 和 e 分别为 0 和最后一个下标, 代表查找整个数组
  3. 使用 while 循环保证当前查找范围有效, 即满足 s<=e
  4. 计算当前两者中点 m, 并比较对应的值和 target 的关系
  5. 如果中点值等于 target, 则说明找到了 target, 直接返回其下标 m
  6. 如果中点值小于 target, 则 m 不可能是插入位置, 直接将 s 设置为 m+1, 继续查找右半部分
  7. 如果中点值大于 target, 则 m 可能是插入位置, 更新 res 为 res 和 m 的较小值, 然后将 e 设置为 m-1, 继续查找左半部分
  8. 最后, 遍历完所有前缀长度后的 res 即为所求
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(logN): 二分查找每次都会将问题规模减半, 所以是 O(logN)
- 空间复杂度 O(1): 只使用了几个常数空间的变量

#### 代码

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # 因为插入位置可能是数组末尾, 所以res要初始化为数组长度
        res = len(nums)
        s, e = 0, len(nums) - 1
        while s <= e:
            m = (s + e) >> 1
            if nums[m] == target:
                # 找到target了, 返回下标
                return m
            elif nums[m] < target:
                # 当前数字小于target, 一定不可能是插入位置
                s = m + 1
            else:
                # 当前数字大于target, 可能是插入位置, res更新为两者较小值
                res = min(res, m)
                e = m - 1
        return res
```

---

> 大家可以在下面这些地方找到我~😊

> [我的 GitHub](https://github.com/zjulyx)

> [我的 Leetcode](https://leetcode-cn.com/u/suibianfahui/)

> [我的 CSDN](https://me.csdn.net/zjulyx1993)

> [我的知乎专栏](https://zhuanlan.zhihu.com/c_1242508721932464128)

> [我的头条号](https://www.toutiao.com/c/user/1090304683804520/#mid=1671643017345028)

> [我的牛客网博客](https://blog.nowcoder.net/zjulyx)

> 我的公众号: [算法精选](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484158&idx=1&sn=90176bac32cf7af40e4074c721fd8a95&chksm=900285f3a7750ce5a068c9c9773781461819633f2fd60533732637ec9520c908371ebc218d49&scene=178&cur_album_id=1386231241346859009#rd), 欢迎大家扫码关注~😊

![算法精选 - 微信扫一扫关注我](https://pic1.zhimg.com/80/v2-7c988a7b35886df51596ef23616764ac_1440w.jpg)
