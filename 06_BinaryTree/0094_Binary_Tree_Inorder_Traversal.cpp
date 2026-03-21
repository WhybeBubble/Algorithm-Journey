/**
 * @file 094_Binary_Tree_Inorder_Traversal.cpp
 * @brief 94. 二叉树的中序遍历
 * 
 * @algorithm 递归 (Recursion)
 * @time_complexity O(N) - 每个节点访问一次
 * @space_complexity O(H) - H 为树的高度。最坏 O(N)，最好 O(log N)
 */

#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

private:
    // 【侯捷提示】：使用引用传递 vector，避免每一层递归都发生昂贵的内存拷贝
    void traversal(TreeNode* curr, vector<int>& res) {
        // 1. 终止条件（刹车）：当前节点为空，说明到底了，回溯
        if (curr == nullptr) return;

        // 2. 递归逻辑：左 -> 根 -> 右
        traversal(curr->left, res);  // 左
        res.push_back(curr->val);    // 根（处理当前节点）
        traversal(curr->right, res); // 右
    }
};

/**
 * @algorithm 迭代法 (Iteration using std::stack)
 * @note 核心逻辑：
 * 1. 模拟系统栈：先一路向左钻到底，沿途所有节点入栈。
 * 2. 触底回溯：从栈中弹出节点（相当于从左孩子回到了根），记录值。
 * 3. 转向：去处理右子树。
 */

#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // 只要当前节点不为空，或者栈里还有存货，就不能停
        while (curr != nullptr || !st.empty()) {
            // 步骤 1: 一路向左钻到底
            while (curr != nullptr) {
                st.push(curr);     // 压栈（保存现场）
                curr = curr->left; // 往左走
            }

            // 步骤 2: 此时 curr 为空，说明左边到头了，该弹栈了
            curr = st.top();
            st.pop();
            result.push_back(curr->val); // 处理“根”

            // 步骤 3: 转向右边
            curr = curr->right;
        }
        return result;
    }
};