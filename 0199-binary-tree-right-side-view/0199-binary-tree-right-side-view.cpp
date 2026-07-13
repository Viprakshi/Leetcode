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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, TreeNode*> mpp;
        queue<pair<int,TreeNode*>> q;
        q.push({1, root});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int line=curr.first;
            TreeNode* temp=curr.second;
            if(mpp.find(line)==mpp.end()){
                mpp[line]=temp;
            }
            if(temp->right){
                q.push({line+1,temp->right});
            }
            
            if(temp->left){
                q.push({line+1,temp->left});
            }
        }
        
        for(auto entry: mpp){
            ans.push_back(entry.second->val);
        }
        return ans;
    }
};