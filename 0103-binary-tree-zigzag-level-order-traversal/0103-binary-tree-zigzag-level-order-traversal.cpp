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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int x=1;
        while(!q.empty()){
            vector<int> level;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* x=q.front();
                q.pop();
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
                level.push_back(x->val);
            }
            if(x%2==0) reverse(level.begin(),level.end());
            ans.push_back(level);
            x++;
        }
        return ans;
    }
};