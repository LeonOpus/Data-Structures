/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：
输入：head = [], val = 1
输出：[]
示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
*/
#include "ListNode.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 方法一：使用虚拟头节点操作
        if (!head)
        {
            return nullptr;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next)
        {
            if (cur->next->val == val)
            {
                int value = cur->next->val;
                ListNode *node = cur->next;
                while (node && node->val == value)
                {
                    ListNode *del_node = node;
                    node = node->next;
                    delete del_node;
                    del_node = nullptr;
                }
                cur->next = node;
            }
            else
                cur = cur->next;
        }
        ListNode *result = dummy->next;
        delete dummy;
        dummy = nullptr;
        return result;
        // 方法二：直接在原节点操作
        // while (head && head->val == val) // 操作头节点，如果头节点的值为val就一直删除头节点
        // {
        //     ListNode *node = head;
        //     head = head->next;
        //     delete node; // 删除节点释放内存
        // }
        // ListNode *cur = head;
        // while (cur && cur->next) // 操作非头部节点
        // {
        //     if (cur->next->val == val)
        //     {
        //         ListNode *node = cur->next;
        //         cur->next = cur->next->next;
        //         delete node;
        //     }
        //     else
        //     {
        //         cur = cur->next;
        //     }
        // }
        // return head;
        // 方法三：递归操作
        //     if (head == nullptr) //  基础情况：空链表
        //     {
        //         return nullptr;
        //     }
        //     // 递归处理
        //     if (head->val == val)
        //     {
        //         ListNode *newHead = removeElements(head->next, val);
        //         delete head;
        //         return newHead;
        //     }
        //     else
        //     {
        //         head->next = removeElements(head->next, val);
        //         return head;
        //     }
    }
};

int main()
{
    ListNode *head_1 = createListNode({1, 2, 6, 3, 4, 5, 6});
    Solution().removeElements(head_1, 6);
    printListNode(head_1);
    return 0;
}