/**
 * @file 560_Subarray_Sum_Equals_K.cpp
 * @brief 560. 和为 K 的子数组
 * @link https://leetcode.cn/problems/subarray-sum-equals-k/
 * 
 * @algorithm 前缀和 (Prefix Sum) + 哈希表 (Hash Map)
 * 
 * @time_complexity O(N) 
 *      - 只需要遍历一次数组，每次在哈希表中查询和插入的时间复杂度均为 O(1)。
 * 
 * @space_complexity O(N)
 *      - 需要一个哈希表来存储所有出现过的前缀和及其出现的次数。
 * 
 * @note 核心思路：
 * 1. 题目存在负数，绝对不能用滑动窗口。
 * 2. 子数组 [i, j] 的和 = prefixSum[j] - prefixSum[i-1]。
 * 3. 题目要求：prefixSum[j] - prefixSum[i-1] == k。
 * 4. 移项得到：prefixSum[i-1] == prefixSum[j] - k。
 * 5. 我们在遍历数组计算当前 prefixSum 时，只需要去哈希表里查一查：
 *    "在我之前，有没有出现过值为 (prefixSum - k) 的前缀和？出现了几次？"
 * 6. 出现的次数，就是以当前位置为结尾、和为 k 的子数组的个数。
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Key   : 某一个前缀和的值
        // Value : 这个前缀和出现的次数
        unordered_map<int, int> prefixMap;
        
        // 【关键初始化】: 应对子数组从下标 0 开始的情况！
        // 假设前缀和刚好等于 k，那么 prefixSum - k = 0。
        // 我们需要哈希表里预先存在一个 "前缀和为 0 出现 1 次" 的记录。
        prefixMap[0] = 1;
        
        int cnt = 0;      
        int prefixSum = 0; 
    
        for (int i = 0; i < nums.size(); i++) {
            
            // 1. 累加当前数字，得到当前位置的 prefixSum
            prefixSum += nums[i];
            
            // 2. 核心公式查询：前面有没有出现过 (prefixSum - k)？
            int target = prefixSum - k;
            if (prefixMap.count(target)) {

                cnt += prefixMap[target];
            }
            
            // 3. 将当前算出的 prefixSum 存入哈希表，供后面的元素查询
            // 如果之前存过，次数 +1；如果没存过，C++ 会自动创建并置为 1
            prefixMap[prefixSum]++;
        }
        
        return cnt;
    }
};

