/**
 * @file 160_Intersection_of_Two_Linked_Lists.cpp
 * @brief 160. 相交链表
 * @link https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * 
 * @algorithm 双指针 (走过你走过的路)
 * 
 * @time_complexity O(M + N) 
 *      - M, N 分别为两个链表的长度。两个指针各走完 M+N 步。
 * 
 * @space_complexity O(1) 
 *      - 只使用了两个临时指针，没有额外空间。
 * 
 * @note 核心思路 (浪漫邂逅法)：
 * 1. 什么是相交？不是值相等，而是【内存地址】相等。
 * 2. 难点：两个链表的长度可能不一样，直接对齐走是不行的。
 * 3. 破局点：
 *    - 指针 pA 走 A 链表，走完后去走 B 链表。
 *    - 指针 pB 走 B 链表，走完后去走 A 链表。
 * 4. 为什么这样能相遇？
 *    - pA 走过的路程：ListA + ListB
 *    - pB 走过的路程：ListB + ListA
 *    - 总路程相等！如果它们有公共部分，那么在第二轮遍历时，它们一定会【同时】到达相交点。
 * 5. 如果不相交呢？
 *    - 它们会同时到达双链表的末尾，即同时指向 nullptr，循环结束。
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 0. 边界防守
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        // 只要两个指针不相等，就继续走
        // 第一次相遇时，要么是相交点，要么都是 nullptr
        while (pA != pB) {
            
            // 如果走到头了，就跳到另一个链表的头；否则继续走下一步
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        // 返回 pA 或 pB 是一样的
        return pA;
    }
};