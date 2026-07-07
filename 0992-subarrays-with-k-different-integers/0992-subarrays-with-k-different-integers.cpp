class Solution {
public:
    int at(vector<int>& arr, int k){
        unordered_map<int,int> mpp;
        int ans=0, i=0, j=0;
        while(j<arr.size()){
            mpp[arr[j]]++;
            while(mpp.size()>k){
                mpp[arr[i]]--;
                if(mpp[arr[i]]==0) mpp.erase(arr[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return at(a,k)-at(a,k-1);
    }
};