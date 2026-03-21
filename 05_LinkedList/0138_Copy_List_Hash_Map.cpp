/**
 * @file 138_Copy_List_Hash_Map.cpp
 * @brief 138. 随机链表的复制 (哈希表法)
 * 
 * @algorithm 哈希表映射 (Hash Map Mapping)
 * @time_complexity O(N) - 遍历链表两次。
 * @space_complexity O(N) - 需要一个哈希表来存储原节点到新节点的映射。
 * 
 * @note 工业级思考：
 * 这是典型的“空间换逻辑清晰度”的解法。虽然多了 O(N) 空间，
 * 但代码极难出错，且不破坏原链表的只读性。
 */

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <unordered_map>
using namespace std;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // 1. 创建映射表：<原节点指针, 新节点指针>
        // 侯捷提示：这里存的是 8 字节的内存地址作为 Key
        std::unordered_map<Node*, Node*> nodeMap;

        // --------------------------------------------------
        // 第一遍遍历：只创建“肉体”（节点本身），不连“灵魂”（指针）
        // --------------------------------------------------
        Node* curr = head;
        while (curr != nullptr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // --------------------------------------------------
        // 第二遍遍历：根据映射表，连接新链表的 next 和 random
        // --------------------------------------------------
        curr = head;
        while (curr != nullptr) {
            // 新节点的 next = 原节点下家的映射
            nodeMap[curr]->next = nodeMap[curr->next];
            
            // 新节点的 random = 原节点随机指向的映射
            nodeMap[curr]->random = nodeMap[curr->random];
            
            curr = curr->next;
        }

        // 返回原链表头节点所对应的新节点地址
        return nodeMap[head];
    }
};

