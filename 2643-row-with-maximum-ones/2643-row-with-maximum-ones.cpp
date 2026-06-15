class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int max=0, ind=0;
        for(int i=0;i<mat.size();i++){
            int left=0, right=mat[0].size()-1;
            while(left<=right){
                int mid=(left+right)/2;
                sort(mat[i].begin(),mat[i].end());
                if(mat[i][mid]==1){
                    int freq=mat[0].size()-mid;
                    if(freq>max){
                        max=freq;
                        ind=i;
                    }
                    right=mid-1;
                }
                else left=mid+1;
            }
        }
        return {ind,max};
    }
};