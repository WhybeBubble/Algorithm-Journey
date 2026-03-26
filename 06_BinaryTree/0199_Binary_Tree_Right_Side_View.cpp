/**
 * @file 0199_Binary_Tree_Right_Side_View.cpp
 * @brief 199. 二叉树的右视图
 * @link https://leetcode.cn/problems/binary-tree-right-side-view/
 * 
 * @algorithm 广度优先搜索 (BFS / Level Order Traversal)
 * @time_complexity O(N) - 每个节点入队出队一次
 * @space_complexity O(W) - W 为二叉树的最大宽度（队列中最多存放一层的节点）
 * 
 * @note 核心思路：
 * 1. 物理直觉：所谓“右视图”，其实就是每一层【最右边】的那个节点。
 * 2. 战术选择：使用层序遍历（BFS）最为直观。
 * 3. 关键动作：
 *    - 遍历每一层时，记录该层的节点数量 `size`。
 *    - 当遍历到该层的最后一个节点（即 `i == size - 1`）时，将其值存入结果数组。
 */

#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        // 1. 准备队列进行层序遍历
        // 侯捷提示：queue 默认底层是 deque，支持高效的头尾操作
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            // 2. 锁定当前层的节点数，防止处理过程中新入队的子节点干扰计数
            int size = que.size();
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();

                // 3. 【核心逻辑】：如果是当前层的最后一个节点，它就是右视图可见的
                if (i == size - 1) {
                    result.push_back(node->val);
                }

                // 4. 将下一层节点入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return result;
    }
};