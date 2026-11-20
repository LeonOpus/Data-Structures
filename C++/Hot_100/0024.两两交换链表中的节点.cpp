/*
将链表相邻节点两两交换。若最后只剩一个节点，保留原位。

示例
输入：head = [1,2,3,4]
输出：[2,1,4,3]

题目链接：https://leetcode.cn/problems/swap-nodes-in-pairs/
*/
#include "hot100_example.h"
using namespace std;

// 用哨兵统一处理首对节点，每次调整前驱与两个相邻节点之间的三条边。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *before = &dummy;
        while (before->next != nullptr && before->next->next != nullptr)
        {
            ListNode *first = before->next;
            ListNode *second = first->next;
            first->next = second->next;
            second->next = first;
            before->next = second;
            before = first;
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({1, 2, 3, 4});
    hot100::printList(sol.swapPairs(head.head()));
    return 0;
}
