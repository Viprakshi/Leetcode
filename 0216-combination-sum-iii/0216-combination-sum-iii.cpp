class Solution {
public:
    void generate(int target,vector<vector<int>>& ans,vector<int>& temp,int k,int n, int x,int sum){
        if(sum==target && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(x>9) return;
        generate(target,ans,temp,k,n,x+1,sum);
        temp.push_back(x);
         generate(target,ans,temp,k,n,x+1,sum+x);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(n,ans,temp,k,n,1,0);
        return ans;
    }
};