/**
 * @file 0207_Course_Schedule.cpp
 * @brief 207. 课程表 (拓扑排序)
 * @link https://leetcode.cn/problems/course-schedule/
 * 
 * @algorithm Kahn 算法 (基于 BFS 的拓扑排序)
 * @time_complexity O(V + E) - V 为课程数，E 为先修关系数。每个点和边都只访问一次。
 * @space_complexity O(V + E) - 需要邻接表存储图结构及入度数组。
 * 
 * @note 核心思路：
 * 1. 物理本质：判断一个有向图是否存在环。如果存在环，则无法完成拓扑排序。
 * 2. 核心数据结构：
 *    - 入度数组 (indegree)：记录每个节点被多少个前驱节点指向。
 *    - 邻接表 (adj)：记录每个节点指向哪些后继节点。
 * 3. 算法流程：
 *    - 将所有入度为 0 的节点（即没有先修要求的课）入队。
 *    - 当队列非空时，弹出一个节点，将其对应的所有后继节点的入度减 1。
 *    - 如果某个后继节点的入度降为 0，说明其依赖已全部解除，将其入队。
 * 4. 判定标准：
 *    - 如果最终处理过的节点数等于总课程数，说明无环，返回 true。
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 初始化邻接表和入度数组
        // 侯捷提示：vector<vector<int>> 是处理稀疏图的通用选择，兼顾了灵活性与随机访问
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // 2. 建立图结构 (预处理)
        for (const auto& cp : prerequisites) {
            int target = cp[0];
            int pre = cp[1];
            adj[pre].push_back(target); // pre -> target
            indegree[target]++;         // 目标节点的依赖数 +1
        }

        // 3. 寻找所有初始入度为 0 的节点
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        // 4. 开始拓扑调度
        int count = 0; // 记录已修完的课程数
        while (!que.empty()) {
            int pre = que.front();
            que.pop();
            count++;

            // 遍历当前课程指向的所有后续课程
            for (int target : adj[pre]) {
                indegree[target]--; // 依赖减 1
                // 如果入度变为 0，说明依赖全部解除，可以排课
                if (indegree[target] == 0) {
                    que.push(target);
                }
            }
        }

        // 5. 最终判定：是否所有课程都能修完
        return count == numCourses;
    }
};