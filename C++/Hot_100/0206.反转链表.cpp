/*
反转单链表，返回反转后的头节点。

示例
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

题目链接：https://leetcode.cn/problems/reverse-linked-list/
*/
#include "hot100_example.h"
using namespace std;

// 逐个翻转 next 指针，修改前先保存后继节点。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *node = cur->next;
            cur->next = pre; // 1节点指向空节点
            pre = cur;       // 空节点移动到1节点
            cur = node;      // 1节点移动到2节点
        }
        return pre;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({1, 2, 3, 4, 5});
    hot100::printList(sol.reverseList(head.head()));
    return 0;
}
