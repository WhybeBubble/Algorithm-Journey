/**
 * @file 048_Rotate_Image.cpp
 * @brief 48. 旋转图像
 * @link https://leetcode.cn/problems/rotate-image/
 * 
 * @algorithm 矩阵转置 + 左右翻转 (Transpose + Reflect)
 * 
 * @time_complexity O(N^2)
 *      - 转置操作遍历半个矩阵：O(N^2 / 2)
 *      - 左右翻转操作遍历半个矩阵：O(N^2 / 2)
 *      - 总复杂度严格为 O(N^2)，N 是矩阵的边长。
 * 
 * @space_complexity O(1)
 *      - 原地修改，只使用了常数个辅助变量。
 * 
 * @note 核心思路 (降维打击)：
 * 顺时针旋转 90 度，在数学上等价于两个简单的几何变换组合：
 * 1. 【转置 (Transpose)】：沿着主对角线（左上到右下）翻转。
 *    (row, col) 变成 (col, row)
 * 2. 【左右翻转 (Reflect)】：每一行内部进行逆序。
 *    (row, col) 变成 (row, n-1-col)
 * 
 * 这种方法比直接去算四个点的坐标交换（四连环交换）要直观得多，不容易写出 Bug。
 */

#include <vector>
#include <algorithm> // 为了使用 std::swap 和 std::reverse

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1. 【第一步：转置】
        // 遍历矩阵的上三角部分，与下三角部分交换
        for (int i = 0; i < n; ++i) {
            // 注意：j 从 i 开始，只处理对角线一侧，否则换过去又换回来了
            for (int j = i + 1; j < n; ++j) {   //微操，越过不必要的对角线。
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. 【第二步：左右翻转】
        // 遍历每一行，直接调用 STL 的 reverse 函数
        for (int i = 0; i < n; ++i) {
            // matrix[i] 本身就是一个 vector<int>，直接翻转它
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

