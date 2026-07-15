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

class NodeValue{
public:
    int min_val,max_val,sum;
    NodeValue(int min_val,int max_val,int sum){
        this->min_val=min_val;
        this->max_val=max_val;
        this->sum=sum;
    }
};

class Solution {
public:
    int ans=0;

    NodeValue cal(TreeNode* root){
        if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);

        auto left=cal(root->left);
        auto right=cal(root->right);

        if(left.max_val<root->val && root->val<right.min_val){
            int currsum=left.sum+right.sum+root->val;
            ans=max(ans,currsum);
            return NodeValue(min(root->val,left.min_val),max(root->val,right.max_val),currsum);
        }

        return NodeValue(INT_MIN,INT_MAX,0);
    }

    int maxSumBST(TreeNode* root) {
        cal(root);
        return ans;
    }
};