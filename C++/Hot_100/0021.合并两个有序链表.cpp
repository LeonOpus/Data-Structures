/*
将两个非递减链表合并成一条非递减链表。

示例
输入：list1 = [1,2,4], list2 = [1,3,4]
输出：[1,1,2,3,4,4]

题目链接：https://leetcode.cn/problems/merge-two-sorted-lists/
*/
#include "hot100_example.h"
using namespace std;

// 每步选择两个表头中较小的节点，借助哨兵统一处理结果表头。时间 O(m + n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummny = new ListNode(0);
        ListNode *cur = dummny;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
            }
            else
            {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        if (list1)
        {
            cur->next = list1;
        }
        if (list2)
        {
            cur->next = list2;
        }
        ListNode *reuslt = dummny->next;
        delete dummny;
        dummny = nullptr;
        return reuslt;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample list1({1, 2, 4});
    hot100::ListExample list2({1, 3, 4});
    hot100::printList(sol.mergeTwoLists(list1.head(), list2.head()));
    return 0;
}
