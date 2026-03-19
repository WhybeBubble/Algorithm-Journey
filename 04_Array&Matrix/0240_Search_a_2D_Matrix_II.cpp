/**
 * @file 240_Search_a_2D_Matrix_II.cpp
 * @brief 240. 搜索二维矩阵 II
 * @link https://leetcode.cn/problems/search-a-2d-matrix-ii/
 * 
 * @algorithm Z 字形查找 (Staircase Search) / 曼哈顿搜索
 * 
 * @time_complexity O(M + N)
 *      - M 是行数，N 是列数。
 *      - 每次比较后，要么行号增加，要么列号减少。
 *      - 最坏情况下，从右上角走到左下角，总共步数为 M + N。
 * 
 * @space_complexity O(1)
 *      - 仅使用了两个指针变量。
 * 
 * @note 核心思路 (寻找“决策点”)：
 * 矩阵的特点：每一行从左到右递增，每一列从上到下递增。
 * 
 * 1. 【破局点】：如果我们从左上角 (0,0) 开始找，如果 target 比当前值大，
 *    你可以向右走，也可以向下走，这时候你无法做出唯一的决策。
 * 
 * 2. 【上帝视角】：我们要找一个“矛盾点”，即一个方向变大、另一个方向变小的位置。
 *    那就是【右上角】 (0, n-1) 或 【左下角】 (m-1, 0)。
 * 
 * 3. 以【右上角】为起点：
 *    - 如果 current == target：找到了！
 *    - 如果 current > target：由于这一列下面的数都比当前值大，target 绝不可能在这一列。
 *      决策：列号减一 (col--)，往左移。
 *    - 如果 current < target：由于这一行左边的数都比当前值小，target 绝不可能在这一行。
 *      决策：行号加一 (row++)，往下移。
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 0. 边界防御
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        // 1. 设置初始搜索点：右上角 (Top-Right)
        int row = 0;
        int col = n - 1;

        // 2. 开始搜索，确保不走出矩阵边界
        while (row < m && col >= 0) {
            int current = matrix[row][col];

            if (current == target) {
                return true; // 命中目标
            } 
            else if (current > target) {
                // 当前值太大，排除掉当前这一列
                col--;
            } 
            else {
                // 当前值太小，排除掉当前这一行
                row++;
            }
        }

        // 3. 走出边界还没找到，说明不存在
        return false;
    }
};
