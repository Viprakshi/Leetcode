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
    int ans = 0;
    tuple<bool, int, int, int> dfs(TreeNode* node) {
        if (!node)
            return {true, INT_MAX, INT_MIN, 0};

        auto [lValid, lMin, lMax, lSum] = dfs(node->left);
        auto [rValid, rMin, rMax, rSum] = dfs(node->right);
        if (lValid && rValid && lMax < node->val && node->val < rMin) {
            int sum = lSum + rSum + node->val;
            ans = max(ans, sum);
            int minVal = min(lMin, node->val); 
            int maxVal = max(rMax, node->val);
            return {true, minVal, maxVal, sum};
        }
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};