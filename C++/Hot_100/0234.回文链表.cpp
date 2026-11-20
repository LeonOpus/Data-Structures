/*
判断链表节点值从前向后读是否与从后向前读相同。

示例
输入：head = [1,2,2,1]
输出：true

题目链接：https://leetcode.cn/problems/palindrome-linked-list/
*/
#include "hot100_example.h"
using namespace std;

// 快慢指针找中点，反转并比较后半段，最后恢复原链。时间 O(n)，额外空间 O(1)。
class Solution
{
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previous = nullptr;
        while (head != nullptr)
        {
            ListNode *next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        return previous;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *suffix = reverseList(slow->next);
        ListNode *first = head;
        bool result = true;
        for (ListNode *second = suffix; second != nullptr; second = second->next)
        {
            if (first->val != second->val)
            {
                result = false;
                break;
            }
            first = first->next;
        }
        slow->next = reverseList(suffix);
        return result;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample head({1, 2, 2, 1});
    hot100::print(sol.isPalindrome(head.head()));
    return 0;
}
