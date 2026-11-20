/*
合并 k 条非递减链表为一条非递减链表。

示例
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]

题目链接：https://leetcode.cn/problems/merge-k-sorted-lists/
*/
#include "hot100_example.h"
#include <queue>
using namespace std;

// 最小堆始终保存各条链表当前的第一个未使用节点。取出最小节点后补入它的后继。
// 设节点总数为 n，时间 O(n log(k + 1))，额外空间 O(k)。
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto greaterValue = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(greaterValue)> pending(greaterValue);
        for (ListNode *head : lists)
        {
            if (head != nullptr)
            {
                pending.push(head);
            }
        }
        ListNode dummy;
        ListNode *tail = &dummy;
        while (!pending.empty())
        {
            ListNode *node = pending.top();
            pending.pop();
            if (node->next != nullptr)
            {
                pending.push(node->next);
            }
            tail->next = node;
            tail = node;
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample a({1, 4, 5});
    hot100::ListExample b({1, 3, 4});
    hot100::ListExample c({2, 6});
    vector<ListNode *> lists = {a.head(), b.head(), c.head()};
    hot100::printList(sol.mergeKLists(lists));
    return 0;
}
