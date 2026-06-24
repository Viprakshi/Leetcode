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
    vector<int> merge(vector<int>& a1,vector<int>& a2){
        vector<int> ans(a1.size()+a2.size());
        int i=0, j=0;
        int x=0;
        while(i<a1.size() && j<a2.size()){
            if(a1[i]<=a2[j]){
                ans[x]=a1[i];
                x++;
                i++;
            }
            else{
                ans[x]=a2[j];
                x++;
                j++;
            }
        }
        while(i<a1.size()){
            ans[x]=a1[i];
            i++;
            x++;
        }
        while(j<a2.size()){
            ans[x]=a2[j];
            j++;
            x++;
        }
        return ans;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> array_1;
        vector<int> array_2;
        inorder(root1,array_1);
        inorder(root2,array_2);
        vector<int> array_3=merge(array_1,array_2);
        return array_3;
    }
};