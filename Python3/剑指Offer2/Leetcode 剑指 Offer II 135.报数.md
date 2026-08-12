> 题目难度: 简单

> [原题链接](https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)

## 题目描述

实现一个十进制数字报数程序，请按照数字从小到大的顺序返回一个整数数列，该数列从数字 1 开始，到最大的正整数 cnt 位数字结束。

### 示例 1：

- 输入：cnt = 2
- 输出：`[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99]`

## 题目思考

1. 如何得到最大值?

## 解决方案

### 思路

#### 分析

- 题目很直白, 我们只需要得到 n 位数的上限, 将其作为循环终点, 从 1 开始循环依次保存到数组即可

#### 实现

1. 方案 1: 取上限的下一个数, 显然是 `pow(10, n)`, 循环上界小于它即可
2. 方案 2: 直接取上限, n 位数的上限就是 **n 个 9**, 通过字符串转换可以直接得到
3. 方案 3: 还是直接取上限, 通过将当前数字乘以 10 然后加 9 的方式循环生成上限

### 复杂度

- 时间复杂度 `O(10^N)`
  - 需要循环到 `10^N` 依次输出
- 空间复杂度 `O(1)`
  - 只使用了几个变量

### 代码

#### 方案 1 - 取上限的下一个数

```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return list(range(1, 10**n))
```

#### 方案 2 - 利用字符串转换取上限数

```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        mx = int("9" * n)
        res = []
        for i in range(1, mx + 1):
            res.append(i)
        return res
```

#### 方案 3 - 利用循环求上限数

```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        mx = 0
        for i in range(n):
            mx = mx * 10 + 9
        res = []
        for i in range(1, mx + 1):
            res.append(i)
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
