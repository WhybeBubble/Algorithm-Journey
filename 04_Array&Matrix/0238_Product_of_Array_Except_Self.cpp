/**
 * @file 238_Product_of_Array_Except_Self.cpp
 * @brief 238. 除自身以外数组的乘积
 * @link https://leetcode.cn/problems/product-of-array-except-self/
 * 
 * @algorithm 前缀积与后缀积 (Prefix and Suffix Products)
 * 
 * @time_complexity O(N) 
 *      - 两次遍历数组，第一次从左到右，第二次从右到左。
 * 
 * @space_complexity O(1) 
 *      - 题目说明输出数组不被视为额外空间。
 *      - 我们利用输出数组来直接存储左前缀积，然后用一个整数动态维护右前缀积，
 *        完美达到了 O(1) 的辅助空间要求。
 * 
 * @note 核心思路：
 * 1. 对于数组中的任意一个数字 nums[i]，它“除自身以外的乘积”可以拆分为两部分：
 *    - 它**左边**所有数字的乘积 (Left Product)
 *    - 它**右边**所有数字的乘积 (Right Product)
 *    - 最终结果 = Left Product * Right Product
 * 
 * 2. 空间 O(1) 绝妙解法 (两次遍历法)：
 *    - 第一遍 (从左到右)：我们将 result 数组当作 "左前缀积" 数组。
 *      result[i] 存储 nums[i] 左边所有元素的乘积。
 *      (注意：result[0] 左边没有元素，初始化为 1)
 *    - 第二遍 (从右到左)：我们需要 "右后缀积"。
 *      为了省空间，我们不建新数组，而是用一个变量 `R` 动态记录右边的乘积。
 *      每次让 result[i] 乘上当前的 `R`，然后把 nums[i] 乘进 `R` 留给下一个人用。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution{

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n,1);

        for(int i = 1; i < n; i++)
        {
            result[i] = result[i-1] * nums[i - 1];
        }

        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
         
        result[i] = result[i] * R;
    
    
        R *= nums[i];
        }
        return result;
    }
};