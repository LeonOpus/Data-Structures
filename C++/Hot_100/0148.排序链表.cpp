/*
将单链表按节点值升序排序。

示例
输入：head = [4,2,1,3]
输出：[1,2,3,4]

题目链接：https://leetcode.cn/problems/sort-list/
*/
#include "hot100_example.h"
using namespace std;

// 自底向上归并，依次合并长度为 1、2、4 等的相邻有序段。
// 时间 O(n log n)，额外空间 O(1)。
class Solution
{
private:
    ListNode *cut(ListNode *head, int length)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        for (int i = 1; i < length && head->next != nullptr; ++i)
        {
            head = head->next;
        }
        ListNode *next = head->next;
        head->next = nullptr;
        return next;
    }

    ListNode *mergeAfter(ListNode *tail, ListNode *a, ListNode *b)
    {
        while (a != nullptr && b != nullptr)
        {
            if (a->val <= b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a != nullptr ? a : b;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        return tail;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        int length = 0;
        for (ListNode *node = head; node != nullptr; node = node->next)
        {
            ++length;
        }
        ListNode dummy(0, head);
        for (int width = 1; width < length; width *= 2)
        {
            ListNode *tail = &dummy;
            ListNode *left = dummy.next;
            while (left != nullptr)
            {
                ListNode *right = cut(left, width);
                ListNode *next = cut(right, width);
                tail = mergeAfter(tail, left, right);
                left = next;
            }
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({4, 2, 1, 3});
    hot100::printList(sol.sortList(head.head()));
    return 0;
}
