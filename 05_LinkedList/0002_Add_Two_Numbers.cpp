/**
 * @file 002_Add_Two_Numbers.cpp
 * @brief 2. 两数相加
 * @link https://leetcode.cn/problems/add-two-numbers/
 * 
 * @algorithm 模拟加法竖式 + 虚拟头节点
 * 
 * @time_complexity O(max(M, N)) - M, N 为两条链表的长度。
 * @space_complexity O(1) - 这里的 1 指的是辅助空间。
 *      (注意：返回的结果链表占用了 O(max(M, N)) 空间，但不计入算法本身的辅助复杂度)
 */

 struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x),next(nullptr){}

};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. 创建虚拟头节点 (栈分配，性能高且安全)
        ListNode dummy(0);
        ListNode* curr = &dummy;

        int carry = 0; // 进位器

        // 2. 核心循环：只要 l1 有数，或 l2 有数，或者还有残留的进位
        // 【注意】：把 carry 放在判断条件里，优雅处理最高位进位 (如 5+5=10)
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            // 【Cherno 视角：利用三目运算符提取数值，防御空指针】
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // 3. 计算当前位的总和
            int sum = val1 + val2 + carry;
            
            // 更新进位 (如 13 / 10 = 1)
            carry = sum / 10;
            // 获取留在本位的值 (如 13 % 10 = 3)
            int newNodeVal = sum % 10;

            // 4. 创建新节点并挂载
            // 【侯捷提示】：这里涉及堆内存分配，工业界会考虑内存池优化
            curr->next = new ListNode(newNodeVal);  //必须向系统申请一块新的空地，造一个全新的 ListNode 出来存放这个计算结果
            curr = curr->next;

            // 5. 链表向后平移
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // 6. 返回真正结果的头
        return dummy.next;
    }
};