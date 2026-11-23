/*
移除链表倒数第 n 个节点，返回剩余链表的头节点。

示例
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
*/
#include "hot100_example.h"
using namespace std;

// 让快指针领先 n 个节点，然后同步移动，快指针到尾时慢指针的后继就是待移除节点。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        dummy->next = head;
        n += 1;
        while (fast && n > 0)
        {
            fast = fast->next;
            n -= 1;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *node = slow->next;
        slow->next = node->next;
        delete node;
        node = nullptr;
        ListNode *result = dummy->next;
        delete dummy;
        dummy = nullptr;
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({1, 2, 3, 4, 5});
    hot100::printList(sol.removeNthFromEnd(head.head(), 2));
    return 0;
}
