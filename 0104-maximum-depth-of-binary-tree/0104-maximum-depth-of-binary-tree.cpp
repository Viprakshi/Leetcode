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
    int cal(TreeNode* root, int d){
        if(root==NULL) return d-1;
        int right=cal(root->right,d+1);
        int left=cal(root->left,d+1);
        return max(right,left);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return cal(root,1);
    }
};