/*
判断一个单链表是否存在环。

示例
输入：head = [3,2,0,-4], pos = 1
输出：true

题目链接：https://leetcode.cn/problems/linked-list-cycle/
*/
#include "hot100_example.h"
using namespace std;

// 快指针每次走两步，慢指针每次走一步。若有环，两指针最终会相遇。时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample input({3, 2, 0, -4});
    input.at(3)->next = input.at(1);
    hot100::print(sol.hasCycle(input.head()));
    return 0;
}
