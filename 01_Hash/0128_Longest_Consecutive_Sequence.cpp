/**
 * @file 128_Longest_Consecutive_Sequence.cpp
 * @brief 128. 最长连续序列
 * @link <https://leetcode.cn/problems/longest-consecutive-sequence/>
 *
 * @algorithm 哈希集合 (Hash Set)
 *
 * @time_complexity O(N)
 *      - 将数组转为 set 需要 O(N) 的时间。
 *      - 遍历 set 也是 O(N)。
 *      - 重点：虽然内部嵌套了一个 while 循环，但由于 if 条件的限制，
 *        每个元素最多被 while 循环访问一次。因此总时间复杂度严格等于 O(N)。
 *
 * @space_complexity O(N)
 *      - 需要一个 unordered_set 来存储所有的数字，以便实现 O(1) 的查询。
 *
 * @note 核心思路：
 * 1. 要求 O(N) 的时间复杂度，说明不能排序（O(N logN)）。我们只能用哈希表。
 * 2. 把所有数字扔进 unordered_set，自动去重且查询复杂度为 O(1)。
 * 3. 遍历 set 中的数字。对于当前数字 num：
 *    - 【关键逻辑】：如何判断它是不是一段连续序列的“开头”？
 *    - 如果 set 里面**存在** `num - 1`，说明当前数字只是某个序列的中间部分，我们跳过它，不作处理！
 *    - 如果 set 里面**不存在** `num - 1`，说明当前数字是一个连续序列的**起点**！
 * 4. 一旦确认是起点，我们就用一个 while 循环，不断去 set 里找 `num + 1`、`num + 2`...
 * 5. 记录当前的序列长度，并不断更新全局的最长长度。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution{

public:
    int longestConsecutive(vector<int>& nums)
    {
        // 0.边界条件检查
        if(nums.empty())
        {
            return 0;
        }

        // 1.创建set同时去重
        unordered_set<int> num_set(nums.begin(),nums.end());
        
        int longestStreak = 0;

        // 2.遍历set中的每一个元素
        for(const int& num : num_set)
        {   
            // 3.只有序列起点才开始往后计算序列长度
            if(!num_set.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;
            
                // 4.在哈希表中寻找下一个连续的数字
                while(num_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak,currentStreak);
            }   
        }
        return longestStreak;
    }
};


