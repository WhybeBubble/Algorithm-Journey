/**
 * @file 141_Linked_List_Cycle.cpp
 * @brief 141. 环形链表
 * @link https://leetcode.cn/problems/linked-list-cycle/
 * 
 * @algorithm 快慢指针 (Floyd's Cycle-Finding Algorithm / Tortoise and Hare)
 * 
 * @time_complexity O(N) 
 *      - 如果没环，快指针走 N 步到头。
 *      - 如果有环，快慢指针进入环后，快指针相对于慢指针的速度是 1 步/次。
 *        它们之间的距离每走一次缩小 1，最终一定会在一圈内相遇。
 * 
 * @space_complexity O(1) 
 *      - 仅使用了两个指针变量，完全不依赖哈希表，极致节省空间。
 * 
 * @note 核心思路 (套圈法)：
 * 1. 想象在操场跑步。如果跑道是直的，快的永远追不上慢的。
 * 2. 如果跑道是圆环，快的跑得足够久，一定能从背后“套圈”慢的。
 * 3. 我们让 slow 每次走 1 步，fast 每次走 2 步。
 * 4. 如果链表有环，fast 最终会进入环并不断循环，直到它从后面撞上 slow。
 * 5. 如果 fast 走到了 nullptr，说明链表有尽头，绝对无环。
 */


struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x),next(nullptr){}

};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 0. 边界防御：空链表或只有一个节点的链表（且没指向自己）肯定无环
        if (!head || !head->next ) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;

        // 1. 开始套圈逻辑
        // 【注意】：这里用刚才学到的短路求值顺序！先看 fast，再看 fast->next
        while (fast && fast->next) {
            slow = slow->next;       // 慢指针走 1 步
            fast = fast->next->next; // 快指针走 2 步

            // 2. 判定：如果地址相等，说明 fast 追上了 slow
            // 注意：比较的是指针本身（内存地址），而不是 val 值！
            if (slow == fast) {
                return true;
            }
        }

        // 如果跳出了循环，说明快指针撞到了 nullptr，没环
        return false;
    }
};