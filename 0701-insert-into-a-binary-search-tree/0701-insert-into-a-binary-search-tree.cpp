/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ans = root;
         TreeNode* new_node = new TreeNode(val);
            TreeNode* parent = nullptr;          // + track parent
            while (root) {                       // * just check root
                parent = root;                   // + save before moving
                if (root->val > val) root = root->left;
                else root = root->right;
            }
            if (!parent) return new_node;        // * empty tree edge case
            if (val < parent->val) parent->left = new_node;   // * attach to parent
            else parent->right = new_node;
            return ans;
    }
};