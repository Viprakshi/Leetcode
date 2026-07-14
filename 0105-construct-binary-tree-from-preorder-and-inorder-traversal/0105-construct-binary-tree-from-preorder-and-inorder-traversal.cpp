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
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int prestart,int preend, int instart, int inend, map<int,int>& mpp){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int pos= mpp[root->val];
        int num_left=pos-instart;
        root->left=build(preorder,inorder,prestart+1,prestart+num_left,instart,pos-1,mpp);
        root->right=build(preorder,inorder,prestart+1+num_left,preend,pos+1,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mpp);
    }
};