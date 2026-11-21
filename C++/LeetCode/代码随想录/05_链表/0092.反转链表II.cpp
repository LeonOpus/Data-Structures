/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
示例 1：
输入：head = [1,2,3,4,5], left = 2, right = 4 (这里意思包含了索引不从0开始)
输出：[1,4,3,2,5]
示例 2：
输入：head = [5], left = 1, right = 1
输出：[5]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // 方法一
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        for (int i = 0; i < left - 1; i += 1)
        {
            pre = cur;
            cur = cur->next;
        }
        for (int i = left; i < right; i += 1)
        {
            ListNode *node = cur->next;
            cur->next = node->next; // 1->3
            node->next = pre->next; // 2->1
            pre->next = node;       // 0->2
        }
        return dummy->next;
    }

    ListNode *reverseBetween_2(ListNode *head, int left, int right)
    {
        // 方法二
        if (!head || left == right)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 1. 找到 left 的前驱节点 pre
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            pre = pre->next;
        }

        // 2. 找到 right 节点 end，并记下后面的节点 after
        ListNode *end = pre;
        for (int i = 0; i < right - left + 1; ++i)
        {
            end = end->next;
        }
        ListNode *start = pre->next;
        ListNode *after = end->next;

        // 3. 断开子链表并反转
        end->next = nullptr;
        reverseListNode(start);

        // 4. 重新拼接
        pre->next = end;
        start->next = after;

        ListNode *result = dummy->next;
        delete dummy;
        dummy = nullptr;
        return result;
    }

    ListNode *reverseListNode(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        return pre;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createListNode(arr);
    ListNode *test = s.reverseBetween(head, 2, 4);
    printListNode(test);
    return 0;
}