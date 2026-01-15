class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
    }
};
