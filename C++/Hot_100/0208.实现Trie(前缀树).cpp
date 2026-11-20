/*
实现前缀树，支持插入小写单词、查找完整单词和检查一个前缀是否存在。

示例
输入：插入 apple，查询 apple、app 和前缀 app，随后插入 app 并查询 app。
输出：[true,false,true,true]

题目链接：https://leetcode.cn/problems/implement-trie-prefix-tree/
*/
#include "hot100_example.h"
using namespace std;

// 每条边代表一个字符，节点需要标记是否有单词在此结束。操作耗时 O(L)，L 为传入字符串长度。
class Trie
{
private:
    struct Node
    {
        int child[26] = {};
        bool terminal = false;
    };
    vector<Node> nodes;

    int follow(const string &text) const
    {
        int node = 0;
        for (char ch : text)
        {
            node = nodes[node].child[ch - 'a'];
            if (node == 0)
            {
                return -1;
            }
        }
        return node;
    }

public:
    Trie() : nodes(1) {}

    void insert(string word)
    {
        int node = 0;
        for (char ch : word)
        {
            int letter = ch - 'a';
            if (nodes[node].child[letter] == 0)
            {
                int next = nodes.size();
                nodes.emplace_back();
                nodes[node].child[letter] = next;
            }
            node = nodes[node].child[letter];
        }
        nodes[node].terminal = true;
    }

    bool search(string word)
    {
        int node = follow(word);
        return node >= 0 && nodes[node].terminal;
    }

    bool startsWith(string prefix)
    {
        return follow(prefix) >= 0;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    vector<bool> result = {trie.search("apple"), trie.search("app"), trie.startsWith("app")};
    trie.insert("app");
    result.push_back(trie.search("app"));
    hot100::print(result);
    return 0;
}
