/**
 * @file 015_3Sum.cpp
 * @brief 15. 三数之和
 * @link https://leetcode.cn/problems/3sum/
 * 
 * @algorithm 排序 (Sorting) + 双指针 (Two Pointers)
 * 
 * @time_complexity O(N^2) 
 *      - 数组排序的时间复杂度为 O(N log N)。
 *      - 外层遍历数组 O(N)，内层使用双指针寻找剩余两个数 O(N)，嵌套起来是 O(N^2)。
 *      - 总时间复杂度为 O(N log N) + O(N^2) = O(N^2)。
 * 
 * @space_complexity O(log N) ~ O(N)
 *      - 不考虑存储结果的二维数组。
 *      - C++ 中 std::sort 的底层实现（IntroSort）需要 O(log N) 的递归栈空间。
 * 
 * @note 核心思路与去重逻辑：
 * 1. 为什么一定要先排序？
 *    - 排序后，相同的元素会挨在一起，这是我们能实现 O(1) 空间去重的唯一基石。
 *    - 排序后才能使用左右双指针向中间逼近。
 * 2. 降维打击：
 *    - 找 a + b + c = 0。我们可以固定 a (即 nums[i])，然后用双指针在 i 之后找 b + c = -a。
 * 3. 【死亡陷阱：三次去重】：
 *    - 去重 a：如果 nums[i] == nums[i-1]，说明这个数字作为老大已经找过一遍了，直接跳过。
 *    - 去重 b 和 c：当找到一组解后，left 和 right 必须跳过所有相同的值，否则会出现重复的三元组。
 * 4. 【极致剪枝优化】：
 *    - 如果固定的 a (nums[i]) 已经大于 0，因为数组排过序，后面的 b 和 c 肯定也大于 0，
 *      三个正数相加绝对不可能等于 0，直接 break 结束整个程序。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // 0. 防御性编程：少于 3 个数绝对凑不出三元组
        if (n < 3) return result;

        // 1. 先排序 (时间 O(N log N))
        sort(nums.begin(), nums.end());

        // 2. 固定第一个数 a (即 nums[i])
        for (int i = 0; i < n - 2; i++) {
            
            // 【剪枝优化】如果最小的数已经大于 0，后面绝不可能凑成 0，直接结束！
            if (nums[i] > 0) {
                break;
            }

            // 【去重 a】注意：必须是 nums[i] == nums[i-1] 而不是 nums[i] == nums[i+1]
            // 如果和前一个数一样，说明这个数作为 a 已经搜索过了，跳过以防止重复结果
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 3. 降维成双指针问题：在 i 之后的区间寻找 b 和 c
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    // 和太小，说明左边的数小了，left 右移
                    left++;
                } 
                else if (sum > 0) {
                    // 和太大，说明右边的数大了，right 左移
                    right--;
                } 
                else {
                    // 找到了一组解！
                    // 【C++11 现代写法】直接用花括号构造 vector 并放入结果集，避免不必要的拷贝
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 【去重 b 和 c】找到解后，必须跳过所有重复的 left 和 right
                    // 注意：这里必须加上 left < right 的限制，防止越界
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // 去重完毕后，双指针双双向内收缩，继续寻找下一组解
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

