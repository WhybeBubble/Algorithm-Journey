/**
 * @file 0543_Diameter_of_Binary_Tree.cpp
 * @brief 543. 二叉树的直径
 * @link https://leetcode.cn/problems/diameter-of-binary-tree/
 * 
 * @algorithm 递归 DFS (后序遍历 / 分治法)
 * @time_complexity O(N) - 每个节点遍历一次
 * @space_complexity O(H) - H 为树的高度，取决于系统递归栈深度
 * 
 * @note 核心思路：
 * 1. 直径定义：任意两个节点路径长度的最大值。该路径可能经过根节点，也可能不经过。
 * 2. 物理转化：对于任意一个节点，经过它的最长路径长度 = 左子树高度 + 右子树高度。
 * 3. 递归设计：
 *    - 返回值：当前子树的高度（max(left, right) + 1）。
 *    - 副作用（更新全局变量）：在计算高度的过程中，顺便计算 `left + right`，并挑战全局最大直径。
 */

#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameter = 0; // 全局最大直径记录器

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);  //醉翁之意不在酒！秒
        return diameter;
    }

private:
    /**
     * @brief 计算高度并同步更新直径
     * 侯捷视角：利用后序遍历的回溯阶段进行信息汇总。
     */
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        // 1. 递去：深入左右子树
        int L = depth(node->left);
        int R = depth(node->right);

        // 2. 归来：计算经过当前节点的路径长度，并更新全局最大值
        // 物理意义：左侧最深路径 + 右侧最深路径
        diameter = max(diameter, L + R);

        // 3. 返回：当前节点作为父节点的一侧子树时，能提供的最大高度
        return max(L, R) + 1;
    }
};
