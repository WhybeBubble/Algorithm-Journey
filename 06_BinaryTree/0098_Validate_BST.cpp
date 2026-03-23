/**
 * @file 098_Validate_BST.cpp
 * @algorithm 中序遍历校验 (In-order Traversal)
 * @time_complexity O(N)
 * @space_complexity O(H)
 */

#include <iostream>
#include <vector>
#include <climits>

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 使用指针记录前驱节点，完美避开边界溢出问题
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        // 1. 左
        if (!isValidBST(root->left)) return false;

        // 2. 根 (中序处理)
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root; // 更新前驱指针

        // 3. 右
        return isValidBST(root->right);
    }
};

// 辅助函数：手动构建一个简单的树（用于测试）
//      5
//     / \
//    1   4
//       / \
//      3   6
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    return root;
}

// 侯捷提示：在 C++ 中，new 出来的树必须手动释放，否则会导致内存泄漏
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();

    if (sol.isValidBST(root)) {
        std::cout << "Result: This is a valid BST." << std::endl;
    } else {
        std::cout << "Result: This is NOT a valid BST." << std::endl;
    }

    // 清理内存
    deleteTree(root);
    return 0;
}