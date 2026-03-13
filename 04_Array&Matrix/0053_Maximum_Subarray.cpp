/**
 * @file 053_Maximum_Subarray.cpp
 * @brief 53. 最大子数组和
 * @link <https://leetcode.cn/problems/maximum-subarray/>
 *
 * @algorithm 动态规划 (DP) / 贪心 (Kadane's Algorithm)
 *
 * @time_complexity O(N)
 *      - 只需要遍历一次数组，每个元素访问一次。
 *
 * @space_complexity O(1)
 *      - 只使用了两个整型变量（当前和、最大和），没有开辟额外数组。
 *
 * @note 核心思路 (Kadane 算法的本质)：
 * 1. 我们遍历数组，不断把当前的数字累加到 `currentSum` 中。
 * 2. 【灵魂拷问】：如果 `currentSum` 加着加着，变成了一个**负数**，这意味着什么？
 *    - 意味着：无论后面遇到多么巨大的正数，如果你带上当前的 `currentSum`（它是负的），
 *      它只会拖累后面的正数，让总和变小！
 *    - 比如：你前面攒了 -5 的局势，后面遇到了 100。你带上前面的局势，总和是 95；
 *      你如果果断抛弃前面的烂摊子，从 100 重新开始算，总和就是 100！
 * 3. 【贪心策略】：
 *    - 如果 `currentSum < 0`，立刻抛弃它，让 `currentSum = 0`，从下一个数字重新开始累加。
 *    - 每次累加后，都更新一下全局记录的最大和 `maxSum`。
 *
 * @note DP 视角的理解 (状态转移方程)：
 * dp[i] 代表以 nums[i] 为结尾的连续子数组的最大和。
 * dp[i] = max(nums[i], dp[i-1] + nums[i])
 * 翻译过来就是：我是自己单干（抛弃前面的），还是和前面的凑一块（带上前面的）？取决于前面的和是不是正数。
 * 由于 dp[i] 只依赖于 dp[i-1]，所以可以压缩为一个变量 `currentSum`。
 */

#include <vector>
using namespace std;

class Solution{

public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.empty()) return 0;
      
        int maxSum = nums[0];

        int currentSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            currentSum += nums[i];
            maxSum = max(maxSum,currentSum);

            if(currentSum < 0)
            {
                currentSum = 0;
            }
        }  
        return maxSum;      
    }
 };

 /*
    更加优雅的写法！
 */

class Solution{

public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int maxSum = nums[0];
        int preSum = 0;
        for(int x : nums) //对于int,char,float直接用传值拷贝更快！
        {
            preSum = max(preSum + x,x);
            maxSum = max(maxSum,preSum);
        }
        return maxSum;      
    }
};

