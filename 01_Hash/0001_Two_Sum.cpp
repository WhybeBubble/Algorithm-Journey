/**
 * @file 001_Two_Sum.cpp
 * @brief 1. 两数之和
 * @link https://leetcode.cn/problems/two-sum/
 * 
 * @algorithm Hash Map
 * @time_complexity O(N)  - 只需遍历一次数组
 * @space_complexity O(N) - 需要一个哈希表存 N 个元素
 * 
 * @note 核心思路：
 * 不要用双层 for 循环去找。
 * 准备一个 unordered_map<数值, 下标>。
 * 遍历数组，对于当前数字 x，去 map 里找有没有 (target - x)。
 * 如果有，直接返回下标；如果没有，把自己存进 map 里，继续往后找。
 */

#include <vector>
#include <unordered_map>

using namespace std; // 刷题时为了手速，这里可以写 using namespace std

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // 如果在 map 中找到了互补的数
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            // 没找到，就把自己存进去
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};
