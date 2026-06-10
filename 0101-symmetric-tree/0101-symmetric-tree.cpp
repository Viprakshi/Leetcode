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
    bool check(TreeNode* x,TreeNode* y){
        if(x==NULL || y==NULL) return x==y;
        return check(x->right, y->left) && check(x->left, y->right) && (x->val==y->val); 

    }
   bool isSymmetric(TreeNode* root) {
        TreeNode *right=root->right;
        TreeNode *left=root->left;
        return check(left,right);        
    }
};