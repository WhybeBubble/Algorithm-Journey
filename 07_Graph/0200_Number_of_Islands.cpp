/**
 * @file 0200_Number_of_Islands.cpp
 * @brief 200. 岛屿数量
 * @link https://leetcode.cn/problems/number-of-islands/
 * 
 * @algorithm DFS (深度优先搜索) + 沉岛策略 (Sinking Strategy)
 * @time_complexity O(M * N) - 每个格子最多被访问 5 次（1次外部遍历，4次四周探索）
 * @space_complexity O(M * N) - 最坏情况下递归深度达到全图，消耗系统栈空间
 * 
 * @note 核心思路：
 * 1. 遍历整个二维网格。
 * 2. 遇到 '1' (陆地)：
 *    - 岛屿计数器 + 1。
 *    - 启动 DFS，将与该陆地相连的所有陆地全部标记为 '0'（沉岛）。
 * 3. 沉岛的目的：防止在后续遍历中重复计数，实现“原地去重”。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 发现一块新陆地，这代表一个新的岛屿
                if (grid[i][j] == '1') {
                    islandCount++;
                    // 利用 DFS 把这个岛屿所有的陆地“沉掉”
                    dfs(grid, i, j);
                }
            }
        }
        return islandCount;
    }

private:
    /**
     * @brief 沉岛函数
     * Cherno 视角：利用原地修改规避了额外的 visited 数组，空间优化到极致。
     */
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. 边界检查与终止条件
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }

        // 2. 将当前陆地置为水 (Sinking)
        grid[r][c] = '0';

        // 3. 向四个方向递归扩散
        // 汇编层面：这是四次函数调用，栈帧层层叠加
        dfs(grid, r - 1, c); // 上
        dfs(grid, r + 1, c); // 下
        dfs(grid, r, c - 1); // 左
        dfs(grid, r, c + 1); // 右
    }
};
