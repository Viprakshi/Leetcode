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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend, map<int,int>& mpp){
        if(instart>inend || poststart<postend) return NULL;
        TreeNode* root=new TreeNode(postorder[poststart]);
        int pos=mpp[root->val];
        int num_left=pos-instart;
       root->left = build(inorder, postorder,
                   instart, pos - 1,
                   postend + num_left - 1, postend,
                   mpp);

root->right = build(inorder, postorder,
                    pos + 1, inend,
                    poststart - 1, postend + num_left,
                    mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder,postorder,0,inorder.size()-1, postorder.size()-1, 0,mpp);
    }
};