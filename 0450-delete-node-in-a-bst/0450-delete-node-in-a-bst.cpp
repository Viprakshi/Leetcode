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
    TreeNode* find(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* del(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return NULL;
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* lastleft=find(root->right);
        lastleft->left=root->left;
        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key) return del(root);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else root->left=deleteNode(root->left,key);
        return root;
    }
};