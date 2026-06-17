class Solution {
public:
    string binary(int i){
        string b="";
        while(i!=0){
            if(i%2==0) b+='0';
            else if(i%2==1) b+='1';
            i=i/2;
        }
        return b;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<(1<<n);i++){
            string val=binary(i);
            for(int x=0;x<nums.size();x++){
                if(val[x]=='1') temp.push_back(nums[x]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};