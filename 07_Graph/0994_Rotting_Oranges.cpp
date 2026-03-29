/**
 * @file 0994_Rotting_Oranges.cpp
 * @brief 994. 腐烂的橘子
 * @link https://leetcode.cn/problems/rotting-oranges/
 * 
 * @algorithm 多源 BFS (Multi-source Breadth-First Search)
 * @time_complexity O(M * N) - 每个格子最多入队出队一次
 * @space_complexity O(M * N) - 队列中最多存放全图的坐标
 * 
 * @note 核心思路：
 * 1. 为什么用 BFS 而不是 DFS？
 *    - 题目要求“最短时间”，即扩散的最短路径，这是 BFS 的天然优势。
 * 2. 多源点的物理意义：
 *    - 初始时，所有的腐烂橘子 (2) 都是传染源，它们是同时开始向外扩散的。
 * 3. 算法流程：
 *    - 首先遍历全图，将所有初始腐烂橘子的坐标存入队列，并统计新鲜橘子的总数。
 *    - 执行层序遍历，每过一分钟，将队列中当前的腐烂橘子向四周扩散一格。
 *    - 每感染一个新鲜橘子，新鲜总数减一。
 * 4. 结果判定：
 *    - 如果新鲜总数归零，返回经过的分钟数；否则返回 -1。
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>> que;

        // 1. 初始化：寻找所有传染源并统计目标总数
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    que.push({i, j}); // 初始腐烂橘子入队
                } else if (grid[i][j] == 1) {
                    freshCount++;     // 统计新鲜橘子数量
                }
            }
        }

        // 如果一开始就没有新鲜橘子，直接返回 0
        if (freshCount == 0) return 0;

        int minutes = 0;
        // 定义四个方向的偏移量：上、下、左、右
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. 开始多源扩散
        while (!que.empty() && freshCount > 0) {
            minutes++;
            int size = que.size(); // 当前分钟要扩散的源点个数

            for (int i = 0; i < size; ++i) {
                auto [r, c] = que.front();
                que.pop();

                for (auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    // 越界检查且目标必须是新鲜橘子
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // 感染该橘子
                        freshCount--;
                        que.push({nr, nc});
                    }
                }
            }
        }

        // 3. 最终检查：是否还有橘子没被感染
        return freshCount == 0 ? minutes : -1;
    }
};
