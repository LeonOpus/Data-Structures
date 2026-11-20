/*
找出两个无环链表共用的第一个节点，没有交点时返回空指针。

示例
输入：A = [4,1,8,4,5], B = [5,6,1,8,4,5]，两条链从值为 8 的节点起共用后缀。
输出：8

题目链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/
*/
#include "hot100_example.h"
#include <unordered_set>
using namespace std;

// 用哈希集合记录链表 A 的节点地址，再遍历 B。相交以地址相同为准。平均时间 O(m + n)，额外空间 O(m)。
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        while (headA)
        {
            set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (set.find(headB) != set.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution sol;
    hot100::ListExample a({4, 1});
    hot100::ListExample b({5, 6, 1});
    hot100::ListExample tail({8, 4, 5});
    a.at(1)->next = tail.head();
    b.at(2)->next = tail.head();
    ListNode *node = sol.getIntersectionNode(a.head(), b.head());
    hot100::print(node != nullptr ? node->val : -1);
    return 0;
}
