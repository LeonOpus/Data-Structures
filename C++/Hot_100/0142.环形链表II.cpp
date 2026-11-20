/*
返回链表中的入环节点。如果不存在环，返回空指针。

示例
输入：head = [3,2,0,-4], pos = 1。示例打印入环节点的下标。
输出：1

题目链接：https://leetcode.cn/problems/linked-list-cycle-ii/
*/
#include "hot100_example.h"
using namespace std;

// 快慢指针在环内相遇时，从头和相遇点各出发一个指针，同速前进并在入口相遇。
// 时间 O(n)，额外空间 O(1)。
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *entry = head;
                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample input({3, 2, 0, -4});
    input.at(3)->next = input.at(1);
    ListNode *entry = sol.detectCycle(input.head());
    int position = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (input.at(i) == entry)
        {
            position = i;
            break;
        }
    }
    hot100::print(position);
    return 0;
}
