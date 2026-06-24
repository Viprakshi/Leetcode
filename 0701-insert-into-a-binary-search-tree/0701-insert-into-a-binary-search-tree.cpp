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
        TreeNode* nn=new TreeNode(val);
        TreeNode* ans=root;
        TreeNode* parent=NULL;
        while(root){
            parent=root;
            if(val<parent->val) root=root->left;
            else root=root->right;
        }
        if(parent==NULL) return nn;
        if(val<parent->val) parent->left=nn;
        else parent->right=nn;
        return ans;

    }
};