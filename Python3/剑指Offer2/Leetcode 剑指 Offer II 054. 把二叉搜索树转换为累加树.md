> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/w6cpku/)

## 题目描述

给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

提醒一下，二叉搜索树满足下列约束条件：

- 节点的左子树仅包含键 小于 节点键的节点。
- 节点的右子树仅包含键 大于 节点键的节点。
- 左右子树也必须是二叉搜索树。

### 示例 1：

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png)

- 输入：root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
- 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

### 示例 2：

- 输入：root = [0,null,1]
- 输出：[1,null,1]

### 示例 3：

- 输入：root = [1,0,2]
- 输出：[3,3,2]

### 示例 4：

- 输入：root = [3,2,4,1]
- 输出：[7,9,4,10]

### 提示：

- 树中的节点数介于 0 和 10^4 之间。
- 每个节点的值介于 -10^4 和 10^4 之间。
- 树中的所有值 互不相同 。
- 给定的树为二叉搜索树。

## 题目思考

1. 如何利用二叉搜索树的性质?

## 解决方案

#### 思路

- 根据题目描述, 要将树的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和, 我们需要知道有哪些节点大于等于该节点
- 结合二叉搜索树的性质, 其中序遍历的节点是从小到大有序的, 自然其逆向中序遍历的节点就是从大到小有序的
- 我们可以利用这一点, 对树进行逆向中序遍历, 也就是先遍历右子树, 然后是当前节点, 最后是左子树
- 同时维护一个后缀和, 遍历到某个节点时, 就将它的值累加到该后缀和里, 那么该后缀和就是树中大于或者等于当前节点值的所有节点值之和, 将当前节点的值更新为该后缀和即可
- 最终遍历结束时, 树中所有节点的值就都更新好了, 直接返回根节点即可
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(N): 只需要遍历每个节点一次
- 空间复杂度 O(H): 递归调用最多使用 O(H) 栈空间, H 是树的高度

#### 代码

```python
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        # 逆向中序遍历+后缀和
        # sm是当前遍历过的所有节点的后缀和
        sm = 0

        def revInorder(root):
            nonlocal sm
            if not root:
                return
            # 逆向中序遍历, 先遍历右子节点
            revInorder(root.right)
            # 后缀和加上当前节点值, 因为题目要求的是大于等于
            sm += root.val
            # 将当前节点值更新为后缀和
            root.val = sm
            revInorder(root.left)

        revInorder(root)
        return root
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
