/**
 * @file 283_Move_Zeroes.cpp
 * @brief 283. 移动零
 * @link https://leetcode.cn/problems/move-zeroes/
 * 
 * @algorithm 双指针 (快慢指针 Fast & Slow Pointers)
 * 
 * @time_complexity O(N) 
 *      - 只需要遍历一次数组，每个元素最多被访问一次。
 * 
 * @space_complexity O(1)
 *      - 题目要求“原地”(in-place) 修改数组，只使用了两个额外的整型变量(指针)，
 *        不需要开辟新的数组空间。
 * 
 * @note 核心思路：
 * 1. 设定两个“指针”（其实就是数组下标）：slow 和 fast。
 * 2. slow 指向“下一个非零元素应该存放的位置”，初始为 0。
 * 3. fast 用于遍历整个数组，寻找非零元素。
 * 4. 遍历规则：
 *    - 如果 nums[fast] 是 0：不管它，fast 继续往前走。
 *    - 如果 nums[fast] 不是 0：说明找到了一个有效数字。
 *      我们把它和 nums[slow] 位置的数字**交换 (Swap)**。
 *      然后 slow++，准备迎接下一个非零元素。
 * 5. 妙处在于：因为 fast 总是走在 slow 前面（或重合），
 *    所以被交换到 fast 位置的元素，要么是 0，要么是它自己（如果此时还没遇到 0）。
 */

#include <vector>
#include <algorithm> // std::swap

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // 慢指针：记录下一个非零元素的填入位置

        // 快指针 fast 遍历整个数组
        for (int fast = 0; fast < nums.size(); fast++) {
            
            // 只要遇到非零元素，就把它交换到 slow 的位置
            if (nums[fast] != 0) {
                // 使用 C++ 标准库的交换函数
                swap(nums[slow], nums[fast]);
                
                // 填入成功后，慢指针向后移动一位
                slow++; 
            }
        }
    }
};

