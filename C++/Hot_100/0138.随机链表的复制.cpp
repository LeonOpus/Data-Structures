/*
深拷贝链表。每个节点除 next 外，还有可能指向任意节点或为空的 random 指针。

示例
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]，每项为 [节点值, random 的目标下标]。
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

题目链接：https://leetcode.cn/problems/copy-list-with-random-pointer/
*/
#include "hot100_example.h"
#include <unordered_map>
using namespace std;

// 先为每个原节点创建副本，建立地址映射，再按映射连接两个指针。平均时间 O(n)，额外空间 O(n)。
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int value) : val(value), next(nullptr), random(nullptr) {}
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> copies = {{nullptr, nullptr}};
        for (Node *node = head; node != nullptr; node = node->next)
        {
            copies[node] = new Node(node->val);
        }
        for (Node *node = head; node != nullptr; node = node->next)
        {
            copies[node]->next = copies[node->next];
            copies[node]->random = copies[node->random];
        }
        return copies[head];
    }
};

int main()
{
    Solution sol;
    vector<Node> nodes = {Node(7), Node(13), Node(11), Node(10), Node(1)};
    for (int i = 0; i < 4; ++i) nodes[i].next = &nodes[i + 1];
    nodes[1].random = &nodes[0];
    nodes[2].random = &nodes[4];
    nodes[3].random = &nodes[2];
    nodes[4].random = &nodes[0];

    Node *copy = sol.copyRandomList(&nodes[0]);
    unordered_map<Node *, int> indices;
    int index = 0;
    for (Node *node = copy; node != nullptr; node = node->next)
    {
        indices[node] = index++;
    }
    cout << '[';
    for (Node *node = copy; node != nullptr; node = node->next)
    {
        if (node != copy) cout << ',';
        cout << '[' << node->val << ',';
        if (node->random == nullptr) cout << "null";
        else cout << indices.at(node->random);
        cout << ']';
    }
    cout << "]\n";
    while (copy != nullptr)
    {
        Node *next = copy->next;
        delete copy;
        copy = next;
    }
    return 0;
}
