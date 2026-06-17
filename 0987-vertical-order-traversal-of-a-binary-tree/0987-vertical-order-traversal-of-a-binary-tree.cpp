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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int vertical=q.front().second.first;
            int horizontal=q.front().second.second;
            q.pop();
            mpp[vertical][horizontal].insert(curr->val);
            if(curr->left)
            q.push({curr->left,{vertical-1, horizontal+1}});
            if(curr->right)
            q.push({curr->right,{vertical+1, horizontal+1}});
            

            
        }
        vector<vector<int>> ans;
         for (auto p : mpp) {
            vector<int> col;
            // Collect all nodes in order of levels
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Push the column into result
            ans.push_back(col);
        }

        return ans;
    }
};