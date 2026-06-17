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
    void generate(TreeNode* root, vector<string>& ans, string temp) {
        if (root == NULL) return;
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        temp += "->";
        if (root->left) generate(root->left, ans, temp);
        if (root->right) generate(root->right, ans, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root) generate(root, ans, "");
        return ans;
    }
};