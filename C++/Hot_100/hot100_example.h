#ifndef HOT100_EXAMPLE_H
#define HOT100_EXAMPLE_H

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;

    explicit ListNode(int value = 0, ListNode *nextNode = nullptr)
        : val(value), next(nextNode) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int value = 0, TreeNode *leftChild = nullptr, TreeNode *rightChild = nullptr)
        : val(value), left(leftChild), right(rightChild) {}
};

namespace hot100
{
template <class T>
void write(const T &value)
{
    std::cout << value;
}

inline void write(const std::string &value)
{
    std::cout << '"';
    for (char ch : value)
    {
        if (ch == '"' || ch == '\\')
        {
            std::cout << '\\';
        }
        std::cout << ch;
    }
    std::cout << '"';
}

template <class T>
void write(const std::vector<T> &values)
{
    std::cout << '[';
    bool first = true;
    for (const auto &value : values)
    {
        if (!first)
        {
            std::cout << ',';
        }
        write(value);
        first = false;
    }
    std::cout << ']';
}

template <class T>
void print(const T &value)
{
    std::cout << std::boolalpha;
    write(value);
    std::cout << '\n';
}

class ListExample
{
private:
    std::vector<std::unique_ptr<ListNode>> nodes;

public:
    ListExample(std::initializer_list<int> values)
    {
        for (int value : values)
        {
            std::unique_ptr<ListNode> node(new ListNode(value));
            if (!nodes.empty())
            {
                nodes.back()->next = node.get();
            }
            nodes.push_back(std::move(node));
        }
    }

    ListNode *head() const { return nodes.empty() ? nullptr : nodes.front().get(); }
    ListNode *at(std::size_t index) const { return nodes[index].get(); }
};

inline void printList(const ListNode *head)
{
    std::vector<int> values;
    for (const ListNode *node = head; node != nullptr; node = node->next)
    {
        values.push_back(node->val);
    }
    print(values);
}

inline void deleteList(ListNode *head)
{
    while (head != nullptr)
    {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

struct TreeValue
{
    int value;
    bool present;
    TreeValue(int value) : value(value), present(true) {}
    TreeValue(std::nullptr_t) : value(0), present(false) {}
};

class TreeExample
{
private:
    std::vector<std::unique_ptr<TreeNode>> nodes;

    TreeNode *add(int value)
    {
        std::unique_ptr<TreeNode> node(new TreeNode(value));
        nodes.push_back(std::move(node));
        return nodes.back().get();
    }

public:
    TreeExample(std::initializer_list<TreeValue> values)
    {
        auto next = values.begin();
        if (next == values.end() || !next->present)
        {
            return;
        }
        std::queue<TreeNode *> pending;
        pending.push(add((next++)->value));
        while (!pending.empty() && next != values.end())
        {
            TreeNode *node = pending.front();
            pending.pop();
            if (next->present)
            {
                node->left = add(next->value);
                pending.push(node->left);
            }
            ++next;
            if (next != values.end())
            {
                if (next->present)
                {
                    node->right = add(next->value);
                    pending.push(node->right);
                }
                ++next;
            }
        }
    }

    TreeNode *root() const { return nodes.empty() ? nullptr : nodes.front().get(); }

    TreeNode *find(int value) const
    {
        for (const auto &node : nodes)
        {
            if (node->val == value)
            {
                return node.get();
            }
        }
        return nullptr;
    }
};

inline void printTree(const TreeNode *root)
{
    std::vector<const TreeNode *> nodes = {root};
    for (std::size_t i = 0; i < nodes.size(); ++i)
    {
        if (nodes[i] != nullptr)
        {
            nodes.push_back(nodes[i]->left);
            nodes.push_back(nodes[i]->right);
        }
    }
    while (!nodes.empty() && nodes.back() == nullptr)
    {
        nodes.pop_back();
    }
    std::cout << '[';
    for (std::size_t i = 0; i < nodes.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << ',';
        }
        if (nodes[i] != nullptr)
        {
            std::cout << nodes[i]->val;
        }
        else
        {
            std::cout << "null";
        }
    }
    std::cout << "]\n";
}

inline void deleteTree(TreeNode *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
}

#endif
