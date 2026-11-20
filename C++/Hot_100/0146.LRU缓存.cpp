/*
实现固定容量的 LRU 缓存。读取或写入已有键会将其标记为最近使用，超容量时淘汰最久未使用的键。

示例
输入：容量 2。依次执行 put(1,1)、put(2,2)、get(1)、put(3,3)、get(2)、put(4,4)、get(1)、get(3)、get(4)。
输出：[1,-1,-1,3,4]

题目链接：https://leetcode.cn/problems/lru-cache/
*/
#include "hot100_example.h"
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

// 双向链表头部是最近访问的条目，哈希表由键定位到链表位置。splice 将条目移到表头。
// get 和 put 的平均时间均为 O(1)，额外空间 O(capacity)。
class LRUCache
{
private:
    using Entry = pair<int, int>;
    int capacity;
    list<Entry> items;
    unordered_map<int, list<Entry>::iterator> positions;

public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto found = positions.find(key);
        if (found == positions.end())
        {
            return -1;
        }
        items.splice(items.begin(), items, found->second);
        return found->second->second;
    }

    void put(int key, int value)
    {
        auto found = positions.find(key);
        if (found != positions.end())
        {
            found->second->second = value;
            items.splice(items.begin(), items, found->second);
            return;
        }
        items.emplace_front(key, value);
        positions[key] = items.begin();
        if (int(items.size()) > capacity)
        {
            positions.erase(items.back().first);
            items.pop_back();
        }
    }
};

int main()
{
    LRUCache cache(2);
    vector<int> reads;
    cache.put(1, 1);
    cache.put(2, 2);
    reads.push_back(cache.get(1));
    cache.put(3, 3);
    reads.push_back(cache.get(2));
    cache.put(4, 4);
    reads.push_back(cache.get(1));
    reads.push_back(cache.get(3));
    reads.push_back(cache.get(4));
    hot100::print(reads);
    return 0;
}
