#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public: 
    void rotateArray(vector<int>& nums,int k)
    {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         auto reverse = [&](int i, int j) {
//             while (i < j) {
//                 swap(nums[i++], nums[j--]);
//             }
//         };

//         int n = nums.size();
//         k %= n; // 轮转 k 次等于轮转 k % n 次
//         reverse(0, n - 1);
//         reverse(0, k - 1);
//         reverse(k, n - 1);
//     }
// };
