/*
每 k 个节点为一组反转链表，最后不足 k 个节点的一组保留原样。

示例
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

题目链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
*/
#include "hot100_example.h"
using namespace std;

// 先找到当前组尾和下一组组头，再反转该组并接回链表。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0, head);
        ListNode *before = &dummy;
        while (true)
        {
            ListNode *end = before;
            for (int i = 0; i < k && end != nullptr; ++i)
            {
                end = end->next;
            }
            if (end == nullptr)
            {
                break;
            }
            ListNode *nextGroup = end->next;
            ListNode *current = before->next;
            ListNode *previous = nextGroup;
            while (current != nextGroup)
            {
                ListNode *next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            ListNode *oldHead = before->next;
            before->next = end;
            before = oldHead;
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({1, 2, 3, 4, 5});
    hot100::printList(sol.reverseKGroup(head.head(), 2));
    return 0;
}
