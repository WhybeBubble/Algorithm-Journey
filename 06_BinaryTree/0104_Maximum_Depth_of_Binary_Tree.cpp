/**
 * @algorithm 递归分治 (Bottom-up DFS)
 * @time_complexity O(N) - 遍历所有节点
 * @space_complexity O(H) - 系统栈深度
 */

#include <algorithm>
using namespace std;

// 题目提供的标准定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 1. 基准情况：如果是空树，深度为 0
        if (root == nullptr) return 0;

        // 2. 分治：递归计算左右子树深度
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // 3. 汇总：取左右最高值 + 1
        return max(leftHeight, rightHeight) + 1;
    }
};