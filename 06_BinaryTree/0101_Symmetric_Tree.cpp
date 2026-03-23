/**
 * @file 101_Symmetric_Tree.cpp
 * @algorithm 递归 DFS (镜像比较)
 * @time_complexity O(N)
 * @space_complexity O(H) - 系统栈深度
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         return check(root->left, root->right);
//     }

// private:
//     // 侯捷视角：递归函数的设计必须保证逻辑完备性
//     bool check(TreeNode* p, TreeNode* q) {
//         // 1. 终止条件：双空则镜像
//         if (!p && !q) return true;
//         // 2. 终止条件：一空一非空，或值不等，则非镜像
//         if (!p || !q || p->val != q->val) return false;
        
//         // 3. 递归：外侧比外侧，内侧比内侧
//         return check(p->left, q->right) && check(p->right, q->left);
//     }
// };

#include <queue>

class Solution{

public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty())
        {
            TreeNode* u = q.front();
            q.pop();
            TreeNode* v = q.back();
            q.pop();
            
            if(!u && !v) continue;
            if(!u || !v || u->val != v->val) return false;

            q.push(u->left);q.push(v->right);
            q.push(u->right);q.push(v->left);
        }
        return true; 
    }
};