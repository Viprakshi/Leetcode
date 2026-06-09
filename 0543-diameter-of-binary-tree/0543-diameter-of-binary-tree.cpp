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
    int maxd(TreeNode* root, int& maxi){
        if(root==NULL) return 0;
        int left=maxd(root->left,maxi);
        int right=maxd(root->right,maxi);
        maxi=max(maxi, left+right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //max depth of right + max depth of left
        int maxi=0;
        maxd(root,maxi);
        return maxi;
    }
};