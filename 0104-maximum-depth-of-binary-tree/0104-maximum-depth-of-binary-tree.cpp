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
    int max_depth(TreeNode* root, int d){
        if(root==nullptr) return 0;
        int left=max_depth(root->left, d+1);
        int right=max_depth(root->right, d+1);
        return 1+ max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return max_depth(root,1);
    }
};