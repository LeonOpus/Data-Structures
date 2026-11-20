/*
两个链表按个位在前的顺序表示非负整数，返回同样顺序的和。

示例
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]

题目链接：https://leetcode.cn/problems/add-two-numbers/
*/
#include "hot100_example.h"
using namespace std;

// 对齐两条链的当前位，加上上一步的进位。遍历结束后还要检查是否有剩余进位。
// 时间 O(max(m,n))，额外空间 O(1)，不计结果链表。
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *tail = &dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample l1({2, 4, 3});
    hot100::ListExample l2({5, 6, 4});
    ListNode *result = sol.addTwoNumbers(l1.head(), l2.head());
    hot100::printList(result);
    hot100::deleteList(result);
    return 0;
}
