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
    void count_nodes(TreeNode* root, int& count){
        if(root==NULL) return;
        if(root->right) count_nodes(root->right, count);
        if(root->left) count_nodes(root->left, count);
        count++;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0; 
        if(root->left==NULL && root->right==NULL) return 1; 
        int count=0;       
        count_nodes(root,count);
        return count;
    }
};